#pragma once
#include <algorithm>
#include <curses.h>
#include <vector>
#include <string>
#include "globals.cpp"

namespace Game_Window {
    std::string correct_text = "give me this fancy boolochka";
    std::string user_text;

    std::vector<int> index_of_incorrect_symbols;

    void Control() {
        switch (CURRENT_KEY)
        {
            case KEY_EXIT:
                ChangeWindow(WINDOWS::Menu);
                break;     
            case KEY_ENTER:
                break; 
            case KEY_BACKSPACE:
                if (user_text.size()) {
                    user_text.pop_back();         
                    if (std::count(index_of_incorrect_symbols.begin(), index_of_incorrect_symbols.end(),
                                   static_cast<int>(user_text.size()))) {
                        index_of_incorrect_symbols.erase(index_of_incorrect_symbols.begin() + static_cast<int>(user_text.size()));
                    }
                }          
                break;
            default:
                if (user_text.size() < correct_text.size()) {
                    user_text.push_back(static_cast<char>(CURRENT_KEY));
                    if (user_text[user_text.size() - 1] != correct_text[user_text.size() - 1]) {
                        index_of_incorrect_symbols.push_back(static_cast<int>(user_text.size() - 1));
                    }
                }
                if (user_text.size() == correct_text.size() && index_of_incorrect_symbols.empty()) {
                    user_text.clear();
                    correct_text = "You won!";
                    PrintWindow();
                    napms(1000);
                    ChangeWindow(WINDOWS::Menu);
                }
                break;
        }
    }

    void Print() {
        mvwprintw(MAIN_WINDOW, START_Y + 1, START_X + 1, "%s", correct_text.c_str());
        for (int i = 0; i < static_cast<int>(user_text.size()); ++i) {
            wmove(MAIN_WINDOW, START_Y + 2, START_X + 1 + i);
            if (std::count(index_of_incorrect_symbols.begin(), index_of_incorrect_symbols.end(), i)) {
                wattron(MAIN_WINDOW, A_REVERSE);
                waddch(MAIN_WINDOW, user_text[i]);
                wattroff(MAIN_WINDOW, A_REVERSE);
            } else {
                waddch(MAIN_WINDOW, user_text[i]);
            }
        }
        wclrtoeol(MAIN_WINDOW);
    }
}