.PHONY: clean

CXX = g++
CXXFLAGS = -Wall -std=c++17

slm: main.o small_language_model.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o slm