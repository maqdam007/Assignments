#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top >= MAX_SIZE - 1;
}
#include <stddef.h>
// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = value;
    } else {
        printf("Stack is full. Cannot push.\n");
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value
    }
}