//LAB exercise 13
//Searching Algorithm
//Menu driven: 1.Liner Search 2.Binary Search 3.Exit

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to input array
void inputArray(int arr[], int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);
    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array
void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Linear Search
void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i);
            return;
        }
    }
    printf("Element %d not found.\n", key);
}

// Binary Search (Iterative)
void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element %d found at index %d.\n", key, mid);
            return;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element %d not found.\n", key);
}

int main() {
    int arr[MAX], n = 0, choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                displayArray(arr, n);
                printf("Enter element to search: ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;

            case 2:
                inputArray(arr, &n);
                displayArray(arr, n);
                printf("Enter element to search: ");
                scanf("%d", &key);
                binarySearch(arr, n, key);
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
