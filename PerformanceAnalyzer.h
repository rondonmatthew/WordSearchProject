#ifndef PERFORMANCEANALYZER_H
#define PERFORMANCEANALYZER_H

#include <ctime>
using namespace std;

// This class helps measure how long parts of the program take
class PerformanceAnalyzer {
private:
    clock_t startTime;
    clock_t endTime;

public:
    void startTimer();
    void stopTimer();
    double getElapsedTime() const;
};

#endif