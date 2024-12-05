#ifndef PSO_H
#define PSO_H

#include "data_analysis.h"
#include <string>
#include <vector>

struct Particle {
    std::string algorithm; // Name of the sorting algorithm
    float fitness;         // Current fitness score
    float bestFitness;     // Best fitness achieved by the particle
    std::string bestAlgorithm; // Best algorithm found by the particle
};

float calculateFitness(const DataFeatures& features, const std::string& algorithm);
std::string recommendAlgorithmUsingPSO(const DataFeatures& features);

#endif // PSO_H
