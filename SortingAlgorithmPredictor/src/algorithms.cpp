#include "../include/algorithms.h"
#include <algorithm>

// Implementation of Quick Sort
void quickSort(int* dataset, int left, int right) {
    if (left < right) {
        int pivot = dataset[(left + right) / 2];
        int index = partition(dataset, left, right, pivot);
        quickSort(dataset, left, index - 1);
        quickSort(dataset, index, right);
    }
}

// Partition function for Quick Sort
int partition(int* dataset, int left, int right, int pivot) {
    while (left <= right) {
        while (dataset[left] < pivot) left++;
        while (dataset[right] > pivot) right--;
        if (left <= right) {
            std::swap(dataset[left], dataset[right]);
            left++;
            right--;
        }
    }
    return left;
}

// Implementation of Insertion Sort
void insertionSort(int* dataset, int size) {
    for (int i = 1; i < size; i++) {
        int key = dataset[i];
        int j = i - 1;

        while (j >= 0 && dataset[j] > key) {
            dataset[j + 1] = dataset[j];
            j--;
        }
        dataset[j + 1] = key;
    }
}

// Implementation of Merge Sort
void mergeSort(int* dataset, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(dataset, left, mid);
        mergeSort(dataset, mid + 1, right);
        merge(dataset, left, mid, right);
    }
}

// Merge function for Merge Sort
void merge(int* dataset, int left, int mid, int right) {
    // Implementation of merging logic
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = dataset[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = dataset[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            dataset[k] = leftArray[i];
            i++;
        } else {
            dataset[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        dataset[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        dataset[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}
