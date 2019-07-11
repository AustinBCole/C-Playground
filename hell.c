//
//  hell.c
//  
//
//  Created by Austin Cole on 7/9/19.
//

#include <stdio.h>
#include <math.h>

// I have to call the function up here before I can call it in the main function
int intsqrt(int i);

typedef struct Person {
    char *name;
    int age;
    float weight;
} Person;

typedef struct Stack {
    int *storage:
    int length;
    int capacity;
    int original_capacity;
} Stack;

Stack *createStack(int capacity)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->storage = malloc(capacity * sizeof(int))
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
    if (stack.length >= stack.capacity * .7) {
        int new_capacity = stack->capacity * 2;
        int new_storage = malloc(new_capacity * sizeof(int))
        for (int i = 0; i < stack->length; i++) {
            new_storage[i] = stack->storage[i];
        }
        *stack->storage = new_storage;
    }
}

int pop(Stack *stack, int value)
{
    if (stack->length > 0) {
        if (stack->length <= stack.capacity * .2) {
            if (stack->length > stack->original_capacity) {
                int new_capacity = stack->capacity / 2;
                int new_storage = malloc(new_capacity * sizeof(int))
                for (int i = 0; i < stack->length; i++) {
                    new_storage[i] = stack->storage[i];
                }
            }
        }
        stack->length = stack->length - 1;
        return stack->storage[stack->length];
    }
}



int main(void)
{
    printf("Hello, world!\n");

    int result = intsqrt(4);
    
    // Here I am declaring a pointer property. The pointer points to the address of the value, in this case a string.
    char *str = "I'm a string!";
    // Next I am printing out the ADDRESS that the pointer holds. The pointer only holds the address of the value, not the value. In this case the address in memory would be printed, like when I am printing an object in swift or obj-C.
    printf("This is the address that the pointer is pointing to in memory: %p\n", str);
    // Next I am printing out the VALUE located at the ADDRESS that the pointer holds. The asterisk is what tells the compiler that I want the VALUE at the ADDRESS and not the ADDRESS itself. The asterisk here is DEREFERENCING the pointer, which means it's getting the value that the pointer is pointing to. The entire string WILL NOT be printed. Only the FIRST CHARACTER of the string will be printed. I would need to use POINTER ARITHMETIC to print out the string this way.
    printf("This is the first character of the string, located at the address that the pointer is pointing to: %c\n", *str);
    // Next I am printing out the entire string by using the string placeholder and passing the pointer to the printf() function. The function will begin at the address that is found with the pointer and will iterate through all of the characters it finds, printing them out until it reaches the terminating character \0.
    printf("This is the entire string, the first character of which is located at the address that the pointer is pointing to: %s\n", str);
    
    return 0;
}

// This function takes an int and returns the square root of the int as a double
int intsqrt(int i)
{
    double d = i, result;
    result = sqrt(d);
    printf("The square root of %lf is %lfn\n", d, result);
    return result;
}


int x = 1, y = 2, z[10]; // x and y represent integers, z represents an array of integers that has a capacity of 10
int *ip; // ip is a pointer to an integer type

ip = &x;         // What is ip here? ip here is pointing now to the address of 'x'. The ampersand here is basically saying "address of __", in this case "addres of x".
y = *ip;          // What is y here? y here is the value of ip. ip is pointed to x, so the value of y would now be the value of x.
*ip = 0;          // What is ip here now? What is x now? The value located at the address ip points to is now changed to 0. The actual value at that address has changed, the address itself remains the same.
ip = &z[0];    // What is ip now? ip now points to the address of the 0th element of the array held by z. In other words, the value of ip IS THE ADDRESS of the 0th element of z.
