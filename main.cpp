#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 4) { 
        cout << "Usage: slm <int> <file> <int>" << endl;
        return 1;
    }
    try {
        int word_size = stoi(argv[1]);
        int output_size = stoi(argv[3]);
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




    datafile.close();
}