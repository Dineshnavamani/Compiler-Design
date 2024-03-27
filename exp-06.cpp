#include <stdio.h>
#include <ctype.h>

char input[100];
int pos = 0;

void error() {
    printf("Error in parsing input.\n");
}

void match(char expected) {
    if (input[pos] == expected) {
        pos++;
    } else {
        error();
    }
}

void F();
void T();
void E();

void F() {
    if (isdigit(input[pos])) {
        match(input[pos]);
    } else if (input[pos] == '(') {
        match('(');
        E();
        match(')');
    } else {
        error();
    }
}

void T() {
    F();
    while (input[pos] == '*') {
        match('*');
        F();
    }
}

void E() {
    T();
    while (input[pos] == '+') {
        match('+');
        T();
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    E();

    if (input[pos] == '\0') {
        printf("Input parsed successfully.\n");
    } else {
        error();
    }

    return 0;
}
