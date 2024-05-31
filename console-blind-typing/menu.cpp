#pragma once
#include <curses.h>
#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include "globals.cpp"

namespace Menu {
    enum class Element {
        Start,
        Exit
    };

    Element choise = Element::Start;

    const std::map<Element, std::string> menu_elements_text = { {Element::Start, "Start"}, {Element::Exit, "Exit"} };

    void PrintMenu(WINDOW *window) {
        int y_padding = 0;
        box(window, 0, 0); 
        for (const auto& [element, text] : menu_elements_text) {
            if (element == choise) {
                mvprintw(WINDOW_HEIGHT / 2 - static_cast<int>(menu_elements_text.size()) / 2 + y_padding,
                         WINDOW_WIDTH / 2 - static_cast<int>(text.size()) / 2,
                         "%s", text.c_str());
            } else {
                mvprintw(WINDOW_HEIGHT / 2 - static_cast<int>(menu_elements_text.size()) / 2 + y_padding,
                         WINDOW_WIDTH / 2 - static_cast<int>(text.size()) / 2,
                         "%s", text.c_str());
            }
            ++y_padding;
        }
        wrefresh(window);
    }
}