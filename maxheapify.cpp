#include <iostream>
using namespace std;

class MaxHeapArray {
private:
    int *heap;
    int size;

    void maxHeapify(int i) {
        int left = 2 * i + 1; // left child index
        int right = 2 * i + 2; // right child index
        int largest = i; // Initialize largest as root

        // If left child is larger than current node
        if (left < size && heap[left] > heap[largest])
            largest = left;
        // If right child is larger than current largest
        if (right < size && heap[right] > heap[largest])
            largest = right;
        // If largest is not the current node
        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxHeapArray(int arr[], int n) {
        heap = arr;
        size = n;
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(i);
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    // Primitive Array Implementation
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    MaxHeapArray heapArray(arr, n);
    cout << "Heap using primitive array: ";
    heapArray.printHeap();
}