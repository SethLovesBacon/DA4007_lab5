#include <iostream> 
#include <string>
#include <cmath>
#include "text_generator.h"
#include "small_language_model.h"
#include <algorithm>
#include <stdexcept> 
#include <vector>
using namespace std; 


TextGenerator::TextGenerator(Small_Language_Model& input_model) : model(input_model) {}


template <typename T> // lets me be able to use this generically as string or char
T TextGenerator::object_from_prob(const map<T, float>& probability_map) {
    vector<T> items; // stores the keys
    vector<float> cumulative; // stores the cumulative probabilities
    float sum = 0.0;

    for (auto& probability : probability_map) {
        items.push_back(probability.first);
        sum += probability.second;
        cumulative.push_back(sum);
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, sum);
    double r = dis(gen);

    for (size_t i = 0; i < cumulative.size(); ++i) {
        if (r <= cumulative[i])
            return items[i];
    }

    return items.back();
}


string TextGenerator::generate_text(int output_size) {
    map<string, float>& word_freq = model.get_word_freq();
    map<string, map<char, float>>& next_char_freq = model.get_next_char_freq();

    // Pick starting word
    string current_word = object_from_prob(word_freq);
    string text = current_word;

    int remaining = output_size - current_word.size();
    for (int i = 0; i < remaining; ++i) {
        if (next_char_freq.find(current_word) == next_char_freq.end())
            break;

        char next_char = object_from_prob(next_char_freq[current_word]);
        text += next_char;

        current_word = current_word.substr(1) + next_char;
    }

    return text;
}

