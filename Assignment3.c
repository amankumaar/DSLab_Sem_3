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

void sorting(int *a, int n)

{
    int p;
    for( p=2;p<=n;p=p*2)
    {
        for(int i=0;i+p-1<n;i+=p)
        {
            mer(a,i,i+(p-1)/2,i+p-1);   
        }
        
    }
    if(p/2<n)
        {
            mer(a,0,(p-1)/2,n-1);
        }
}


int main()
{
    int n=6;
    int a[]={14,16,15,12,13,11};
    sorting(a,n);
    for(int k=0;k<n;k++)
        printf("%d ",a[k]);
    return 0;
}