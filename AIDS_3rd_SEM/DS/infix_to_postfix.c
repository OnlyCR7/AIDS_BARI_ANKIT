#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char arr[MAX_SIZE];
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
void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to get the top element of the stack without popping it
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0; // Assuming '(' has the lowest precedence
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initialize(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == ' ' || infix[i] == '\t') {
            // Skip whitespaces
            i++;
        } else if (isalnum(infix[i])) {
            // If the character is an operand, add it to the postfix expression
            postfix[j++] = infix[i++];
        } else if (isOperator(infix[i])) {
            // If the character is an operator, pop operators from the stack
            // until the stack is empty or the top operator has lower precedence
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            // Push the current operator onto the stack
            push(&stack, infix[i++]);
        } else if (infix[i] == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            // If the character is a closing parenthesis, pop operators from the stack
            // and add them to the postfix expression until an opening parenthesis is encountered
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            // Pop the opening parenthesis from the stack
            pop(&stack);
            i++;
        } else {
            // Invalid character in the infix expression
            printf("Invalid character: %c\n", infix[i]);
            exit(EXIT_FAILURE);
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    // Removing newline character from the input
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
