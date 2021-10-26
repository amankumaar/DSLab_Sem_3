#include<stdio.h>
#include<string.h>

void push(char *Arr,int *pt){
	Arr[*pt+1]='(';
	(*pt)++;
}

int pop(char *Arr,int *pt){
	if(*pt==-1){
		return 0;
	}
	else{
		(*pt)--;
		return 1;
	}
}

int check(char * str){
	int i=0;
	char stack[100];
	int pt=-1;
	for(i = 0;i<strlen(str);i++){
		if(str[i]=='('){
			push(stack,&pt);
		}
		else{
			int x=pop(stack,&pt);
			if(x==0){
				return 0;
			}
		}
	}
	return (1-pop(stack,&pt));
}

int main(){
	char str[90];
	printf("Enter bracket : ");
	scanf("%s",str);
	int x=check(str);
	if(x==1){
		printf("The sequence is Balanced");
	}
	else{
		printf("The sequence is not Balanced");
	}
}
