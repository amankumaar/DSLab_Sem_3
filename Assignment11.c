#include <stdio.h>

struct sparse{
   int row;
   int col;
   int value; 
};
   
typedef struct sparse sparsemat;

void readmatrix(sparsemat a[]){
   int m,n,t;
   printf("Enter Dimensions (mxn of matrix): ");
   scanf("%d %d",&m,&n);
   printf("Enter number of Non-Zero elements : ");
   scanf("%d",&t);
   a[0].row = m;
   a[0].col = n;
   a[0].value = t;
   printf("Enter Matrix Elements (FORMAT: <row-no> <col-no> <value>): \n");
   for(int i=1;i<=t;i++){
       scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);
       } 
}

void printmatrix(sparsemat a[]){
   int k=1;
   for(int i=0;i<a[0].row;i++){
       for(int j=0;j<a[0].col;j++){
           if(k<=a[0].value){
               if(i==a[k].row && j==a[k].col){
                   printf("%8d",a[k].value);
                   k++;
                   } 
                else{
                    printf("%8d",0);
                    }
            } 
            else{
                printf("%8d",0);
                } 
        }
    printf("\n");
   }
}

void addmatrix(sparsemat a[],sparsemat b[],sparsemat c[]){
    int i=1,j=1,k=1;
    while(i<=a[0].value && j<=b[0].value){
       if((a[i].row<b[j].row) || (a[i].row==b[j].row && a[i].col<b[j].col)){
           c[k].row=a[i].row;
           c[k].col=a[i].col;
           c[k].value=a[i].value;
           i++,k++; 
        }
       else if(a[i].row==b[j].row && a[i].col==b[j].col){
           c[k].row=a[i].row;
           c[k].col=a[i].col;
           c[k].value=a[i].value+b[j].value;
           i++,j++,k++;
        } 
        else{
           c[k].row=b[j].row;
           c[k].col=b[j].col;
           c[k].value=b[j].value;
           j++,k++;
        } 
    }
   while(i<=a[0].value){
       c[k].row=a[i].row;
       c[k].col=a[i].col;
       c[k].value=a[i].value;
       i++,k++;
    }

    while(j<=b[0].value){
       c[k].row=b[j].row;
       c[k].col=b[j].col;
       c[k].value=b[j].value;
       j++,k++;
    }
    c[0].row=a[0].row;
    c[0].col=a[0].col;
    c[0].value=k-1;
}

int main() {
    sparsemat a[35],b[35],c[35];
    printf("For Matrix A - \n");
    readmatrix(a);
    printf("Matrix A :- \n");
    printmatrix(a);
    printf("For Matrix B -\n");
    readmatrix(b);
    printf("Matrix B :- \n");
    printmatrix(b);
    printf("\n");
    printf("\n");
    addmatrix(a,b,c);
    printf("Addition of Matrices A and B : \n");
    printmatrix(c);
    return 0;
}