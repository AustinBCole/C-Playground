//
//  C-Stack.c
//  
//
//  Created by Austin Cole on 7/11/19.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *storage;
    int length;
    int capacity;
    int original_capacity;
} Stack;

Stack *createStack(int capacity)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->storage = malloc(capacity * sizeof(int));
    newStack->length = 0;
    newStack->capacity = capacity;
    newStack->original_capacity = capacity;
    return newStack;
}

void destroyStack(Stack *stack)
{
    free(stack->storage);
    free(stack);
}

void push(Stack *stack, int value)
{
    stack->storage[stack->length] = value;
    stack->length = stack->length + 1;
    if (stack->length >= stack->capacity * .7) {
        stack->capacity = stack->capacity * 2;
        int *new_storage = malloc(stack->capacity * sizeof(int));
        for(int i = 0; i < stack->length; i++) {
            new_storage[i] = stack->storage[i];
        }
        *stack->storage = *new_storage;
        free(new_storage);
    }
}

int pop(Stack *stack)
{
    if (stack->length > 0) {
        stack->length = stack->length - 1;
        if (stack->length <= stack->capacity * .2) {
            stack->capacity = stack->capacity / 2;
            int *new_storage = malloc(stack->capacity * sizeof(int));
            for (int i = 0; i < stack->length; i++) {
                new_storage[i] = stack->storage[i];
            }
            *stack->storage = *new_storage;
            free(new_storage);
        }
        return stack->storage[stack->length];
    }
    return -1;
}

void push(Stack *stack, int value);
int pop(Stack *stack);
void destroyStack(Stack *stack);
Stack *createStack(int capacity);

int main(void)
{
    Stack *stack = createStack(4);
    push(stack, 2);
    push(stack, 4);
    push(stack, 7);
    push(stack, 88);
    for (int i = 0; i < stack->length; i++) {
        printf("At index %d, we have %d\n\n\n", i, stack->storage[i]);
    }
    printf("The stack's capacity should be 8. Its actual capacity is: %d\n\n\n", stack->capacity);
    printf("The stack's length should be 4. Its actual length is: %d\n\n\n", stack->length);
    pop(stack);
    pop(stack);
    pop(stack);
    for (int i = 0; i < stack->length; i++) {
        printf("At index %d, we have %d\n\n\n", i, stack->storage[i]);
    }
    printf("The stack's capacity should be 4. Its actual capacity is: %d\n\n\n", stack->capacity);
    printf("The stack's length should be 1. Its actual length is: %d\n\n\n", stack->length);
    
}
