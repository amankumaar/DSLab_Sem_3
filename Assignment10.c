#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *Arr;};

struct Stack *createStack(int size) {
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack)); 
    sp->top = -1;
    sp->size = size;
    sp->Arr = (int *)malloc(sp->size * sizeof(int));
    return sp; 
    }
    
int isEmpty(struct Stack *sp) {
    return sp->top == -1; 
    }

char peek(struct Stack *sp) {
    return sp->Arr[sp->top]; 
    }
    
char pop(struct Stack *sp) {
    if (!isEmpty(sp))
    return sp->Arr[sp->top--];
    return '$'; 
    }

void push(struct Stack *sp, char p) {
    sp->Arr[++sp->top] = p; 
    }

int is_operand(char ch) {
        return(ch>= 'a' &&ch<= 'z')||(ch>= 'A' &&ch<= 'Z');
        }

int precedence(char ch) {
    switch (ch) {
        case '+':
        return 1; 
        case '-':
        return 1; 
        case '*':
        return 2; 
        case '/':
        return 2; 
        case '^':
        return 3; 
        }
        return -1; 
        }

int infixToPostfix(char *exp)
{
    int i, k;
    struct Stack *sp = createStack(strlen(exp)); 
    for (i = 0, k = -1; exp[i]; ++i)
{
    if (is_operand(exp[i]))
    exp[++k] = exp[i]; 
    else if (exp[i] == '(')
    push(sp, exp[i]); 
    else if (exp[i] == ')') 
    {
        while (!isEmpty(sp) && peek(sp) != '(') 
        exp[++k] = pop(sp);
        if (!isEmpty(sp) && peek(sp) != '(') 
        return -1;
        else
        pop(sp);
        }
        else
        {
            while (!isEmpty(sp) && precedence(exp[i]) <= precedence(peek(sp)))
            exp[++k] = pop(sp); 
            push(sp, exp[i]);
            } 
        }
        while (!isEmpty(sp)) exp[++k] = pop(sp);
        exp[++k] = '\0';
        printf("%s\n", exp);
}
            
int main() {
    char exp[60];
    printf("\nEnter Expression :\n"); 
    scanf("%s",exp); 
    infixToPostfix(exp);
    return 0;
}