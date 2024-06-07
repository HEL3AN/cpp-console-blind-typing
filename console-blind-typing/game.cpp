#pragma once
#include <algorithm>
#include <curses.h>
#include <vector>
#include <string>
#include "globals.cpp"

namespace Game_Window {
    std::string correct_text;
    std::string user_text;

    std::vector<int> index_of_incorrect_symbols;
    std::vector<int> index_of_correct_typed_words;
    std::vector<std::string> words_of_correct_text;
    int current_word_index; 

    void Init() {
        init_pair(1, COLOR_BLACK, COLOR_GREEN);
        correct_text = "give me this fancy boolochka";
        user_text.clear();
        index_of_incorrect_symbols.clear();
        index_of_correct_typed_words.clear();    
        words_of_correct_text = SplitIntoWords(correct_text);
        current_word_index = 0;
    }

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
            case 32:
                if (user_text == words_of_correct_text[current_word_index]) {
                    user_text.clear();
                    index_of_incorrect_symbols.clear();
                    ++current_word_index;
                    index_of_correct_typed_words.push_back(static_cast<int>(index_of_correct_typed_words.size()));
                }
                break;
            default:
                if (user_text.size() <  words_of_correct_text[current_word_index].size()) {
                    user_text.push_back(static_cast<char>(CURRENT_KEY));
                    if (user_text[user_text.size() - 1] != words_of_correct_text[current_word_index][user_text.size() - 1]) {
                        index_of_incorrect_symbols.push_back(static_cast<int>(user_text.size() - 1));
                    }
                }
                if (user_text.size() == words_of_correct_text[current_word_index].size()
                    && current_word_index == static_cast<int>(words_of_correct_text.size() - 1)
                    && index_of_incorrect_symbols.empty()) {
                    wclear(MAIN_WINDOW);
                    mvwprintw(MAIN_WINDOW, START_Y, START_X, "%s", "You win!");
                    wrefresh(MAIN_WINDOW);
                    napms(1000);
                    ChangeWindow(WINDOWS::Menu);
                }
                break;
        }
    }

    void Print() {
        int x_padding = 0;
        for (int i = 0; i < static_cast<int>(words_of_correct_text.size()); ++i) {
            if (i != 0)
                wmove(MAIN_WINDOW, START_Y + 1, START_X + 1 + x_padding + i);
            else    
                wmove(MAIN_WINDOW, START_Y + 1, START_X + 1);
            if (current_word_index > i) {
                wattron(MAIN_WINDOW, COLOR_PAIR(1));
                waddstr(MAIN_WINDOW, words_of_correct_text[i].c_str());
                wattroff(MAIN_WINDOW, COLOR_PAIR(1));
            } else {
                waddstr(MAIN_WINDOW, words_of_correct_text[i].c_str());
            }  
            x_padding += static_cast<int>(words_of_correct_text[i].size());        
        }
        


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