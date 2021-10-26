#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int *Arr;
    int size;
    int top; 
};

int isEmpty(struct Stack* sp)
{
    if(sp ->top == -1){
        return -1;
    }
    else{
        return 0;
    }
};

int isFull(struct Stack* sp)
{
    if(sp ->top == sp->size-1){
        return -1;
    }
    else{
        return 0;
    }
};

void display(struct Stack *sp) 
{
    printf("Stack elements are:\n"); 
    for (int i = sp->top; i >= 0; i--)
    printf("%d ", sp->Arr[i]); 
    printf("\n");
}

void push(struct Stack* sp, int val){
    if(isFull(sp)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        sp->top++;
        sp->Arr[sp->top] = val;
        printf("Element pushed successfully!\n"); 
    }
}

int pop(struct Stack* sp){
    if(isEmpty(sp)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = sp->Arr[sp->top];
        sp->top--;
        printf("Element %d pushed successfully!\n", val);
        return val;
    }
}

int main(){
    struct Stack *sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->Arr = (int *) malloc(sp->size * sizeof(int));
    int choice;
    printf("\nMENU Options\n"); 
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");    
    do
    {
        int val;
        printf("Enter Your Choice:"); 
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("Enter element to be pushed:"); 
            scanf("%d", &val);
            push(sp, val);
            break;
            case 2: 
            pop(sp);
            break;
            case 3: 
            display(sp);
            break;
            default:
            break;
        }
    } while (choice !=4);
    return 0; 
    }