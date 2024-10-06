#include "../include/data_analysis.h"

DataFeatures analyzeData(int* dataset, int size) {
    DataFeatures features;
    features.datasize = size;

    // Check if the dataset is sorted
    features.isSorted = true;
    for (int i = 1; i < size; ++i) {
        if (dataset[i] < dataset[i - 1]) {
            features.isSorted = false;
            break;
        }
    }

    return features;
}
