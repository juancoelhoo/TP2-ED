#ifndef SORT_HPP
#define SORT_HPP
#include "../include/Graph.hpp"


// Swap two integer values by reference
void swap(int& a, int& b);

// Swap two Node pointers to exchange elements in two arrays
void swap_neighbors(Node* a, Node* b);

// Sort an array of Node pointers using the Bubble Sort algorithm based on their 'color' attribute
void bubbleSort(Node** arr, int n);

void selectionSort(Node** arr, int n);

void insertionSort(Node** arr, int n);

int partition(Node** arr, int low, int high);

void quickSort(Node** arr, int low, int high);

void merge(Node** arr, int const left, int const mid, int const right);

void mergeSort(Node** arr, int const begin, int const end);

void heapify(Node** arr, int N, int i);

void heapSort(Node** arr, int N);

void myMethodSort(Node** arr, int const begin, int const end);


// Sort a list of nodes using the specified sorting method ('method') based on the Node attributes
// 'adjacencyList' is the list of nodes to be sorted, and 'verticesNumber' is the number of vertices in the graph
void sortMethodSelection(char method, Node** AdjacencyList, int VerticesNumber);


#endif