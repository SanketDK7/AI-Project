#include "../include/recommendation_system.h"

std::string recommendAlgorithm(const DataFeatures& features) {
    // Simple logic to recommend sorting algorithms based on dataset features
    if (features.isSorted) {
        return "Insertion Sort (as the data is already sorted)";
    }
    if (features.datasize < 10) {
        return "Insertion Sort (for small datasets)";
    }
    return "Quick Sort (for larger datasets)";
}
