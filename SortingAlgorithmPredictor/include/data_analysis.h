#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H

struct DataFeatures {
    int datasize;
    bool isSorted;
    // Add more features as needed
};

// Function to analyze the dataset and return its features
DataFeatures analyzeData(int* dataset, int size);

#endif // DATA_ANALYSIS_H
