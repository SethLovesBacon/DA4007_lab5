# DA4007_lab5
Lab 5 for DA4007 - SLM

I only have a few commits under the src folder, this is because I had orginally put all my files in the main repo folder and only made and moved them into the src folder on the 29th Oct.
The vast majority of my commits are under History for DA4007_lab5

This project implements a small language model that generates text based on k-grams (substrings of length k). The program reads an input text file, then uses the substring size from the input to cycle through substrings of the text. Frequencies of the k-grams are then computed and the probabilities of the next character are recorded. This training model can be used along with the output size to generate new text that appears similar but can be different due to the next character being affected by the probability from the next character frequency map.


Files
- src/main.cpp — The main file that receives the input and runs the program.  
- src/small_language_model.h/cpp — Implements the SLM and does the training, frequency calculation, next character probabilities.  
- src/text_generator.h/cpp — Generates new text from the trained SLM from choosing a random character based on the next character probabilities.  
- src/Makefile — Compiles the project into the executable slm file. Usage: ./slm <sub_string_size> <file> <output_size>.


From the src directory:

```bash
make

Usage: ./slm <sub_string_size> <file> <output_size>
