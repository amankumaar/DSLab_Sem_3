#include<stdio.h> 
#include<stdlib.h>

struct Queue {
    int *Arr; 
    int size; 
    int R; 
    int F;
    };

int isfull(struct Queue *q) {
    if ((q->R + 1) % q->size == q->F) 
    return 1;
    return 0; 
    }

int isempty(struct Queue *q) {
    if (q->R == q->F) return 1;
    return 0; 
    }

void enqueue(struct Queue *q, int val) {
    if (isfull(q))
    printf("The Circular Queue is Full!\n");
    else
    {
        q->R = (q->R + 1) % q->size;
        q->Arr[q->R] = val;
        printf("Element Enqueued Successfully!\n"); 
        printf("Enqueued element: %d\n", val);
        }
    }

void dequeue(struct Queue *q) {
    if (isempty(q))
    printf("The Circular Queue is Empty!\n");
    else
    {
        q->F = (q->F + 1) % q->size; 
        printf("Element Dequeued Successfully!\n"); 
        }
        }

void display(struct Queue *q) {
    printf("Elements of Queue are:\n");
    for (int i = (q->F + 1) % q->size; i <= q->R; i++) 
    printf("%d ", q->Arr[i]);
    printf("\n");
    }

int main(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue)); 
    q->size = 5;
    q->R = 0;
    q->F = 0;
    q->Arr = (int *)malloc(q->size * sizeof(int)); 
    int choice;
    printf("MENU Options\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    int x;
    do
    {
        printf("Enter Your Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("Enter element to be enqueued:");
            scanf("%d", &x);
            enqueue(q, x);
            break;
            case 2:
            dequeue(q);
            break;
            case 3:
            display(q);
            break;
            default:
            break;
        }} while (choice != 4);
        return 0;
}