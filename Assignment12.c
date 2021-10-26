#include<stdio.h>
#include<stdlib.h>


struct polynomial
{
    float cof;
    int exp; 
};

void input(struct polynomial polynomial[],int *size)
{   
    printf("Input polynomial:: ");
    printf("\nInput size of polynomial: ");
    scanf("%d",size); 

    for (int i = 0; i < *size; i++)
    {
        printf("\nDegree of element:%d:",i+1);
        scanf("%d",&polynomial[i].exp);
        printf("Coeffcient of element:%d:",i+1);
        scanf("%f",&polynomial[i].cof);
    }
}

void print(struct polynomial polynomial1[],int size)
{
    for (int i = 0; i < size; i++)
    { 
        if(polynomial1[i].cof==0)i++;
        else printf("(%.2f)",
        polynomial1[i].cof);
        if(polynomial1[i].exp==0)
        printf("");
        else if(size-i!=1)
        printf("x^%d+",polynomial1[i].exp); 
        else printf("x^%d",polynomial1[i].exp); 
    } 
}

void add(struct polynomial polynomial1[],struct polynomial polynomial2[],
struct polynomial result[],int size1,int size2,int *size3)
{   
    int i=0,j=0,k=0;
    *size3=0;

    while (i<size1 || j <size2)
    {
        if (polynomial1[i].exp==polynomial2[j].exp)
        {
            result[k].cof=polynomial1[i].cof+polynomial2[j].cof;
            result[k].exp=polynomial1[i].exp;
            (*size3)++;
            i++;j++;k++;
        }
        else if(polynomial1[i].exp>polynomial2[j].exp)
        {
            result[k].cof=polynomial1[i].cof;
            result[k].exp=polynomial1[i].exp;
            (*size3)++;
            i++;k++;
        }
        else
        {
            result[k].cof=polynomial2[j].cof;
            result[k].exp=polynomial2[j].exp;
            (*size3)++;
            j++;k++;
        }   
    }
}

void multiply(struct polynomial polynomial1[],struct polynomial polynomial2[],
struct polynomial result[],int size1,int size2,int *size3)
{
    
    struct polynomial polynomial3[10],polynomial4[100];
    int m=0;

    for(int i=0;i<100;i++)
    {       
    result[i].cof=0;
    result[i].exp=0;  
    polynomial4[i].cof=0;
    polynomial4[i].exp=0;    
    }
    
    for(int i=0;i<size1;i++)
    {
        int k=-1,l=0;

        for(l=0;l<m;l++)
        {       
            polynomial4[l].cof=result[l].cof;
            polynomial4[l].exp=result[l].exp;     
        }

        for(int j=0;j<size2;j++)
        { 
            polynomial3[++k].exp=polynomial1[i].exp+polynomial2[j].exp;
            polynomial3[k].cof=polynomial1[i].cof*polynomial2[j].cof;
        }
        add(polynomial3,polynomial4,result,k+1,l,&m);
    }
    *size3=m;
}

int main()
{   
    
    struct polynomial polynomial1[10],polynomial2[10],result[100];
    int size1,size2,size3;

    input(polynomial1,&size1);
    input(polynomial2,&size2);

    add(polynomial1,polynomial2,result,size1,size2,&size3);
    printf("\nAddition of two Polynomials: "); 
    print(result,size3); 

    multiply(polynomial1,polynomial2,result,size1,size2,&size3); 
    printf("\nMultiplication of two Polynomial: ");
    print(result,size3); 
}