#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int arraySize;
    int top;
    int* array;
};

struct Stack* createStack(int arraySize) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arraySize = arraySize;
    stack->top = -1;
    stack->array = (int*)malloc(arraySize * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int value) {
    if (stack->top == stack->arraySize - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

int pop(struct Stack* stack) {
    if (stack->top > -1) {
        int value = stack->array[stack->top];
        stack->top--;
        return value;
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int main() {
    struct Stack* first = createStack(5);

    push(first, 10);
    push(first, 20);
    push(first, 30);

    printf("Popped: %d\n", pop(first));
    printf("Popped: %d\n", pop(first));

    free(first->array);
    free(first);

    return 0;
}
