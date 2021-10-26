#include<stdio.h> 
#include<stdlib.h>

struct Stack
{
    float *Arr;
    int top;
    int size;
};

int isfull(struct Stack *sp) 
{
    return (sp->top==sp->size-1); 
    }

int isempty(struct Stack *sp) 
{
    return sp->top==-1; 
    }

void push(struct Stack *sp,float x) 
{
    if(isfull(sp)) {
        printf("Stack Overflow! Cannot push %f to the stack!\n", x);
        return; 
        }
        sp->top++;
        sp->Arr[sp->top]=x; 
        }

void pop(struct Stack *sp) 
{
    if(isempty(sp)) 
    {
        printf("Empty Stack!\n");
        return; }
        sp->top--; }
        
int is_operand(char ch) {
    if (ch == '+' || ch == '/' || ch == '*' || ch == '-') 
    return 0;
    return 1; }

float eval(char ch, int a, int b) {
    switch (ch) {
        case '+':
        return a + b;
        break; 
        case '-':
        return a - b;
        break;
        case '*':
        return a * b;
        break; 
        case '/':
        return a / (float)b;
        break; }
        return -1; }
        
float eval_of_postfix(char post[]) {
    struct Stack *sp=(struct Stack*)malloc(sizeof(struct Stack)); 
    sp->Arr=(float *)malloc(sizeof(float)*100);
    sp->top=-1;
    sp->size=100;
    for (int i = 0; post[i]!='\0'; i++) {
        if (is_operand(post[i])) push(sp, post[i] - 48);
        else
        {
            int b = sp->Arr[sp->top]; 
            pop(sp);
            int a = sp->Arr[sp->top]; 
            pop(sp);
            float x = eval(post[i], a, b);
            push(sp,x); }
            }
            return sp->Arr[sp->top]; 
            }

int main() {
    char post[60];
    printf("Enter a Postfix expression: \n");
    scanf("%s",post);
    printf("The Output is: %f\n",eval_of_postfix(post)); 
    return 0;
}