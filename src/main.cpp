#include "events.h"
#include "scaleform/scaleform.h"

void MessageHandler(SKSE::MessagingInterface::Message* a_msg) {
    switch (a_msg->type) {
        case SKSE::MessagingInterface::kDataLoaded:
            logger::info("Data loaded"sv);
            events::sink_event_handlers();
            scaleform::Register();
            break;
    }
}

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info) {
    try {
#ifndef NDEBUG
        auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
#else
        auto path = logger::log_directory();
        if (!path) {
            return false;
        }

        *path /= Version::PROJECT;
        *path += ".log"sv;
        auto sink = make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
#endif
        auto log = make_shared<spdlog::logger>("global log"s, move(sink));

#ifndef NDEBUG
        log->set_level(spdlog::level::trace);
#else
        log->set_level(spdlog::level::trace);
        log->flush_on(spdlog::level::trace);
#endif

        set_default_logger(move(log));
        spdlog::set_pattern("[%H:%M:%S.%f] %s(%#) [%^%l%$] %v"s);

        logger::info(FMT_STRING("{} v{}"), Version::PROJECT, Version::NAME);

        a_info->infoVersion = SKSE::PluginInfo::kVersion;
        a_info->name = Version::PROJECT.data();
        a_info->version = Version::ASINT;

        if (a_skse->IsEditor()) {
            logger::critical("Loaded in editor, marking as incompatible"sv);
            return false;
        }

        const auto ver = a_skse->RuntimeVersion();
        if (ver < SKSE::RUNTIME_1_5_39) {
            logger::critical(FMT_STRING("Unsupported runtime version {}"), ver.string());
            return false;
        }
    } catch (const std::exception& e) {
        logger::critical("failed, cause {}"sv, e.what());
        return false;
    }

    return true;
}


extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse) {
    try {
        logger::info("ShowStats loading"sv);
        try {
            settings::load();
        } catch (const std::exception& e) { logger::warn("failed to load setting {}"sv, e.what()); }

        Init(a_skse);

        switch (*settings::log_level) {
            case const_log_trace:
                spdlog::set_level(spdlog::level::trace);
                spdlog::flush_on(spdlog::level::trace);
                break;
            case const_log_debug:
                spdlog::set_level(spdlog::level::debug);
                spdlog::flush_on(spdlog::level::debug);
                break;
            case const_log_info:
                spdlog::set_level(spdlog::level::info);
                spdlog::flush_on(spdlog::level::info);
                break;
        }

        auto messaging = SKSE::GetMessagingInterface();
        if (!messaging->RegisterListener("SKSE", MessageHandler)) {
            return false;
        }

        logger::info("ShowStats loaded"sv);
    } catch (const std::exception& e) {
        logger::critical("failed, cause {}"sv, e.what());
        return false;
    }

    return true;
}
