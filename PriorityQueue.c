// Priority queue where enqueue, dequeue, peek and display operations are performed
#include <stdio.h>
#define MAX 5

// Structure for priority queue
struct PQueue {
    int item[MAX];
    int priority[MAX];
    int size;
};

// Function prototypes
void enqueue(struct PQueue *pq);
void dequeue(struct PQueue *pq);
void peek(struct PQueue *pq);
void display(struct PQueue *pq);

int main() {
    struct PQueue pq;
    pq.size = 0;

    int choice;

    while (1) {
        printf("\n--- PRIORITY QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&pq);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                peek(&pq);
                break;
            case 4:
                display(&pq);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Enqueue: insert item with priority
void enqueue(struct PQueue *pq) {
    if (pq->size == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    int value, pr;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);
    printf("Enter priority (lower = higher priority): ");
    scanf("%d", &pr);

    int i = pq->size - 1;

    // Shift items to keep sorted by priority
    while (i >= 0 && pq->priority[i] > pr) {
        pq->item[i + 1] = pq->item[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }

    pq->item[i + 1] = value;
    pq->priority[i + 1] = pr;
    pq->size++;

    printf("Enqueued %d with priority %d\n", value, pr);
}

// Dequeue: remove highest priority item (lowest priority number)
void dequeue(struct PQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue Underflow! Nothing to dequeue.\n");
        return;
    }

    printf("Dequeued element: %d (Priority: %d)\n",
            pq->item[0], pq->priority[0]);

    for (int i = 0; i < pq->size - 1; i++) {
        pq->item[i] = pq->item[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }

    pq->size--;
}

// Peek: show highest-priority element without removing it
void peek(struct PQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Peek -> Value: %d  Priority: %d\n",
           pq->item[0], pq->priority[0]);
}

// Display
void display(struct PQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nPriority Queue Elements (highest priority first):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d  Priority: %d\n",
               pq->item[i], pq->priority[i]);
    }
}
