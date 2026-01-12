//to show circular queue operation with enqueue, dequeue and display
#include <stdio.h>
#define MAX 10
//structure
struct CircularQueue {
    int item[MAX];
    int front;
    int rear;
};
//Function prototypes
void enqueue(struct CircularQueue *q);
void dequeue(struct CircularQueue *q);
void display(struct CircularQueue *q);

int main() {
    struct CircularQueue q;
    q.front = -1;
    q.rear = -1;
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
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
        //enqueue operation
void enqueue(struct CircularQueue *q){
    int num;
    if ((q->rear + 1) % MAX == q->front){
        printf("Circular Queue overflow!!\n");
        return;
    }
    else{
        printf("Enter elements to enqueue: ");
        scanf("%d", &num);
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->item[q->rear] = num;
        printf("%d enqueued to circular queue\n", num);
    }
}

//dequeue operation
void dequeue(struct CircularQueue *q){
    int num;
    if (q->front == -1){
        printf("Circular Queue underflow!!\n");
        return;
    }
    else{
        num = q->item[q->front];
        if (q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }
        else{
            q->front = (q->front + 1) % MAX;
        }
        printf("%d dequeued from circular queue\n", num);
    }
}
// Display operation
void display(struct CircularQueue *q){
    if (q->front == -1){
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->item[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}