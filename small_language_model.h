#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Small_Language_Model {
    public: 
    Small_Language_Model(string, int, int);

    void train();

    private:
    string text;
    int word_size;
    int output_size;
};