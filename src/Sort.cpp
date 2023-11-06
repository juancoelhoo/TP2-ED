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
            break;

        case 'q':
            quickSort(AdjacencyList, 0, (VerticesNumber - 1));
            break;

        case 'm':
            mergeSort(AdjacencyList, 0, (VerticesNumber - 1));
            break;

        case 'p':
            heapSort(AdjacencyList, VerticesNumber);
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

void merge(Node** arr, int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto leftArray = new Node*[subArrayOne];
    auto rightArray = new Node*[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into arr[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]->color < rightArray[indexOfSubArrayTwo]->color) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else if (leftArray[indexOfSubArrayOne]->color == rightArray[indexOfSubArrayTwo]->color) {
            // If colors are the same, compare by vertex value
            if (leftArray[indexOfSubArrayOne]->val < rightArray[indexOfSubArrayTwo]->val) {
                arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(Node** arr, int const begin, int const end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void heapify(Node** arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && (arr[l]->color > arr[largest]->color || (arr[l]->color == arr[largest]->color && arr[l]->val > arr[largest]->val)))
        largest = l;

    if (r < n && (arr[r]->color > arr[largest]->color || (arr[r]->color == arr[largest]->color && arr[r]->val > arr[largest]->val)))
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Node** arr, int n) {
    // Build max-heap.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extracting elements from the heap.
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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


