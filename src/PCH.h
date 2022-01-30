#pragma once

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"

#pragma warning(push)
#include <spdlog/sinks/basic_file_sink.h>
#ifdef NDEBUG
#include <spdlog/sinks/basic_file_sink.h>
#else
#include <spdlog/sinks/msvc_sink.h>
#endif
#pragma warning(pop)

#include "AutoTOML.hpp"

using namespace std::literals;

namespace stl {
    using namespace SKSE::stl;
    using SKSE::stl::report_and_fail;

    constexpr std::string_view safe_string(const char* a_str) { return a_str ? a_str : ""sv; }
}

namespace logger = SKSE::log;

#define DLLEXPORT __declspec(dllexport)

#include "Version.h"
#include "settings/settings.h"
#include "utils/constants.h"
#include "utils/utils.h"
