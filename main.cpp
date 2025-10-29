#include <iostream>
#include <fstream>
#include "small_language_model.h"
#include "text_generator.h"
using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 4) { // ensures correct useage
        cout << "Usage: slm <int> <file> <int>" << endl;
        return 1;
    }

    int word_size;
    int output_size;
    try { // checks that integers were inputted
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
    string line;
    while (getline(datafile, line)) {
        text += line;  // puts all of the text from the file into one string
    }
    datafile.close();

    // create and train the model
    Small_Language_Model model = Small_Language_Model(text, word_size, output_size);
    model.train(); 

    // generate text using the probabilities from the training model
    TextGenerator generator(model);
    string generated_text = generator.generateText(output_size);
    cout << "Generated text: " << generated_text << endl;

}