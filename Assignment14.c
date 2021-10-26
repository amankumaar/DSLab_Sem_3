#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int d;
    struct node *next;
};

struct node *head = NULL;

void display()
{
    struct node *ptr = head;
    if (!ptr)
    {
    printf("list is empty\n");
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

void insertSorted()
{
    int x;
    printf("Enter data to be inserted: \n"); 
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->d = x;
    ptr->next = NULL;
    if (!head)
    {
        head = ptr;
        return; 
    }
    if (head->d >= x)
    {
        ptr->next = head;
        head = ptr;
        return;
    }
    if (head->d < x && head->next == NULL)
    {
        head->next = ptr;
        return; 
    }
    struct node *p = head;
    struct node *tail = NULL;
    while (p && p->d < x)
    {
        tail = p;
        p = p->next; 
    }
    if (!p) 
    {
    tail->next = ptr;
    return; 
    }
    tail->next = ptr;
    ptr->next = p;
}

void deleteNode()
{
    int x;
    printf("Enter node to be deleted:\n"); scanf("%d", &x);
    struct node *ptr = head;
    struct node *tail = NULL;
    if (head->d == x)
    {
        head = head->next;
        free(ptr); 
    }
    while (ptr && ptr->d < x)
    {
        tail = ptr;
        ptr = ptr->next;
    }
    if (!ptr) {
        printf("Element not present in list!\n");
        return; 
    }
    if(ptr->d>x){
        printf("Element not present in list!\n");
        return; 
    }
    tail->next = ptr->next;
    free(ptr); 
    }
    
void search()
{
    int x;
    printf("Enter data to be searched\n"); 
    scanf("%d", &x);
    struct node *p = head;
    while (p)
    {
        if (p->d > x)
        break;
        if (p->d == x)
        {
            printf("Element found in list!\n");
            return; 
        }
        p = p->next; }
        printf("Element not found!!\n"); }

int main() {
    int choice;
    while (1)
    {
        printf("1 - To see list\n");
        printf("2 - For inserting in sorted list\n");
        printf("3 - For deletion\n"); 
        printf("4 - To search element\n"); 
        printf("5 - To exit\n"); 
        printf("\nEnter Choice :\n"); 
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            display();
            break;
            case 2:
            insertSorted();
            break;
            case 3:
            deleteNode();
            break;
            case 4:
            search();
            break;
            case 5:
            exit(1);
            break;
            default:
            printf("Enter valid choice!\n");
            continue; 
        }
    }
    return 0; 
}