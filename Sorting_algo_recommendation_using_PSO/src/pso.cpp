#include "../include/pso.h"
#include "../include/complexity_analysis.h"
#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate fitness based on dataset features
float calculateFitness(const DataFeatures& features, const std::string& algorithm) {
    float fitness = 0.0;

    if(features.sortedness == 100)
    {
        return fitness;
    }
    // Example criteria for each sorting algorithm
    if (algorithm == "Insertion Sort") {
        fitness += (features.sortedness > 80) ? 1.0 : 0.0;
        fitness += (features.datasetSize < 1000) ? 1.0 : 0.0; // Favors smaller datasets
    } else if (algorithm == "Merge Sort") {
        fitness += (features.sortedness < 50) ? 1.0 : 0.0;
        fitness += (features.datasetSize > 1000 && features.datasetSize < 10000) ? 1.0 : 0.0; // Favors larger datasets
    } else if (algorithm == "Quick Sort") {
        fitness += (features.sortedness < 50) ? 1.0 : 0.0;
        fitness += (features.datasetSize > 10000) ? 1.0 : 0.0; // Favors larger datasets
    } else if (algorithm == "Heap Sort") {
        fitness += (features.maxValue - features.minValue > 1000) ? 1.0 : 0.0;
    } else if (algorithm == "Radix Sort") {
        fitness += (features.datasetSize > 10000 && features.maxValue >= 0) ? 1.0 : 0.0;
    }

    return fitness;
}

// Function to recommend the best sorting algorithm using PSO
std::string recommendAlgorithmUsingPSO(const DataFeatures& features) {
    std::vector<Particle> particles = {
        {"Insertion Sort", 0.0, 0.0, ""},
        {"Merge Sort", 0.0, 0.0, ""},
        {"Quick Sort", 0.0, 0.0, ""},
        {"Heap Sort", 0.0, 0.0, ""},
        {"Radix Sort", 0.0, 0.0, ""}
    };

    // Initialize the best global fitness
    float globalBestFitness = 0.0;
    std::string globalBestAlgorithm;

    // Iterate for a number of PSO iterations
    const int iterations = 100; // Adjust based on needs
    for (int iter = 0; iter < iterations; ++iter) {
        for (auto& particle : particles) {
            // Calculate fitness
            particle.fitness = calculateFitness(features, particle.algorithm);

            // Update best local fitness
            if (particle.fitness > particle.bestFitness) {
                particle.bestFitness = particle.fitness;
                particle.bestAlgorithm = particle.algorithm;
            }

            // Update global best fitness
            if (particle.fitness > globalBestFitness) {
                globalBestFitness = particle.fitness;
                globalBestAlgorithm = particle.algorithm;
            }
        }
    }

    std::cout << "Recommended Algorithm: " << globalBestAlgorithm << std::endl;
    displayComplexity(globalBestAlgorithm); // Show complexity details

    return globalBestAlgorithm;
}
