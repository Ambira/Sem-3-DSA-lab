#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Add at Beginning
void addBeg(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("Inserted %d at Beginning\n", val);
}

// Add at End
void addEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    }
    else {
        struct Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at End\n", val);
}

// Add at Specified Position
void addPos(int val, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if(pos == 0 || head == NULL) {
        newNode->prev = NULL;
        newNode->next = head;
        if(head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("Inserted %d at Position %d\n", val, pos);
        return;
    }

    struct Node *temp = head;
    for(int i=0; i<pos-1 && temp->next!=NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Inserted %d at Position %d\n", val, pos);
}

// Delete Beginning
void delBeg() {
    if(head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    printf("Deleted %d from Beginning\n", temp->data);
    free(temp);
}

// Delete End
void delEnd() {
    if(head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node *temp = head;

    if(temp->next == NULL) { // Single node
        printf("Deleted %d from End\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from End\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Delete at Position
void delPos(int pos) {
    if(head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node *temp = head;

    if(pos == 0) {
        delBeg();
        return;
    }

    for(int i=0; i<pos && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    printf("Deleted %d from Position %d\n", temp->data, pos);

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

// Display List
void display() {
    if(head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver Code - MENU
int main() {
    int choice, val, pos;

    while(1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Add at Beginning\n2. Add at End\n3. Add at Position\n");
        printf("4. Delete Beginning\n5. Delete End\n6. Delete Position\n");
        printf("7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                addBeg(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                addEnd(val);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                addPos(val, pos);
                break;

            case 4:
                delBeg();
                break;

            case 5:
                delEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                delPos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
}
