#include <stdio.h>
#include <stdlib.h>

typedef struct CList {
    int data;
    struct CList *next;
} node;

void addAtBeg(node **head, node **tail) {
    int num;
    node *temp;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = (node*) malloc(sizeof(node));
    temp->data = num;
    temp->next = temp;

    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    } else {
        temp->next = *head;
        *head = temp;
        (*tail)->next = *head;
    }
    printf("Added %d at the beginning.\n", num);
}

void addAtEnd(node **head, node **tail) {
    int num;
    node *temp;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = (node*) malloc(sizeof(node));
    temp->data = num;
    temp->next = temp;

    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    } else {
        (*tail)->next = temp;
        *tail = temp;
        (*tail)->next = *head;
    }
    printf("Added %d at the end.\n", num);
}

void delFromBeg(node **head, node **tail) {
    node *temp;
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    temp = *head;
    if (*head == *tail) { // Only one node
        *head = NULL;
        *tail = NULL;
    } else {
        *head = (*head)->next;
        (*tail)->next = *head;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delFromEnd(node **head, node **tail) {
    node *temp, *p;
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (*head == *tail) { // Only one node
        temp = *head;
        *head = NULL;
        *tail = NULL;
    } else {
        p = *head;
        while (p->next != *tail) {
            p = p->next;
        }
        temp = *tail;
        p->next = *head;
        *tail = p;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display(node *head) {
    node *p;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    p = head;
    printf("Circular Linked List elements:\n");
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(back to head %d)\n", head->data);
}

int main() {
    node *head = NULL, *tail = NULL;
    int choice, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Add at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAtBeg(&head, &tail); break;
            case 2: addAtEnd(&head, &tail); break;
            case 3: 
                printf("Enter position: ");
                scanf("%d", &pos);
                addAtPos(&head, &tail, pos);
                break;
            case 4: delFromBeg(&head, &tail); break;
            case 5: delFromEnd(&head, &tail); break;
            case 6: 
                printf("Enter position: ");
                scanf("%d", &pos);
                delAtPos(&head, &tail, pos);
                break;
            case 7: display(head); break;
            case 8: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
