#include "../include/data_analysis.h"
#include <vector>
#include <string>
#include <algorithm> // For std::max_element and std::min_element
#include <numeric>
#include <iostream>  // Include for std::cout

// Function to count inversions in the dataset
int countInversions(const std::vector<int>& dataset) {
    int inversions = 0;
    for (size_t i = 0; i < dataset.size(); i++) {
        for (size_t j = i + 1; j < dataset.size(); j++) {
            if (dataset[i] > dataset[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

// Function to calculate sortedness of the dataset
float calculateSortedness(const std::vector<int>& dataset) {
    int inversions = countInversions(dataset);
    int totalPairs = (dataset.size() * (dataset.size() - 1)) / 2; // n(n-1)/2
    return 1.0f - (static_cast<float>(inversions) / totalPairs); // Higher is better
}

// Function to extract data features from the dataset
DataFeatures extractDataFeatures(const std::vector<int>& dataset) {
    DataFeatures features;
    features.datasetSize = dataset.size();
    features.sortedness = calculateSortedness(dataset) * 100; // Convert to percentage
    features.minValue = *std::min_element(dataset.begin(), dataset.end());
    features.maxValue = *std::max_element(dataset.begin(), dataset.end());
    return features;  // Correctly return the DataFeatures struct
}

// Function to recommend the best sorting algorithm based on dataset analysis
DataFeatures analyze_dataset(const std::vector<int>& dataset) {
    DataFeatures features = extractDataFeatures(dataset);  // Extract features

    // Check if the dataset is already sorted
    if (features.sortedness == 100.0f) {
        std::cout << "The array is already sorted. No need to recommend a sorting algorithm." << std::endl;
        features.recommendedAlgorithm = "None";  // No algorithm recommended
        features.recommendationReason = "The dataset is already sorted, so no sorting is needed.";
        return features; // Return immediately, breaking the recommendation flow
    }

    // Default sorting recommendation logic
    features.recommendedAlgorithm = "Quick Sort";  // Default recommendation
    features.recommendationReason = "The dataset appears to be random and of a size where Quick Sort is efficient in most cases."; // Default reason

    int n = features.datasetSize;

    // Check if the dataset is small (suitable for Insertion Sort)
    if (n <= 10) {
        features.recommendedAlgorithm = "Insertion Sort";
        features.recommendationReason = "The dataset is small, which suits Insertion Sort's efficient handling of small datasets.";
        return features; // Return early
    }

    // Calculate the degree of sortedness
    if (features.sortedness >= 75) {
        features.recommendedAlgorithm = "Merge Sort";
        features.recommendationReason = "The dataset is mostly sorted, which Merge Sort handles efficiently with its stable nature.";
        return features; // Return early
    }

    // Check the range of elements in the dataset
    int range = features.maxValue - features.minValue;

    // If the range is large, recommend Heap Sort
    if (range > n * 10) {
        features.recommendedAlgorithm = "Heap Sort";
        features.recommendationReason = "The dataset has a large range, which Heap Sort handles efficiently with its in-place sorting.";
        return features; // Return early
    }

    // Check if all elements are non-negative and suitable for Radix Sort
    bool is_non_negative = std::all_of(dataset.begin(), dataset.end(), [](int x) { return x >= 0; });
    if (is_non_negative && range < 1000 && n > 20) {
        features.recommendedAlgorithm = "Radix Sort";
        features.recommendationReason = "The dataset contains non-negative integers in a suitable range, making Radix Sort a good choice.";
        return features; // Return early
    }

    // Return the filled DataFeatures struct
    return features;
}
