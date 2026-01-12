#include <stdio.h>
#include <limits.h>
#define MAX 5

struct item {
    int value;
    int priority;
};

struct PriorityQueue {
    struct item pr[MAX];
    int size;
};

void enqueue(struct PriorityQueue *pq) {
    int val, pri;
    if(pq->size >= MAX - 1) {
        printf("Priority Queue is full\n");
    }
    else {
        printf("Enter value: ");
        scanf("%d", &val);
        printf("Enter priority: ");
        scanf("%d", &pri);
        
        pq->size++;
        pq->pr[pq->size].value = val;
        pq->pr[pq->size].priority = pri;
        printf("Element %d with priority %d enqueued\n", val, pri);
    }
}

int peek(struct PriorityQueue *pq) {
    int highestPriority = INT_MIN;
    int ind = -1;
    
    for(int i = 0; i <= pq->size; i++) {
        if(highestPriority == pq->pr[i].priority && ind > -1 && 
           pq->pr[ind].value < pq->pr[i].value) {
            highestPriority = pq->pr[i].priority;
            ind = i;
        }
        else if(highestPriority < pq->pr[i].priority) {
            highestPriority = pq->pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue(struct PriorityQueue *pq) {
    if(pq->size == -1) {
        printf("Priority Queue is empty\n");
    }
    else {
        int ind = peek(pq);
        printf("Dequeued element: %d (priority: %d)\n", 
               pq->pr[ind].value, pq->pr[ind].priority);
        
        for(int i = ind; i < pq->size; i++) {
            pq->pr[i] = pq->pr[i + 1];
        }
        pq->size--;
    }
}

void display(struct PriorityQueue *pq) {
    if(pq->size == -1) {
        printf("Priority Queue is empty\n");
    }
    else {
        printf("Priority Queue elements:\n");
        printf("Value\tPriority\n");
        for(int i = 0; i <= pq->size; i++) {
            printf("%d\t%d\n", pq->pr[i].value, pq->pr[i].priority);
        }
    }
}

int main() {
    struct PriorityQueue pq;
    pq.size = -1;
    int choice;
    
    while(1) {
        printf("\n----- PRIORITY QUEUE MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                enqueue(&pq);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                if(pq.size == -1) {
                    printf("Priority Queue is empty\n");
                }
                else {
                    int ind = peek(&pq);
                    printf("Highest priority element: %d (priority: %d)\n", 
                           pq.pr[ind].value, pq.pr[ind].priority);
                }
                break;
            case 4:
                display(&pq);
                break;
            case 5:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}