#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Grid.h"
#include "PuzzleGenerator.h"
#include "PuzzleSolver.h"
#include "PerformanceAnalyzer.h"

using namespace std;

int main() {
    srand(time(0));

    // Create grid
    Grid puzzleGrid(10, 10);
    puzzleGrid.initialize();

    // Word list
    vector<string> words;
    words.push_back("BACKTRACK");
    words.push_back("CLASS");
    words.push_back("GHOST");
    words.push_back("WORDSEARCH");

    // Create generator
    PuzzleGenerator generator(puzzleGrid, words);

    // Start timing generation
    PerformanceAnalyzer generationTimer;
    generationTimer.startTimer();

    bool success = generator.generate();

    generationTimer.stopTimer();

    if (success) {
        puzzleGrid.fillEmptySpaces();

        cout << "Generated Word Search Puzzle:" << endl;
        puzzleGrid.display();

        cout << endl;
        cout << "Backtracking Steps: " << generator.getBacktrackCount() << endl;

        // create solver and start timing solving
        PuzzleSolver solver(puzzleGrid, words);

        PerformanceAnalyzer solvingTimer;
        solvingTimer.startTimer();

        solver.solve();

        solvingTimer.stopTimer();

        // Performance results 
        cout << endl;
        cout << "Performance Results:" << endl;
        cout << "Generation Time: " << generationTimer.getElapsedTime() << " seconds" << endl;
        cout << "Solving Time: " << solvingTimer.getElapsedTime() << " seconds" << endl;
        cout << "Backtracking Steps: " << generator.getBacktrackCount() << endl;

    } else {
        cout << "Could not place all words in the grid." << endl;
    }

    return 0;
}