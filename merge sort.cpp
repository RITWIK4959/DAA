#include <stdio.h>
#include <string.h>

#define SIZE 5

// Function to merge two halves
void merge(const char *arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays for storing pointers
    const char *leftArray[n1], *rightArray[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = left; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (strcmp(leftArray[i], rightArray[j]) <= 0) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray, if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray, if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(const char *arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(const char *arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Array of strings
    const char *arr[SIZE] = {"apple", "banana", "grape", "cherry", "date"};

    printf("Original array:\n");
    printArray(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);

    printf("\nSorted array:\n");
    printArray(arr, SIZE);

    return 0;
}
