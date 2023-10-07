#include <stdio.h>

struct Stack {
    int arraySize;
    int top;
    int array[100];
};

void push(struct Stack *s, int value);
char pop(struct Stack *s);

int main() {
    struct Stack first = {
            5,
            -1,
    };

    push(&first, 10);
    push(&first, 20);
    push(&first, 30);

    printf("Popped: %d\n", pop(&first));
    printf("Popped: %d\n", pop(&first));

    return 0;
}

void push(struct Stack *s, int value) {
    if (s->top == s->arraySize - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top += 1;
    s->array[s->top] = value;
}

char pop(struct Stack *s) {
    if (s->top > -1) {
        char value = s->array[s->top];
        s->top = s->top - 1;
        return value;
    }
}
