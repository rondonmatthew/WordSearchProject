#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
using namespace std;

// Handles the 2d word search grid
class Grid {
    private:
        vector<vector<char>> grid;
        int rows;
        int cols;

    public:
        Grid(int r, int c);

        void initialize();
        void display() const;

        bool isInBounds(int row, int col) const;

        void setLetter(int row, int col, char letter);
        char getLetter(int row, int col) const;

        void fillEmptySpaces();

        int getRows() const;
        int getCols() const;
};

#endif
