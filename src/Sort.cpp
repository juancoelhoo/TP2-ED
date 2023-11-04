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
        
        case 'i':
            insertionSort(AdjacencyList, VerticesNumber);

        case 'q':
            quickSort(AdjacencyList, 0, (VerticesNumber - 1));
        
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

    for (i = 0; i < n - 1; i++) 
    {
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

void insertionSort(Node** arr, int n) {
    int i, j;
    Node* key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Compare based on color and, if equal, based on value
        while (j >= 0 && (arr[j]->color > key->color || (arr[j]->color == key->color && arr[j]->val > key->val))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(Node** arr, int low, int high) {
    // Choose the pivot
    Node* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (arr[j]->color < pivot->color || (arr[j]->color == pivot->color && arr[j]->val < pivot->val)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Node** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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


