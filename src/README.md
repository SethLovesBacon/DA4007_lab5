# DA4007_lab5
Lab 5 for DA4007 - SLM

I only have a few commits under the src folder, this is because I had orginally put all my files in the main repo folder and only made and moved them into the src folder on the 29th Oct.
The vast majority of my commits are under History for DA4007_lab5

This project implements a small language model that generates text based on k-grams (substrings of length k). The program reads an input text file, computes frequencies of k-grams and the probabilities of the next character, and then generates new text.


Files
- src/main.cpp — Entry point; parses arguments and runs the program.  
- src/small_language_model.h/cpp — Implements the SLM and does the training, frequency calculation, next character probabilities.  
- src/text_generator.h/cpp — Generates new text from the trained SLM.  
- src/Makefile — Compiles the project into the executable "slm".


From the src directory:

```bash
make

Usage: ./slm <sub_string_size> <file> <output_size>
