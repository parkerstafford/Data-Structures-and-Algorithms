#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insertAtBeginning(int data);
struct node* linkedListInsert(struct node* head, int index, int data);

int main() {
    struct node one = {
            2,
            NULL
    };
    struct node two = {
            3,
            NULL
    };

    struct node* newHead = linkedListInsert(&one, 0, 3);
    struct node* newNode = linkedListInsert(&one, 1, 3);


    printf("Address of newHead's next: %p\n", (void*)(newHead->next));
    printf("Address of newNode: %p\n", (void*)(newNode));

    return 0;
}

struct node* linkedListInsert(struct node* head, int index, int data) {
    if (index == 0) {
        struct node* newHead = (struct node*)malloc(sizeof(struct node));
        if (newHead == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }
        newHead->data = data;
        newHead->next = head;
        return newHead;
    }

    struct node* current = head;
    struct node* previous = NULL;
    int count = 0;

    while (count < index && current != NULL) {
        previous = current;
        current = current->next;
        count = count + 1;
    }

    if (count < index) {
        printf("Invalid index error.\n");
        return head;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = previous->next;
    previous->next = newNode;

    return head;
}

struct node* insertAtBeginning(int data) {
    struct node* lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;

    return lk;
}

struct node* linkedListLookup(struct node* head, int elementNumber) {
    struct node* current = head;
    int count = 0;

    while (count < elementNumber && current != NULL) {
        current = current->next;
        count += 1;
    }
    return current;
}

struct node* linkedListDelete(struct node* head, int index) {
    if (head == NULL) {
        return NULL;
    }

    if (index == 0) {
        struct node* newHead = head->next;
        head->next = NULL;
        free(head);
        return newHead;
    }

    struct node* current = head;
    struct node* previous = NULL;
    int count = 0;

     while (count < index && current != NULL) {
         previous = current;
         current = current->next;
         count++;
     }

     if (current != NULL) {
         previous->next = current->next;
         current->next = NULL;
     } else {
         fprintf(stderr, "Invalid index");
     }

     return head;
}
