#include<stdio.h>
#include <stdlib.h>

struct arr
{
    int *A;
    int si;
    int len;
};

void Insert(struct arr *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->len)
    {
        for (i = arr->len; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->len++;
    }
}
int Delete(struct arr *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->len)
    {
        x = arr->A[index];
        for (i = index; i < arr->len - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->len--;
        return x;
    }
    return 0;
}

int Search(struct arr *arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr->len - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr->A[mid])
            return mid;
        else if (key < arr->A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
void Display(struct arr arr)
{
    int i;
    printf("\nElements are: \n");
    for (i = 0; i < arr.len; i++)
        printf("%d ", arr.A[i]);
}

int main(){
    struct arr arr1;
    int ch;
    int x, ind;
    printf("Enter Size of Array: ");
    scanf("%d", &arr1.si);
    arr1.A = (int *)malloc(arr1.si * sizeof(int));
    arr1.len = 0;

    do
    {
        printf("\nSelect you Options:- \n");
        printf("Press '1' to Insert\n");
        printf("Press '2' to Delete\n");
        printf("Press '3' to Search\n");
        printf("Press '4' to Display\n");
        printf("Press '5' to Exit\n");
        printf("Enter you choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an element and index: ");
            scanf("%d %d", &x, &ind);
            Insert(&arr1, ind, x);
            break;
        case 2:
            printf("Enter index: ");
            scanf("%d", &ind);
            x = Delete(&arr1, ind);
            printf("Deleted Element is: %d\n", x);
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &x);
            ind = Search(&arr1, x);
            printf("Element index: %d", ind);
            break;

        case 4:
            Display(arr1);
            break;
        }
    } while (ch < 5);
    return 0;
}