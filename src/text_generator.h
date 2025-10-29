#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include <map>
using namespace std;

class Small_Language_Model; 

class TextGenerator {
public:
    TextGenerator(Small_Language_Model&);

    string generate_text(int);

private:
    Small_Language_Model& model;  // store reference instead of object
    
    double random_number(float);

    template <typename T>
    T object_from_prob(const map<T, float>&);
};
