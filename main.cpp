#include <iostream>
#include <fstream>
#include "small_language_model.h"
using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 4) { 
        cout << "Usage: slm <int> <file> <int>" << endl;
        return 1;
    }

    int word_size;
    int output_size;
    try {
        word_size = stoi(argv[1]);
        output_size = stoi(argv[3]);
    }
    catch (invalid_argument) {
        cerr << "Invalid input - Usage: slm <int> <file> <int>" << endl;
        return 1;        
    }

    ifstream datafile(argv[2]);
    if (!datafile) { // Check that file is an actual file
        cerr << "can't open " << argv[2] << "\n";
        return 1;
    }

    string text;
    getline(datafile, text);
    datafile.close();
    cout << text << endl;

    Small_Language_Model model = Small_Language_Model(text, word_size, output_size);
    model.train();
    model.get_word_freq();
    model.get_next_char_freq();
}