#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H

#include <vector>
#include <string>

// Struct to hold analyzed data features
struct DataFeatures {
    int datasetSize;
    float sortedness;
    int minValue;
    int maxValue;
    std::string recommendedAlgorithm;  // Added field to hold the recommendation
    std::string recommendationReason;   // Added field for reasoning
};

// Function to calculate sortedness of the dataset
float calculateSortedness(const std::vector<int>& dataset);

// Function to extract data features from the dataset
DataFeatures extractDataFeatures(const std::vector<int>& dataset);

// Function to recommend the best sorting algorithm based on analyzed data
DataFeatures analyze_dataset(const std::vector<int>& dataset);  // Change return type

#endif // DATA_ANALYSIS_H
