#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H

#include <iostream>
#include <vector>
#include <string>
#include "Grid.h"

using namespace std;

// This class searches the grid to find the words
class PuzzleSolver {
private:
    Grid& grid;
    vector<string> words;

    bool searchDirection(string word, int row, int col, int rowDir, int colDir);

public:
    PuzzleSolver(Grid& g, vector<string> wordList);

    void solve();
};

#endif
