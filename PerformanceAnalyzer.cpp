#include "PerformanceAnalyzer.h"

// Saves the current time when the timer starts
void PerformanceAnalyzer::startTimer() {
    startTime = clock();
}

// Saves the current time when the timer stops
void PerformanceAnalyzer::stopTimer() {
    endTime = clock();
}

// Converts the time difference into seconds
double PerformanceAnalyzer::getElapsedTime() const {
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}