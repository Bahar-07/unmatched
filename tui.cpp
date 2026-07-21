#include "tui.h"
#include <iostream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

int tui::main_menu()
{
    auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries = {
        "Play",
        "Help",
        "Exit"
    };

   
    int selected = 0;

    auto menu = Menu(&entries, &selected);

    auto component = CatchEvent(menu, [&](Event event) {
        if (event == Event::Return) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    auto renderer = Renderer(component, [&] {
        return vbox({
            text("UNMATCHED") | bold | center,
            separator(),
            component->Render(),
        });
    });

    screen.Loop(renderer);

    return selected;
}
int tui::action_menu()
{
    auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries = {
        "Maneuver",
        "Scheme",
        "Attack",
        "Show map",
        "Your status",
        "Enemy status",
        "Back to Main Menu"
    };

    int selected = 0;

    auto menu = Menu(&entries, &selected);

    auto component = CatchEvent(menu, [&](Event event) {
        if (event == Event::Return) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    auto renderer = Renderer(component, [&] {
        return vbox({
            text("Choose Action") | bold | center,
            separator(),
            component->Render(),
        });
    });

    screen.Loop(renderer);

    return selected;
}
int tui::agee(std::string a , std::string b)
{
     auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries = {
        a,
        b
        
    };

    int selected = 0;

    auto menu = Menu(&entries, &selected);

    auto component = CatchEvent(menu, [&](Event event) {
        if (event == Event::Return) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    auto renderer = Renderer(component, [&] {
        return vbox({
            text("Who is younger?") | bold,
            component->Render(),
        });
    });

    screen.Loop(renderer);

    return selected;
}
int tui::choose_character()
{
     auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries = {
        "Dracula",
        "Sherlock Holmes"
    };

   
    int selected = 0;

    auto menu = Menu(&entries, &selected);

    auto component = CatchEvent(menu, [&](Event event) {
        if (event == Event::Return) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    auto renderer = Renderer(component, [&] {
        return vbox({
            text(""),
            component->Render(),
        });
    });

    screen.Loop(renderer);

    return selected;
}
int tui::choose_space(map& g , std::string title , std::vector<int> entriess)
{
    auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries;
        for(auto s:entriess)
        {
            entries.push_back(std::to_string(s));
        }

   
    int selected = 0;

    auto menu = Menu(&entries, &selected);

    auto component = CatchEvent(menu, [&](Event event) {
        if (event == Event::Return) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    auto renderer = Renderer(component, [&] {
        return vbox({
            text(title),
            component->Render(),
        });
    });

    screen.Loop(renderer);

    return selected;
}
int tui::yesorno(std::string title)
{
     auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries = {
        "yes",
        "no"
    };

   
    int selected = 0;

    auto menu = Menu(&entries, &selected);

    auto component = CatchEvent(menu, [&](Event event) {
        if (event == Event::Return) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    auto renderer = Renderer(component, [&] {
        return vbox({
            text(title) |bold,
            component->Render(),
        });
    });

    screen.Loop(renderer);

    return selected;
}
int tui::choose_acharacter(std::string title , std::vector<std::string> entriess)
{
      auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries;
        for(auto s:entriess)
        {
            entries.push_back(s);
        }

   
    int selected = 0;

    auto menu = Menu(&entries, &selected);

    auto component = CatchEvent(menu, [&](Event event) {
        if (event == Event::Return) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    auto renderer = Renderer(component, [&] {
        return vbox({
            text(title) |bold,
            component->Render(),
        });
    });

    screen.Loop(renderer);

    return selected;
}
