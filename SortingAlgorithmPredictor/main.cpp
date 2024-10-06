#include <iostream>
#include "include/data_analysis.h"
#include "include/algorithms.h"
#include "include/recommendation_system.h"
#include "include/utility.h"

int main() {
    std::cout << "Welcome to the Sorting Algorithm Prediction/Recommendation System!" << std::endl;

    // Example dataset (can be replaced with user input)
    int dataset[] = {5, 2, 9, 1, 5, 6, 8, 10, 7, 14};
    int size = sizeof(dataset) / sizeof(dataset[0]);

    // Analyze the dataset
    DataFeatures features = analyzeData(dataset, size);

    // Recommend a sorting algorithm based on the analysis
    std::string recommendedAlgorithm = recommendAlgorithm(features);
    std::cout << "Recommended Sorting Algorithm: " << recommendedAlgorithm << std::endl;

    // Sort the dataset using the recommended algorithm and print the result
    if (recommendedAlgorithm == "Quick Sort (for larger datasets)") {
        quickSort(dataset, 0, size - 1);
    } else if (recommendedAlgorithm == "Insertion Sort (for small datasets)") {
        insertionSort(dataset, size);
    } else if (recommendedAlgorithm == "Insertion Sort (as the data is already sorted)") {
        insertionSort(dataset, size);
    }

    // Print the sorted dataset
    std::cout << "Sorted Dataset: ";
    for (int i = 0; i < size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
