//Lab 9 Queue as linked list
//Menu driven 1.Enqueue 2.Dequeue 3.Display 4.Exit
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct node {
    int data;
    struct node *next;
};

typedef struct node node;

// Enqueue operation
void enqueue(node **front, node **rear) {
    node *temp;
    int num;

    printf("Enter element to enqueue: ");
    scanf("%d", &num);

    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;

    if(*front == NULL) {   // Queue is empty
        *front = temp;
        *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }

    printf("Enqueued %d into queue\n", num);
}

// Dequeue operation
void dequeue(node **front, node **rear) {
    if(*front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    node *temp = *front;
    printf("Dequeued element: %d\n", temp->data);

    *front = temp->next;
    if(*front == NULL)   // Queue becomes empty
        *rear = NULL;

    free(temp);
}

// Display operation
void display(node *front) {
    if(front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");
    while(front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

// Main function (Menu Driven)
int main() {
    node *front = NULL;
    node *rear = NULL;
    int choice;

    while(1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue(&front, &rear);
                break;

            case 2:
                dequeue(&front, &rear);
                break;

            case 3:
                display(front);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
