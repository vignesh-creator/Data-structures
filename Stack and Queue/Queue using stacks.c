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
void push(struct stack* Stack,int num,struct stack* Stack2){
	if(Stack->top==(Stack->size)-1)
	{
		printf("Queue is full\n");
	}
	else{
	Stack->top+=1;
	Stack2->top+=1;
	Stack->items[Stack->top]=num;
	printf("%d is pushed\n",num);
   }
}
void pop(struct stack* Stack1,struct stack* Stack2){
	if(Stack2->top==-1){
		printf("Queue is Empty\n");
	}
	else{
		printf("An element is poped\n");
		Stack2->top-=1;
		Stack1->top-=1;
		int i;
		for(i=0;i<=Stack1->top;i++){
			Stack1->items[i]=Stack2->items[Stack2->top-i];
		}
	}
}
void remove_num(struct stack* Stack1,struct stack* Stack2){
	int i;
	if(Stack1->top!=-1){
		for(i=Stack1->top;i>=0;i--){
			Stack2->items[(Stack1->top)-i]=Stack1->items[i];
		}
		pop(Stack1,Stack2);
	}
	else{
		printf("Queue is Empty\n");
	}
}
void check(struct stack* Stack){
	int i;
	if(Stack->top!=-1){
		printf("Queue contains\n");
		for(i=0;i<=Stack->top;i++){
		printf("%d ",Stack->items[i]);
		}
	}
	else{
		printf("No elements in Queue for now\n");
	}
	printf("\n");
}
void isEmpty(struct stack* Stack){
	if(Stack->top==-1){
		printf("Queue is empty\n");
	}
	else{
		printf("Queue is not empty\n");
	}
}
void isFull(struct stack* Stack){
	if(Stack->top==Stack->size-1){
		printf("Queue is full\n");
	}
	else{
		printf("Queue is not full\n");
	}
}
main(){
	int size;
	printf("Enter size of Queue\n");
	scanf("%d",&size);
	struct stack* Stack1=create_stack(size);
	struct stack* Stack2=create_stack(size);
	while(1){
		int k;
		printf("Enter 0 to exit process and display final Queue\n");
		printf("Enter 1 to push element into the Queue\n");
		printf("Enter 2 to remove an element from Queue\n");
		printf("Enter 3 to display elements of Queue\n");
		printf("Enter 4 to check whether Queue is empty or not\n");
		printf("Enter 5 to check whether Queue is full or not\n");
		scanf("%d",&k);
		if(k==0){
			break;
		}
		else if(k==1){
			int  num;
			printf("Enter an Integer to push\n");
			scanf("%d",&num);
			push(Stack1,num,Stack2);
		}
		else if(k==2){
			remove_num(Stack1,Stack2);
		}
		else if(k==3){
			check(Stack1);
		}
		else if(k==4){
			isEmpty(Stack1);
		}
		else if(k==5){
			isFull(Stack1);
		}
		else{
			printf("Please enter valid key\n");
		}
	}
	int i;
	if(Stack1->top!=-1){
		printf("Queue contains\n");
		for(i=0;i<=Stack1->top;i++){
		printf("%d ",Stack1->items[i]);
		}
	}
	else{
		printf("Queue is empty\n");
	}
	free(Stack1->items);
	free(Stack2->items);
	free(Stack1);
	free(Stack2);
	
}
