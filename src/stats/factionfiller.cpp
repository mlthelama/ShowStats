#pragma once
#include "stats/factionfiller.h"

using Menu = FactionMenuValue;

auto FactionFiller::GetSingleton() -> FactionFiller* {
    static FactionFiller singleton;
    return std::addressof(singleton);
}

std::vector<std::shared_ptr<FactionItem>> FactionFiller::getData() {
    std::vector<std::shared_ptr<FactionItem>> factionList = {
        /*TODO cleanup menu just one cfg for faction, thane, champion*/
        std::make_shared<FactionItem>(FactionValue::darkbrotherHood, *Settings::darkbrotherHoodString,
            *Settings::showFactions, getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::thiefsGuild, *Settings::thiefsGuildString, *Settings::showFactions,
            getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::orcFriend, *Settings::orcFriendString, *Settings::showFactions,
            getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::collegeOfWinterhold, *Settings::collegeOfWinterholdString,
            *Settings::showFactions, getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::companions, *Settings::companionsString, *Settings::showFactions,
            getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::imperialLegion, *Settings::imperialLegionString,
            *Settings::showFactions, getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::stormcloaks, *Settings::stormcloaksString, *Settings::showFactions,
            getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::greybeard, *Settings::greybeardString, *Settings::showFactions,
            getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::bard, *Settings::bardString, *Settings::showFactions,
            getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::volkiharVampireClan, *Settings::volkiharVampireClanString,
            *Settings::showFactions, getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::dawnguard, *Settings::dawnguardString, *Settings::showFactions,
            getFactionMenu(*Settings::factionMenu)),
        std::make_shared<FactionItem>(FactionValue::houseTelvanni, *Settings::houseTelvanniString,
            *Settings::showFactions, getFactionMenu(*Settings::factionMenu)),

        std::make_shared<FactionItem>(FactionValue::thaneOfEastmarch, *Settings::thaneOfEastmarchName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfFalkreath, *Settings::thaneOfFalkreathName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfHaafingar, *Settings::thaneOfHaafingarName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfHjaalmarch, *Settings::thaneOfHjaalmarchName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfThePale, *Settings::thaneOfThePaleName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfTheReach, *Settings::thaneOfTheReachName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfTheRift, *Settings::thaneOfTheRiftName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfWhiterun, *Settings::thaneOfWhiterunName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),
        std::make_shared<FactionItem>(FactionValue::thaneOfWinterhold, *Settings::thaneOfWinterholdName,
            *Settings::showThanes, getFactionMenu(*Settings::thaneMenu), true),

        std::make_shared<FactionItem>(FactionValue::azura, *Settings::azuraName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::clavicusVile, *Settings::clavicusVileName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::hermaeusMora, *Settings::hermaeusMoraName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::hircine, *Settings::hircineName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::malacath, *Settings::malacathName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::mehrunesDagon, *Settings::mehrunesDagonName,
            *Settings::showChampion, getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::mephala, *Settings::mephalaName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::meridia, *Settings::meridiaName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::molagBal, *Settings::molagBalName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::namira, *Settings::namiraName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::nocturnal, *Settings::nocturnalName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::peryite, *Settings::peryiteName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::sanguine, *Settings::sanguineName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::sheogorath, *Settings::sheogorathName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
        std::make_shared<FactionItem>(FactionValue::vaermina, *Settings::vaerminaName, *Settings::showChampion,
            getFactionMenu(*Settings::championMenu), true),
    };

    logger::debug("Vector Size is {}"sv, factionList.size());
    return factionList;
}

void FactionFiller::PrintFactionVector(std::vector<std::shared_ptr<FactionItem>>& p_vec) {
    logger::trace("Vector Size is {}"sv, p_vec.size());
    for (auto& element : p_vec) {
        logger::trace("name {}, value {}, displayname ({}), show {}, guiText ({}), menu {}, VID {}"sv,
            element->getName(), element->getValue(), element->getDisplayName(), element->getShow(),
            element->getGuiText(), element->getMenu(), element->getDisplayIsValue());
    }
}