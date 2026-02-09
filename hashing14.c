//Lab 14
// Hashing
///1. Insert into hash table 2.Delete from hash table 3.Search in hash table 4.Display hash table
//also check collision and resolve it 

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10   // hash table size
int hashTable[SIZE];

// Initialize hash table with -1 (empty)
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Display hash table
void displayTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("[%d] : EMPTY\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

// Insert into hash table with collision resolution (linear probing)
void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    if (i == SIZE) {
        printf("Hash Table is full. Cannot insert %d.\n", key);
    } else {
        hashTable[(index + i) % SIZE] = key;
        printf("Inserted %d at index %d.\n", key, (index + i) % SIZE);
    }
}

// Search in hash table
void search(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i) % SIZE] == key) {
            printf("Element %d found at index %d.\n", key, (index + i) % SIZE);
            return;
        }
        i++;
    }
    printf("Element %d not found.\n", key);
}

// Delete from hash table
void delete(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i) % SIZE] == key) {
            hashTable[(index + i) % SIZE] = -1;  // mark as empty
            printf("Deleted element %d from index %d.\n", key, (index + i) % SIZE);
            return;
        }
        i++;
    }
    printf("Element %d not found. Cannot delete.\n", key);
}

int main() {
    int choice, key;
    initTable();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into Hash Table\n");
        printf("2. Delete from Hash Table\n");
        printf("3. Search in Hash Table\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                displayTable();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
