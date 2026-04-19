#include <stdio.h>
#include <string.h>

#define MAX 1000000

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

// Check matching pair
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Check balanced expression
int isBalanced(char* s) {
    top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else {
            if (top == -1)
                return 0;

            char popped = pop();
            if (!isMatchingPair(popped, ch))
                return 0;
        }
    }

    return top == -1;
}

// MAIN
int main() {
    char s[MAX];

    printf("Enter expression: ");
    scanf("%s", s);

    if (isBalanced(s))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
