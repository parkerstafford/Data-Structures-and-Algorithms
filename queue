#include <stdio.h>
#include <malloc.h>

struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
};

struct Que {
    struct LinkedListNode *front;
    struct LinkedListNode *back;
};

void enque(struct Que *que, int data);
int deque(struct Que *que);

int main() {
    struct Que que;
    que.front = NULL;
    que.back = NULL;

    enque(&que, 20);
    enque(&que, 30);

    printf("Dequed: %d\n", deque(&que));
    printf("Dequed: %d\n", deque(&que));

    return 0;
}

void enque(struct Que *que, int data) {
    struct LinkedListNode *node = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.");
        exit(1);
    }

    node->data = data;
    node->next = NULL;

    if (que->back == NULL) {
        que->front = node;
        que->back = node;
    } else {
        que->back->next = node;
        que->back = node;
    }
}

int deque(struct Que *que) {
    if (que->front == NULL) {
        fprintf(stderr, "Que is empty.");
        exit(1);
    }

    int data = que->front->data;
    struct LinkedListNode *temp = que->front;
    que->front = que->front->next;
    free(temp);

    if (que->front == NULL) {
        que->back = NULL;
    }

    return data;
}
