#include<stdio.h>
#include <stdlib.h>
struct Stack
{
    char *Arr;
    int size;
    int top; 
};

int isEmpty(struct Stack* sp)
{ 
    return sp ->top == -1;
}

void push(struct Stack* sp, int val)
{
        sp->top++;
        sp->Arr[sp->top] = val;
}

char pop(struct Stack* sp) 
{ 
    char c = sp->Arr[sp->top]; sp->top--;
    return c;
}

int palindrome(char str[]) 
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack)); 
    sp->Arr = (char *)malloc(100 * (sizeof(char)));
    sp->size = 100;
    sp->top = -1;
    for (int i = 0; str[i] != '\0'; i++) push(sp, str[i]);
    int i = 0;
    while (!isEmpty(sp)) {
        char c = pop(sp);
        if (c == str[i]) i++;
        else
            return 0;
}
return 1; 
}

int main(){
    char str[90]; 
    printf("\nEnter String:"); 
    scanf("%s", str);
    if (palindrome(str))
    printf("Given string is a palindrome\n"); 
    else
    printf("Given string is not a palindrome\n");
    return 0;
}