#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int d;
    struct node *next;
};

struct headnode
{
    struct node *start;
    struct node *end;
    int count;
};

struct headnode h;

void display()
{
    struct node *ptr = h.start;
    if (!ptr)
    {
        printf("List is empty\n");
        return; 
    }
    printf("List elements are: \n"); 
    while (ptr)
    {
        printf("%d ", ptr->d);
        ptr = ptr->next;
    }
    printf("\n"); 
}

void insertAtFront()
{
    int x;
    printf("Enter data to be inserted : \n");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); ptr->d = x;
    ptr->next = NULL;
    if (!h.start)
    {
        h.start = ptr;
        h.end = ptr;
        h.count = 1;
        return;
    }
    ptr->next = h.start;
    h.start = ptr;
    h.count++;
}

void insertAtEnd()
{
    int x;
    printf("Enter data to be inserted : \n");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); ptr->d = x;
    ptr->next = NULL;
    if (!h.start)
    {
        h.start = ptr;
        h.end = ptr;
        h.count = 1;
        return;
    }
    struct node *p = h.start;
    while (p->next)
    p = p->next;
    p->next = ptr;
    h.end = ptr;
    h.count++; 
}

void deleteNode()
{
    int x;
    printf("Enter node to be deleted: \n");
    scanf("%d", &x);
    struct node *q = h.start;
    struct node *p = NULL;
    while(q && q->d!=x)
    {
        p=q;
        q=q->next; 
    }
    if(!q)
    return;
    if(!p)
    h.start=q->next;
    else
    p->next=q->next;
    if(h.end==q)
    h.end=p;
    free(q);
    h.count--;
}

void search(){
    int x;
    printf("Enter data to be searched: \n"); 
    scanf("%d", &x);
    struct node *p = h.start;
    while (p)
    {
        if (p->d == x)
        {
            printf("Element found in list!\n");
            return; 
        }
        p = p->next; }
        printf("Element not found!!\n"); }
        
void countNode()
{
    printf("Number of nodes :%d\n", h.count); 
}

int main() { 
    h.start = NULL;
    h.end = NULL;
    h.count = 0;
    int choice;
    while (1)
    {
        printf("1 - To see list\n");
        printf("2 - For insertion at starting\n"); 
        printf("3 - For insertion at end\n"); 
        printf("4 - For deletion of node\n"); 
        printf("5 - To search element\n"); 
        printf("6 - To count nodes\n");
        printf("7 - To exit\n");
        printf("\nEnter Choice :\n"); 
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            display();
            break;
            case 2:
            insertAtFront();
            break;
            case 3:
            insertAtEnd();
            break;
            case 4:
            deleteNode();
            break;
            case 5:
            search();
            break;
            case 6:
            countNode();
            break;
            case 7:
            exit(1);
            break;
            default:
            printf("Enter valid choice!\n");
            continue; 
        }
    }
    return 0; 
}