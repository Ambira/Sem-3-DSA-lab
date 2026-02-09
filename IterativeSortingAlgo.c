//Lab Exercise -11
//Iterative Sorting Algorithms - 1.Bubble Sort, 2.Selection Sort
//3. Insertion Sort, 4. Shell Sort 5. Exit 
//make it menu driven using functions for each sorting algorithm
//also crete two functions to inptut and display the array which can be shared by all sorting functions

#include <stdio.h>

#define MAX 100

void inputArray(int arr[], int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);
    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Bubble Sort completed.\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
    printf("Selection Sort completed.\n");
}

void insertionSort(int arr[], int n) {
int temp, i, j;
    for (i = 1; i < n; i++) {
         temp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
            arr[j + 1] = temp;
    }
    printf("Insertion Sort completed.\n");
}

void shellSort(int arr[], int n) {
int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf("Shell Sort completed.\n");
}

int main() {
    int arr[MAX], n = 0, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            inputArray(arr, &n);
            switch (choice) {
                case 1: bubbleSort(arr, n); break;
                case 2: selectionSort(arr, n); break;
                case 3: insertionSort(arr, n); break;
                case 4: shellSort(arr, n); break;
            }
            displayArray(arr, n);
        } else if (choice == 5) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
