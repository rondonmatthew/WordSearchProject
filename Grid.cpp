#include "Grid.h"
#include <cstdlib>

// Constructor to initialize the grid with given rows and columns
Grid::Grid(int r, int c) {
    rows = r;
    cols = c;

    //Resize the grid to chosen size
    grid.resize(rows, vector<char>(cols));
}

// Fill grid with dots to show empty space
void Grid::initialize(){
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            grid[row][col] = '.';
        }
    }
}

// Prints the grid
void Grid::display() const {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << grid[row][col] << " ";

        }
        cout << endl;
    }
}

// Checks if the given row and column are within the bounds of the grid
bool Grid::isInBounds(int row, int col) const {
    return row>= 0 && row < rows && col >= 0 && col < cols;

}

// Sets a letter at the specified row and column
void Grid::setLetter(int row, int col, char letter) {
    if (isInBounds(row,col)) {
        grid[row][col] = letter;
    }
}

// Gets the letter at the specified row and column
char Grid::getLetter(int row, int col) const {
    if (isInBounds(row, col)) {
        return grid[row][col];
    }

    return '?';
}

// Fills empty spaces in the grid with random capital letters
void Grid::fillEmptySpaces() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == '.') {
                grid[row][col] = 'A' + rand() % 26; // Random capital letter
            }
        }
    }
}

int Grid::getRows() const {
    return rows;
}

int Grid::getCols() const {
    return cols;
}
