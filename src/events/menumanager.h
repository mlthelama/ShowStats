#include "handler/showhandler.h"
#include "scaleform/menus/factionmenu.h"
#include "scaleform/menus/statsinventorymenu.h"
#include "scaleform/menus/statsmenu.h"

class MenuManager : public RE::BSTEventSink<RE::MenuOpenCloseEvent> {
public:
    using EventResult = RE::BSEventNotifyControl;
    using ShowMenu = MenuUtil::ShowMenu;

    static MenuManager* GetSingleton() {
        static MenuManager singleton;
        return std::addressof(singleton);
    }

    static void Sink() {
        RE::UI::GetSingleton()->AddEventSink(
            static_cast<RE::BSTEventSink<RE::MenuOpenCloseEvent>*>(MenuManager::GetSingleton()));
    }

    auto ProcessEvent(RE::MenuOpenCloseEvent const* a_event,
        [[maybe_unused]] RE::BSTEventSource<RE::MenuOpenCloseEvent>* a_eventSource) -> EventResult {
        if (!a_event) {
            return EventResult::kContinue;
        }

        if (a_event->opening && a_event->menuName == RE::InventoryMenu::MENU_NAME &&
            *Settings::showInventoryStatsAutoOpen) {
            ShowHandler::GetSingleton()->HandleInventoryStatsOpen();
        }

        if (!a_event->opening && a_event->menuName == RE::InventoryMenu::MENU_NAME) {
            ShowHandler::GetSingleton()->CloseWindow(ShowMenu::mStatsInventory);
        }

        return EventResult::kContinue;
    }

private:
    MenuManager() = default;
    MenuManager(const MenuManager&) = delete;
    MenuManager(MenuManager&&) = delete;
    virtual ~MenuManager() = default;

    MenuManager& operator=(const MenuManager&) = delete;
    MenuManager& operator=(MenuManager&&) = delete;
};