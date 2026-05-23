#include "PuzzleSolver.h"

// Constructor
PuzzleSolver::PuzzleSolver(Grid& g, vector<string> wordList) : grid(g) {
    words = wordList;
}

// Checks one direction for a word
bool PuzzleSolver::searchDirection(string word, int row, int col, int rowDir, int colDir) {
    for (int i = 0; i < word.length(); i++) {
        int newRow = row + i * rowDir;
        int newCol = col + i * colDir;

        // Make sure we do not go outside the grid
        if (!grid.isInBounds(newRow, newCol)) {
            return false;
        }

        // If one letter does not match, stop checking
        if (grid.getLetter(newRow, newCol) != word[i]) {
            return false;
        }
    }

    return true;
}

// Searches the whole grid for each word
void PuzzleSolver::solve() {
    int rowDirections[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colDirections[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    string directionNames[8] = {
        "Up Left",
        "Up",
        "Up Right",
        "Left",
        "Right",
        "Down Left",
        "Down",
        "Down Right"
    };

    cout << endl;
    cout << "Solver Results:" << endl;

    for (int w = 0; w < words.size(); w++) {
        string currentWord = words[w];
        bool found = false;

        for (int row = 0; row < grid.getRows(); row++) {
            for (int col = 0; col < grid.getCols(); col++) {

                // Only start searching if the first letter matches
                if (grid.getLetter(row, col) == currentWord[0]) {

                    for (int dir = 0; dir < 8; dir++) {
                        if (searchDirection(currentWord, row, col, rowDirections[dir], colDirections[dir])) {
                            cout << currentWord << " found at ";
                            cout << "(" << row << ", " << col << ") ";
                            cout << "Direction: " << directionNames[dir] << endl;

                            found = true;
                        }
                    }
                }
            }
        }

        if (!found) {
            cout << currentWord << " was not found." << endl;
        }
    }
}