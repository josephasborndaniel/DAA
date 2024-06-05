#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
    
    int top = -1;
    int size = strlen(s);
    char stack[size];

    
    for (int i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            
           stack[++top] = s[i];
        } else {
            
            if ((s[i] == ')' && stack[top] == '(') ||
                (s[i] == '}' && stack[top] == '{') ||
                (s[i] == ']' && stack[top] == '[')) {
                top--;
            } else {
                return false; 
            }
        }
    }

    return top == -1; 
}

int main() {
    char input[] = "{[()]}";
    
    if (isValid(input)) {
        printf("The input string is valid.\n");
    } else {
        printf("The input string is invalid.\n");
    }

    return 0;
}
