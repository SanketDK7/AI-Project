#include "../include/complexity_analysis.h"
#include <iostream>

Complexity getAlgorithmComplexity(const std::string& algorithm) {
    Complexity complexity;
    if (algorithm == "Insertion Sort") {
        complexity.timeComplexityBest = "O(n)";
        complexity.timeComplexityAvg = "O(n^2)";
        complexity.timeComplexityWorst = "O(n^2)";
        complexity.spaceComplexity = "O(1)";
    } else if (algorithm == "Merge Sort") {
        complexity.timeComplexityBest = "O(n log n)";
        complexity.timeComplexityAvg = "O(n log n)";
        complexity.timeComplexityWorst = "O(n log n)";
        complexity.spaceComplexity = "O(n)";
    } else if (algorithm == "Quick Sort") {
        complexity.timeComplexityBest = "O(n log n)";
        complexity.timeComplexityAvg = "O(n log n)";
        complexity.timeComplexityWorst = "O(n^2)";
        complexity.spaceComplexity = "O(log n)";
    } else if (algorithm == "Heap Sort") {
        complexity.timeComplexityBest = "O(n log n)";
        complexity.timeComplexityAvg = "O(n log n)";
        complexity.timeComplexityWorst = "O(n log n)";
        complexity.spaceComplexity = "O(1)";
    } else if (algorithm == "Radix Sort") {
        complexity.timeComplexityBest = "O(nk)";
        complexity.timeComplexityAvg = "O(nk)";
        complexity.timeComplexityWorst = "O(nk)";
        complexity.spaceComplexity = "O(n + k)";
    } else if (algorithm == "Bubble Sort") {
        complexity.timeComplexityBest = "O(n)";
        complexity.timeComplexityAvg = "O(n^2)";
        complexity.timeComplexityWorst = "O(n^2)";
        complexity.spaceComplexity = "O(1)";
    }
    return complexity;
}

void displayComplexity(const std::string& algorithm) {
    Complexity complexity = getAlgorithmComplexity(algorithm);
    std::cout << "Algorithm: " << algorithm << std::endl;
    std::cout << "Time Complexity (Best): " << complexity.timeComplexityBest << std::endl;
    std::cout << "Time Complexity (Average): " << complexity.timeComplexityAvg << std::endl;
    std::cout << "Time Complexity (Worst): " << complexity.timeComplexityWorst << std::endl;
    std::cout << "Space Complexity: " << complexity.spaceComplexity << std::endl;
    std::cout << std::endl;
}
