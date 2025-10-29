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
    word_count = text.size() - word_size + 1;
    string sub_str;
    char next_char;
    for (int i = 0; i < word_count; i++) {
        sub_str = text.substr(i, word_size);

        update_word_freq(sub_str, word_count);

        if (i != (text.size() - word_size)) { 
            next_char = text[i + word_size]; 
            update_next_char_count(sub_str, next_char);
        }
    }
    update_next_char_freq();
}


void Small_Language_Model::update_word_freq(string sub_str, int count) {
    word_freq[sub_str] += 1.0 / count;
}


void Small_Language_Model::update_next_char_count(string sub_str, char next_char) {
    substr_char_count[sub_str] += 1;
    next_char_count[sub_str][next_char] += 1;
}


void Small_Language_Model::update_next_char_freq() {
    for (auto [word, next_char] : next_char_count) {
        int total = substr_char_count[word];
        for (auto [character, count] : next_char)
            next_char_freq[word][character] = 1.0 * count / total;
    }
}


map<string, float>& Small_Language_Model::get_word_freq() {
    return word_freq;
}


map<string, map<char, float>>& Small_Language_Model::get_next_char_freq() {
    return next_char_freq;
}


void Small_Language_Model::print_word_freq() {
    for (auto word : word_freq) {
        cout << word.first << ": " << word.second << endl;
    }
}


void Small_Language_Model::print_next_char_freq() {
    for (auto word : next_char_freq) {
        map<char, float>char_freq = word.second;

        for (auto character : char_freq) {
            cout << word.first << " " << character.first << " " << character.second << endl;
        }
    }
}