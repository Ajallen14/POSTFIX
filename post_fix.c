#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int top=-1;
int s[MAX];


void infixToPostfix(char infix[], char postfix[]){

}

void push(char symbol){
    if(top >= MAX-1){
        printf("Stack Overflow \n");
        return;
    }
    s[++top] = symbol;
}

char pop(){
    if(isEmpty()){
        printf("Stack Underflow \n");
        return;
    }
    return s[top--];
}

int isEmpty(){
    return top == -1;
}

int precedence(char symbol){
    switch (symbol)
    {
    case '(' :
        return 0;
    case '+' :
    case '_' :
        return 1;
    case '*' :
    case '/' :
    case '%' :
        return 2;
    case '^' :
        return 3;
    default:
        return -1; //Returns a -ve value for non-operators
    }
}


void main(){
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression : ");
    fgets(infix, sizeof(infix), stdin);

    //TO REMOVE NEWLINE CHARACTER FROM THE INPUT STRING
    size_t len = strlen(infix);
    if(len > 0 && infix[len -1] =='\n'){
        infix[len -1] = '\0';
    }

    infixToPostfix(infix, postfix);
    printf("Postfix expression is :\n", postfix);

}