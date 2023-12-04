#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize an empty stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    Stack stack;
    initialize(&stack);

    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            // If the character is a digit, convert it to an integer and push onto the stack
            push(&stack, postfix[i] - '0');
        } else {
            // If the character is an operator, pop the required number of operands,
            // perform the operation, and push the result back onto the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&stack, operand1 / operand2);
                    } else {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Invalid character in postfix expression: %c\n", postfix[i]);
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }

    // The final result is at the top of the stack
    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);

    // Removing newline character from the input
    size_t len = strlen(postfix);
    if (len > 0 && postfix[len - 1] == '\n') {
        postfix[len - 1] = '\0';
    }

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}
