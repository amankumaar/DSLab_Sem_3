#include <stdio.h>

void mer(int*a,int l,int m,int h){
    
    int b[h+1];
    int i=l,j=m+1,k=l;
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=h)
        b[k++]=a[j++];
    for(int q=l;q<=h;q++)
        a[q]=b[q];
}

void sorting(int *a, int h, int l)
{
    if(l<h){
        int m= (l + h)/2;
        sorting(a,h,m+1);
        sorting(a,m,l);
        mer(a,l,m,h);       
    }
}

int main()
{
    int n=6;
    int a[]={14,16,15,12,13,11};
    sorting(a,n-1,0);
    printf("Sorted array is:");
    for(int k=0;k<n;k++)
        printf("%d ",a[k]);
    return 0;
}