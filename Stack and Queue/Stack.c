#include<stdio.h>
#include<stdlib.h>
struct stack{
	int top;
	int size;
	int* items;
};
struct stack* create_stack(int size)
{
	struct stack* Stack=(struct stack*)malloc(sizeof(struct stack));
	Stack->size=size;
	Stack->top=-1;
	Stack->items=(int*)calloc(Stack->size,sizeof(int));
	return Stack;
};
void push(struct stack* Stack,int num){
	if(Stack->top==(Stack->size)-1)
	{
		printf("Stack is full\n");
	}
	else{
	Stack->top+=1;
	Stack->items[Stack->top]=num;
	printf("%d is pushed\n",num);
   }
}
void pop(struct stack* Stack){
	if(Stack->top==-1){
		printf("Stack is Empty\n");
	}
	else{
		printf("An element is poped\n");
		Stack->top-=1;
	}
}
void isEmpty(struct stack* Stack){
	if(Stack->top==-1){
		printf("Stack is empty\n");
	}
	else{
		printf("Stack is not empty\n");
	}
}
void isFull(struct stack* Stack){
	if(Stack->top==Stack->size-1){
		printf("Stack is full\n");
	}
	else{
		printf("Stack is not full\n");
	}
}
void check(struct stack* Stack){
	int i;
	if(Stack->top!=-1){
		printf("Stack contains\n");
		for(i=0;i<=Stack->top;i++){
		printf("%d ",Stack->items[i]);
		}
	}
	else{
		printf("No elements in stack for now\n");
	}
	printf("\n");
}

int main(){	
	int k;
	int size;
	printf("Enter size of stack\n");
	scanf("%d",&size);
	struct stack* Stack=create_stack(size);
	while(1){
		printf("Enter 0 if you want to exit the process and display final stack\n");
		printf("Enter 1 if you want to push the element into stack\n");
		printf("Enter 2 if you want to pop element out of stack\n");
		printf("Enter 3 if you want to check whether stack is empty or not\n");
		printf("Enter 4 if you want to check whether stack is full or not\n");
		printf("Enter 5 to display current elements in stack\n");
		scanf("%d",&k);
		if(k==0){
			if(Stack->top==-1){
		printf("Stack is Empty\n");
			}
			break;
		}
		else if(k==1){
			printf("Enter an integer to push\n");
			int num;
			scanf("%d",&num);
			push(Stack,num);
		}
		else if(k==2){
			pop(Stack);
		}
		else if(k==3){
			isEmpty(Stack);
		}
		else if(k==4){
			isFull(Stack);
		}
		else if(k==5){
			check(Stack);
		}
		else{
			printf("Please enter valid key\n");
		}
	}
	int i;
	if(Stack->top!=-1){
		printf("Stack contains\n");
		for(i=0;i<=Stack->top;i++){
		printf("%d ",Stack->items[i]);
		}
	}
	free(Stack->items);
	free(Stack);
	
}
