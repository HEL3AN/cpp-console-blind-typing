#pragma once
#include <curses.h>
#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include "globals.cpp"

namespace Menu_Window {
    enum class Element {
        Start,
        Setting,
        Exit,
    };

    Element choise = Element::Start;

    const std::map<Element, std::string> menu_elements_text = { {Element::Start, "Start"},
                                                                {Element::Setting, "Setting"},
                                                                {Element::Exit, "Exit"} };

    void ControlMenu() {
        switch (CURRENT_KEY)
        {
            case KEY_UP:
                choise = static_cast<Element>(static_cast<int>(choise) - 1);
                break;
            case KEY_DOWN:
                choise = static_cast<Element>(static_cast<int>(choise) + 1);
                break;
            case KEY_ENTER:
                break;
            default:
                break;
        }
    }

    void PrintMenu(WINDOW *window) {
        ControlMenu();
 
        int y_padding = static_cast<int>(menu_elements_text.size()) / 2;
        for (const auto& [element, text] : menu_elements_text) {
            if (element == choise) {
                wattron(window, A_REVERSE);
                mvwprintw(window,
                          WINDOW_HEIGHT / 2 - y_padding + static_cast<int>(element),
                          WINDOW_WIDTH / 2 - static_cast<int>(text.size()) / 2,
                          "%s", text.c_str());
                wattroff(window, A_REVERSE);
            } else {
                mvwprintw(window,
                          WINDOW_HEIGHT / 2 - y_padding + static_cast<int>(element),
                          WINDOW_WIDTH / 2 - static_cast<int>(text.size()) / 2,
                          "%s", text.c_str());
            }
        }
    }
}