#include "../include/Sort.hpp"

void sortMethodSelection(char method, Node** AdjacencyList, int VerticesNumber){
        switch (method)
        {
        case 'b':
            bubbleSort(AdjacencyList, VerticesNumber);
            break;

        case 's':
            selectionSort(AdjacencyList, VerticesNumber);
            break;
        
        default:
            break;
        }
}

void bubbleSort(Node** arr, int n)
{
	int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j]->color > arr[j + 1]->color) {
                swap_neighbors(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void selectionSort(Node**arr, int n)
{
     int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j]->color < arr[min_idx]->color || (arr[j]->color == arr[min_idx]->color && arr[j]->val < arr[min_idx]->val)) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap_neighbors(arr[min_idx], arr[i]);
        }
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_neighbors(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}


