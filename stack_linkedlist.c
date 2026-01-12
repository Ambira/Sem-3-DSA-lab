//Lab 8 Stack as linked list
//Menu driven 1.Push 2.Pop 3.Display 4.Exit
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct node {
    int data;
    struct node *next;
};

typedef struct node node;

// Push operation
void push(node **top) {
    node *temp;
    int num;

    printf("Enter element to push: ");
    scanf("%d", &num);

    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->next = *top;
    *top = temp;

    printf("Pushed %d into stack\n", num);
}

// Pop operation
void pop(node **top) {
    if(*top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    node *temp = *top;
    printf("Popped element: %d\n", temp->data);
    *top = temp->next;
    free(temp);
}

// Display operation
void display(node *top) {
    if(top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");
    while(top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

// Main function (Menu Driven)
int main() {
    node *top = NULL;
    int choice;

    while(1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push(&top);
                break;

            case 2:
                pop(&top);
                break;

            case 3:
                display(top);
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
