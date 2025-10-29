#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

class Small_Language_Model {
    public: 
    Small_Language_Model(string, int, int);

    void train();
    void get_word_freq();
    void get_next_char_freq();

    private:
    string text;
    int word_size;
    int output_size;
    int word_count;
    map<string, float> word_freq;
    map<string, map<char, float>> next_char_freq;
    map<string, int> substr_char_count;
    map<string, map<char, int>> next_char_count;


    void update_word_freq(string, int);
    void update_next_char_freq();
    void update_next_char_count(string, char);
};