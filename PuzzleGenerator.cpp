#include "PuzzleGenerator.h"
#include <cstdlib>

// Constructor 
PuzzleGenerator::PuzzleGenerator(Grid& g, vector<string> wordList) : grid(g) {
    words = wordList;
    backtrackCount = 0;
}
 // Starts the puzzle generation process
 bool PuzzleGenerator::generate() {
    return placeWords(0);
 }

 // Recursive function to place words in the grid
 bool PuzzleGenerator::placeWords(int index) {
    // Base case: All words have been placed
    if (index == words.size()) {
        return true;
    }

    string currentWord = words[index];

    // These arrays store the possible directions for placing words (right, down, diagonal down-right, diagonal down-left)
    int rowDirections[8] = {-1,-1,-1,0,0,1,1,1};
    int colDirections[8] = {-1,0,1,-1,1,-1,0,1};

    // try evey row 
    for (int row = 0; row < grid.getRows(); row++) {

        //Try every column
        for (int col = 0; col < grid.getCols(); col++) {

            // Try all 8 directions
            for (int dir = 0; dir < 8; dir++) {
                int rowDir = rowDirections[dir];
                int colDir = colDirections[dir];

                // Check if the word can be placed at the current position and direction
                if (canPlaceWord(currentWord, row, col,rowDir,colDir)) {
                    
                    // Place the Word
                    placeWord(currentWord, row, col, rowDir, colDir);

                    // try placing the next word
                    if (placeWords(index + 1 )) {
                        return true;
                    }
                    
                    // If the next word cannot be places, backtrack and remove the current word
                    removeWord(currentWord, row, col, rowDir, colDir);
                    backtrackCount++;
                }
            }
        }
    }
    return false;
 }

 // Checks if a word can be placed at the specified position and direction
 bool PuzzleGenerator::canPlaceWord(string word, int row, int col, int rowDir, int colDir){
    for (int i = 0; i < word.length(); i++) {
        int newRow = row + i * rowDir;
        int newCol = col + i * colDir;

        // Makes sure the position is inside the gride
        if (!grid.isInBounds(newRow,newCol)) {
            return false;
        }

        char currentLetter = grid.getLetter(newRow, newCol);

        // The spot must be empty or already have the same letter
        if (currentLetter != '.' && currentLetter != word[i]) {
            return false;
        }
    }

    return true;
 }

 // places a word into the grid
void PuzzleGenerator::placeWord(string word,int row, int col, int rowDir, int colDir) {
    for (int i = 0; i < word.length(); i++) {
        int newRow = row + i * rowDir;
        int newCol = col + i * colDir;

        grid.setLetter(newRow, newCol, word[i]);
    }
}

// Removes a word during backtracking 
void PuzzleGenerator::removeWord(string word, int row, int col, int rowDir, int colDir) {
    for (int i = 0; i < word.length(); i++) {
        int newRow = row + i * rowDir;
        int newCol = col + i * colDir;

        grid.setLetter(newRow,newCol, '.');
    }
}

// Returns the number of times backtracking happened
int PuzzleGenerator::getBacktrackCount() const {
    return backtrackCount;
}
