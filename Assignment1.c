#include<stdio.h>

void merge(int *arr1, int n, int *arr2, int m, int *a){
	int i=0;
	int j=0;
	int k =0;
	while(i<n && j<m){
		if(arr1[i]<arr2[j]){
			a[k++]=arr1[i++];
		}
		else if(arr2[j]<arr1[i]){
			a[k++]=arr2[j++];	
		}
		else{
		
			a[k++]=arr1[i++];
			a[k++]=arr2[j++];
		}
	}
	
	while(i<n){
		a[k++]=arr1[i++];
	}
	
	while(j<m){
		a[k++]=arr2[j++];
	}
}

int main(){
	int n=10;
	int arr1[]={13,15,17,19,21,23,25,27,29,31};
	int m=5;
	int arr2[]={14,16,18,20,22};
	int a[15];
	merge(arr1,n,arr2,m,a);
	for(int i = 0  ; i < m+n ; i++){
		printf("%d ", a[i]);
	}
}