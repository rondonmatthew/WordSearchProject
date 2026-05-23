#ifndef PUZZLEGENERATOR_H
#define PUZZLEGENERATOR_H

#include <vector>
#include <string>
#include "Grid.h"

using namespace std;

// Handles the generation of the word search puzzle
class PuzzleGenerator {
    private:
        Grid& grid; // Reference to the grid where the puzzle will be generated
        vector<string> words; //List of words to place in the grid
        int backtrackCount; // Counter for backtracking attempts

        bool placeWords(int index);
        bool canPlaceWord(string word, int row, int col, int rowDir, int colDir);
        void placeWord(string word, int row, int col, int rowDir, int colDir);
        void removeWord(string word, int row, int col, int rowDir, int colDir);

    public:
        PuzzleGenerator(Grid& g, vector<string> wordList);

        bool generate();
        int getBacktrackCount() const;

};

#endif
