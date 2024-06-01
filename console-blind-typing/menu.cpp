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

    void Control() {
        switch (CURRENT_KEY)
        {
            case KEY_UP:
                choise = static_cast<Element>(static_cast<int>(choise) - 1);
                break;
            case KEY_DOWN:
                choise = static_cast<Element>(static_cast<int>(choise) + 1);
                break;
            case KEY_ENTER:
                switch (choise)
                {
                    case Element::Start:
                        ChangeWindow(WINDOWS::Game);
                        break;   
                    case Element::Setting:
                        //ChangeWindow(WINDOWS::Setting);
                        break;
                    case Element::Exit:
                        SHOULD_CLOSE = true;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    void Print() {
        int y_padding = static_cast<int>(menu_elements_text.size()) / 2;
        for (const auto& [element, text] : menu_elements_text) {
            if (element == choise) {
                wattron(MAIN_WINDOW, A_REVERSE);
                mvwprintw(MAIN_WINDOW,
                          WINDOW_HEIGHT / 2 - y_padding + static_cast<int>(element),
                          WINDOW_WIDTH / 2 - static_cast<int>(text.size()) / 2,
                          "%s", text.c_str());
                wattroff(MAIN_WINDOW, A_REVERSE);
            } else {
                mvwprintw(MAIN_WINDOW,
                          WINDOW_HEIGHT / 2 - y_padding + static_cast<int>(element),
                          WINDOW_WIDTH / 2 - static_cast<int>(text.size()) / 2,
                          "%s", text.c_str());
            }
        }
    }
}