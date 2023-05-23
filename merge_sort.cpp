#include <iostream>

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    int temp[leftSize + rightSize];

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            temp[k++] = left[i++];
        } else {
            temp[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        temp[k++] = left[i++];
    }

    while (j < rightSize) {
        temp[k++] = right[j++];
    }

    for (int index = 0; index < k; index++) {
        arr[index] = temp[index];
    }
}

void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;
    }
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

int main() {
    int arr[] = {9, 5, 2, 7, 1, 8, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
