//Menu driven program for Linear Queue 
#include <stdio.h>
#define MAX 10
//structure
struct Queue {
    int item[MAX];
    int front;
    int rear;
};

//Function prototypes
void enqueue(struct Queue *q);
void dequeue(struct Queue *q);  
void display(struct Queue *q);

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    int choice;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Enqueue operation
void enqueue(struct Queue *q){
    int num;
    if (q->rear == MAX - 1){
        printf("Queue overflow!!\n");
        return;
    }
    else{
        printf("Enter elements to enqueue: ");
        scanf("%d", &num);
        if (q->front == -1)
            q->front = 0;

        q->rear++;
        q->item[q->rear] = num;

        printf("%d enqueued to queue.\n", num);
    }
}
    //dequeue operation
    void dequeue(struct Queue *q){
    if (q->front == -1 || q->front > q->rear){
        printf("Queue underflow!!\n");
        return;
    }
    else{
        int dequeuedElement = q->item[q->front];
        q->front++;
        printf("%d dequeued from queue.\n", dequeuedElement);
    }
}


// Display operation
void display(struct Queue *q){
    if (q->front == -1 || q->front > q->rear){
        printf("Queue is empty!\n");
        return;
    }
    else{
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++){
            printf("%d ", q->item[i]);
        }
        printf("\n");
    }
}