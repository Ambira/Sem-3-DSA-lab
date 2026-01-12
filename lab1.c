//to show stack operation where it is menu driven with push,pop, display and exit option
#define MAX 10
#include<stdio.h>
//structure
struct Stack{
int item[MAX];
int top;
};

// Function prototypes
void push(struct Stack *s);
void pop(struct Stack *s);
void display(struct Stack *s);

int main() {
    struct Stack s;
    s.top = -1;
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&s);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Push operation
void push(struct Stack *s) {
    int num;
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &num);
        s->top++;
        s->item[s->top] = num;
        printf("%d pushed onto stack.\n", num);
    }
}

// Pop operation
void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
    } else {
        printf("%d popped from stack.\n", s->item[s->top]);
        s->top--;
    }
}

// Display operation
void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->item[i]);
        }
        printf("\n");
    }
}
