#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// Function prototypes for sorting algorithms
void quickSort(int* dataset, int left, int right);
void mergeSort(int* dataset, int left, int right);
void insertionSort(int* dataset, int size);
int partition(int* dataset, int left, int right, int pivot);
void merge(int* dataset, int left, int mid, int right);

#endif // ALGORITHMS_H
