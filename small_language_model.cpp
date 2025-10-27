#include <iostream> 
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "small_language_model.h"
using namespace std; 


Small_Language_Model::Small_Language_Model(string input_text, int input_word_size, int input_output_size) {
    text = input_text;
    word_size = input_word_size;
    output_size = input_output_size;
}


void Small_Language_Model::train() {
    word_count = 0;
    for (int i = 0; i < text.size() - word_size + 1; i++) {
        string sub_str = text.substr(i, word_size);

        char next_char;
        if (i == text.size() - word_size + 1) { next_char = ' '; }
        else { next_char = text[i + 1]; }

        if (word_freq.count(sub_str) == 0) { 
            word_freq[sub_str] = 1; 
            next_char_freq[sub_str][next_char] = 1;
        }
        else {
            word_freq[sub_str] += 1;
            if (next_char_freq[sub_str].count(next_char) == 0) {
                next_char_freq[sub_str][next_char] = 1;
            }
            else { next_char_freq[sub_str][next_char] += 1; }
            
        }
        word_count++;
    }
}


void Small_Language_Model::get_word_freq() {
    for (auto word : word_freq) {
        cout << word.first << ": " << word.second << endl;
    }
}


void Small_Language_Model::get_next_char_freq() {
    for (auto word : next_char_freq) {
        map<char, int>char_freq = word.second;

        for (auto character : char_freq) {
            cout << word.first << " " << character.first << " " << character.second << endl;
        }
    }

}