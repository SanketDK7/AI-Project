#ifndef COMPLEXITY_ANALYSIS_H
#define COMPLEXITY_ANALYSIS_H

#include <string>

struct Complexity {
    std::string timeComplexityBest;
    std::string timeComplexityAvg;
    std::string timeComplexityWorst;
    std::string spaceComplexity;
};

Complexity getAlgorithmComplexity(const std::string& algorithm);
void displayComplexity(const std::string& algorithm);

#endif // COMPLEXITY_ANALYSIS_H
