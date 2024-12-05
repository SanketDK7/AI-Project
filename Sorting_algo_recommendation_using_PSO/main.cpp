#include <iostream>
#include <vector>
#include <fstream> // Include for file operations
#include "../include/data_analysis.h"
#include "../include/algorithms.h"
#include "../include/recommendation_system.h"
#include "../include/utility.h"
#include "../include/complexity_analysis.h"
#include <chrono>
#include <string>

void displayMenu() {
    std::cout << "\n========== MENU ==========\n";
    std::cout << "1. Analyze dataset and recommend sorting algorithm\n";
    std::cout << "2. Perform sorting based on recommendation\n";
    std::cout << "3. Exit\n";
    std::cout << "===========================\n";
    std::cout << "Enter your choice: ";
}

/*void askFeedback(const std::string& algo) {
    std::cout << "\nDid the recommended algorithm " << algo << " work well for your dataset? (yes/no): ";
    std::string feedback;
    std::cin >> feedback;
    if (feedback == "yes") {
        std::cout << "Great! The system learned from this feedback.\n";
    } else {
        std::cout << "Sorry to hear that! The system will improve in future versions.\n";
    }
}*/

int main() {
    std::cout << "====================================" << std::endl;
    std::cout << "Welcome to the Sorting Algorithm Prediction/Recommendation System!" << std::endl;
    std::cout << "====================================" << std::endl;

    char continueSystem = 'y';  // For AI-like feedback loop to repeat operations

    while (continueSystem == 'y') {
        // Open the input file
        std::ifstream inputFile("input.txt");
        if (!inputFile) {
            std::cerr << "Error opening input file!" << std::endl;
            return 1; // Exit if the file cannot be opened
        }

        // Take user input for the dataset from the file
        int size;
        inputFile >> size; // Read size from the file

        std::vector<int> dataset(size);  // Use vector to hold the dataset
        for (int i = 0; i < size; i++) {
            inputFile >> dataset[i]; // Read elements from the file
        }

        inputFile.close(); // Close the input file

        // Display the input dataset
        std::cout << "\nInput Dataset: [";
        for (int i = 0; i < size; i++) {
            std::cout << dataset[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;

        // Variables to hold the features and recommendation
        DataFeatures features;
        std::string recommendedAlgorithm;
        bool analyzed = false;

        while (true) {
            displayMenu();  // Show menu options

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    // Analyze the dataset
                    std::cout << "\nSystem Analysis:" << std::endl;
                    features = analyze_dataset(dataset);  // Updated function call
                    std::cout << "\n\nAnalyzing dataset..." << std::endl;
                    std::cout << "- Dataset Size: " << features.datasetSize << std::endl;
                    std::cout << "- Sortedness: " << features.sortedness << "%" << std::endl;
                    std::cout << "- Range: " << features.maxValue << " - " << features.minValue << " = " << (features.maxValue - features.minValue) << std::endl;

                    // Recommend a sorting algorithm based on the analysis using PSO
                    recommendedAlgorithm = recommendAlgorithm(features);
                   // std::cout << "\n\nRecommended Sorting Algorithm: " << recommendedAlgorithm << std::endl;

                    // Provide reasoning behind the recommendation
                    std::cout << "\nReason for Recommendation: ";
                    if (recommendedAlgorithm == "Insertion Sort") {
                        std::cout << "Insertion Sort is recommended because the dataset is small or mostly sorted." << std::endl;
                    } else if (recommendedAlgorithm == "Quick Sort") {
                        std::cout << "Quick Sort is recommended due to its efficiency for larger, unsorted datasets." << std::endl;
                    } else if (recommendedAlgorithm == "Merge Sort") {
                        std::cout << "Merge Sort is recommended for large datasets with significant unsortedness." << std::endl;
                    } else if (recommendedAlgorithm == "Heap Sort") {
                        std::cout << "Heap Sort is recommended for datasets with large value ranges." << std::endl;
                    } else if (recommendedAlgorithm == "Radix Sort") {
                        std::cout << "Radix Sort is optimal for datasets with non-negative integers and uniform distribution." << std::endl;
                    }
                    analyzed = true;  // Mark dataset as analyzed
                    break;
                }
                case 2: {
                    if (!analyzed) {
                        std::cout << "Please analyze the dataset first (option 1) before sorting." << std::endl;
                        break;
                    }

                    // Perform sorting based on the recommended algorithm (only print sorting steps now)
                    if (recommendedAlgorithm == "Insertion Sort") {
                        std::cout << "Sorting using Insertion Sort..." << std::endl;
                        auto start = std::chrono::high_resolution_clock::now();
                        insertionSort(dataset);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> executionTime = end - start;

                        // Print the sorted dataset
                        std::cout << "Sorted Array: [";
                        for (int i = 0; i < size; i++) {
                            std::cout << dataset[i];
                            if (i < size - 1) std::cout << ", ";
                        }
                        std::cout << "]" << std::endl;

                        // Print performance metrics
                        std::cout << "\nPerformance Metrics:" << std::endl;
                        std::cout << "Estimated Time Complexity: O(n^2)" << std::endl;
                        std::cout << "Execution Time: " << executionTime.count() << " seconds" << std::endl;

                    } else if (recommendedAlgorithm == "Quick Sort") {
                        std::cout << "Sorting using Quick Sort..." << std::endl;
                        auto start = std::chrono::high_resolution_clock::now();
                        quickSort(dataset, 0, size - 1);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> executionTime = end - start;

                        // Print the sorted dataset
                        std::cout << "Sorted Array: [";
                        for (int i = 0; i < size; i++) {
                            std::cout << dataset[i];
                            if (i < size - 1) std::cout << ", ";
                        }
                        std::cout << "]" << std::endl;

                        // Print performance metrics
                        std::cout << "\nPerformance Metrics:" << std::endl;
                        std::cout << "Estimated Time Complexity: O(n log n)" << std::endl;
                        std::cout << "Execution Time: " << executionTime.count() << " seconds" << std::endl;

                    } else if (recommendedAlgorithm == "Merge Sort") {
                        std::cout << "Sorting using Merge Sort..." << std::endl;
                        auto start = std::chrono::high_resolution_clock::now();
                        mergeSort(dataset, 0, size - 1);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> executionTime = end - start;

                        // Print the sorted dataset
                        std::cout << "Sorted Array: [";
                        for (int i = 0; i < size; i++) {
                            std::cout << dataset[i];
                            if (i < size - 1) std::cout << ", ";
                        }
                        std::cout << "]" << std::endl;

                        // Print performance metrics
                        std::cout << "\nPerformance Metrics:" << std::endl;
                        std::cout << "Estimated Time Complexity: O(n log n)" << std::endl;
                        std::cout << "Execution Time: " << executionTime.count() << " seconds" << std::endl;

                    } else if (recommendedAlgorithm == "Heap Sort") {
                        std::cout << "Sorting using Heap Sort..." << std::endl;
                        auto start = std::chrono::high_resolution_clock::now();
                        heapSort(dataset);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> executionTime = end - start;

                        // Print the sorted dataset
                        std::cout << "Sorted Array: [";
                        for (int i = 0; i < size; i++) {
                            std::cout << dataset[i];
                            if (i < size - 1) std::cout << ", ";
                        }
                        std::cout << "]" << std::endl;

                        // Print performance metrics
                        std::cout << "\nPerformance Metrics:" << std::endl;
                        std::cout << "Estimated Time Complexity: O(n log n)" << std::endl;
                        std::cout << "Execution Time: " << executionTime.count() << " seconds" << std::endl;

                    } else if (recommendedAlgorithm == "Radix Sort") {
                        std::cout << "Sorting using Radix Sort..." << std::endl;
                        auto start = std::chrono::high_resolution_clock::now();
                        radixSort(dataset);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> executionTime = end - start;

                        // Print the sorted dataset
                        std::cout << "Sorted Array: [";
                        for (int i = 0; i < size; i++) {
                            std::cout << dataset[i];
                            if (i < size - 1) std::cout << ", ";
                        }
                        std::cout << "]" << std::endl;

                        // Print performance metrics
                        std::cout << "\nPerformance Metrics:" << std::endl;
                        std::cout << "Estimated Time Complexity: O(n)" << std::endl;
                        std::cout << "Execution Time: " << executionTime.count() << " seconds" << std::endl;
                    }

                    //askFeedback(recommendedAlgorithm);  // Asking for user feedback
                    break;
                }
                case 3:
                    std::cout << "Exiting the system. Goodbye!" << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice! Please select a valid option." << std::endl;
            }
        }
        std::cout << "\nDo you want to continue? (y/n): ";
        std::cin >> continueSystem;  // Check if the user wants to continue
    }
    return 0;
}
