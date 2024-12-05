#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

// Functions for std::vector<int>
void insertionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr, int low, int high);
void mergeSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& dataset, int left, int mid, int right); // Ensure this is here
void heapSort(std::vector<int>& arr);
void radixSort(std::vector<int>& arr);
int partition(std::vector<int>& arr, int low, int high);
void analyzeDataSet(const std::vector<int>& arr);

// Functions for int[]
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void heapSort(int arr[], int n);
void radixSort(int arr[], int n);

#endif // ALGORITHMS_H
