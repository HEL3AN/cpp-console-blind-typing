#pragma once
#include <curses.h>
#include <map>
#include <string>

namespace Menu {
    int x = 0;
    int y = 0;
    enum class Element {
        Start,
        Exit
    };

    Element choise = Element::Start;

    const std::map<Element, std::string> menu_elements_text = { {Element::Start, "Start"}, {Element::Exit, "Exit"} };

    void PrintMenu(WINDOW *window) {
        for (const auto& [element, text] : menu_elements_text) {
            if (element == choise) {
                mvprintw(y, x, "%s", text.c_str());
            } else {
                mvprintw(y, x, "%s", text.c_str());
            }
            ++y;
        }
        refresh();
    }
}