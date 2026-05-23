# Word Search Puzzle Generator & Solver

## Project Description
This project is a C++ program that creates and solves a word search puzzle.  
The program takes a list of words, places them into a 2D grid, and then searches the grid to find where the words are located.

The goal of this project was to apply concepts learned in class such as vectors, object-oriented programming, and backtracking.

---

## Features
- Generates a word search puzzle using a 2D grid
- Places words in multiple directions:
  - Horizontal
  - Vertical
  - Diagonal
- Uses backtracking to place words if needed
- Solves the puzzle by searching the grid
- Displays:
  - Starting position of each word
  - Direction of each word
- Measures performance:
  - Generation time
  - Solving time
  - Backtracking steps

---

## How to Compile and Run

### Compile:
```bash
g++ main.cpp Grid.cpp PuzzleGenerator.cpp PuzzleSolver.cpp PerformanceAnalyzer.cpp -o wordsearch
