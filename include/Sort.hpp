#ifndef SORT_HPP
#define SORT_HPP
#include "../include/Graph.hpp"

// Swap two integer values by reference
void swap(int& a, int& b);

// Swap two Node pointers to exchange elements in two arrays
void swap_neighbors(Node* a, Node* b);

// Sort an array of Node pointers using the Bubble Sort algorithm based on their 'color' attribute
void bubbleSort(Node** arr, int n);

// Sort an array of Node pointers using the Selection Sort algorithm
void selectionSort(Node** arr, int n);

// Sort an array of Node pointers using the Insertion Sort algorithm
void insertionSort(Node** arr, int n);

// Partition an array of Node pointers for the Quick Sort algorithm and return the partition index
int partition(Node** arr, int low, int high);

// Sort an array of Node pointers using the Quick Sort algorithm
void quickSort(Node** arr, int low, int high);

// Merge two sorted subarrays within an array during Merge Sort
void merge(Node** arr, int const left, int const mid, int const right);

// Sort an array of Node pointers using the Merge Sort algorithm
void mergeSort(Node** arr, int const begin, int const end);

// Organize a binary heap within an array for the Heap Sort algorithm
void heapify(Node** arr, int N, int i);

// Sort an array of Node pointers using the Heap Sort algorithm
void heapSort(Node** arr, int N);

// Your custom sorting method, which sorts an array of Node pointers based on specific criteria
void myMethodSort(Node** arr, int const begin, int const end);

// Select and apply a sorting method based on the provided character code 'method' to sort an array of Node pointers
void sortMethodSelection(char method, Node** AdjacencyList, int VerticesNumber);

#endif
