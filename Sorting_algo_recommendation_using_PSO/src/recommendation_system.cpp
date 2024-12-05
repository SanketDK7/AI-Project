#include "../include/recommendation_system.h"
#include "../include/pso.h"
#include "../include/complexity_analysis.h"
#include <iostream>

std::string recommendAlgorithm(const DataFeatures& features) {
    // First, try to get the recommendation using PSO
    std::string recommendedAlgorithm = recommendAlgorithmUsingPSO(features);

    // If you want to maintain fallback rules as well, uncomment the following section
    /*
    if (features.sortedness > 80) {
        recommendedAlgorithm = "Insertion Sort";
    } else if (features.datasetSize > 1000 && features.sortedness < 50) {
        recommendedAlgorithm = "Merge Sort";
    } else if (features.datasetSize > 10000 && features.sortedness < 50) {
        recommendedAlgorithm = "Quick Sort";
    } else if (features.maxValue - features.minValue > 1000) {
        recommendedAlgorithm = "Heap Sort";
    } else if (features.datasetSize > 10000 && features.maxValue >= 0) {
        recommendedAlgorithm = "Radix Sort";
    } else {
        recommendedAlgorithm = "Quick Sort";
    }
    */

    // Display complexity information
    std::cout << "Recommended Algorithm: " << recommendedAlgorithm << std::endl;
   //displayComplexity(recommendedAlgorithm);

    return recommendedAlgorithm;
}
