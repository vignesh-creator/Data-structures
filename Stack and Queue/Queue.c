#include<stdio.h>
#include<stdlib.h>
struct queue{
	int front,rear,size;
	int* items;
};
struct queue* create_queue(int size){
	struct queue* Queue=(struct queue*)malloc(sizeof(struct queue));
	Queue->front=0;
	Queue->rear=0;
	Queue->size=size;
	Queue->items=(int*)calloc(Queue->size,sizeof(int));
};
void push_queue(struct queue* Queue,int num){
	if(Queue->rear==Queue->size){
		printf("Queue is full\n");
	}
	else{
		printf("%d is pushed into Queue\n",num);
		Queue->items[Queue->rear]=num;
		Queue->rear+=1;
	}
}
void remove_queue(struct queue* Queue){
	if(Queue->rear==Queue->front){
		printf("Queue is empty\n");
	}
	else{
		int i;
		printf("%d is removed\n",Queue->items[0]);
		for(i=0;i<Queue->rear;i++){
			Queue->items[i]=Queue->items[i+1];
		}
		Queue->rear-=1;
	}
}
void size_of(struct queue* Queue){
	printf("Present number of element in Queue: %d\n",(Queue->rear));
}
void isfull(struct queue* Queue){
	if(Queue->rear==Queue->size){
		printf("Queue is full\n");
	}
	else{
		printf("Queue is not full\n");
	}
}
void isempty(struct queue* Queue){
	if(Queue->rear==Queue->front){
		printf("Queue is empty\n");
	}
	else{
		printf("Queue is Not Empty\n");
	}
}
void check(struct queue* Queue){
	int i;
		if(Queue->rear>0){
			printf("Currently Queue contains:");
		for(i=0;i<Queue->rear;i++){
		printf("%d ",Queue->items[i]);
			}
			printf("\n");
		}
		else{
			printf("Queue is Empty\n");
		}
}
main(){
		printf("Enter the size of queue\n");
		int size;
		scanf("%d",&size);
		struct queue* Queue=create_queue(size);
		int k;
		while(1){
			printf("Enter 0 if you want to end the process and display final queue\n");
			printf("Enter 1 if you want to insert element into the queue\n");
			printf("Enter 2 if you want to remove element from the queue\n");
			printf("Enter 3 to know number of elements present in the Queue\n");
			printf("Enter 4 to check if the Queue is full or not\n");
			printf("Enter 5 to check if the Queue is empty or not\n");
			printf("Enter 6 to know current elements that are present in the queue\n");
			scanf("%d",&k);
			if(k==0){
				break;
			}
			else if(k==1){
				int num;
				printf("Enter an integer to push into queue\n");
				scanf("%d",&num);
				push_queue(Queue,num);
			}
			else if(k==2){
				remove_queue(Queue);
			}
			else if(k==3){
				size_of(Queue);
			}
			else if(k==4){
				isfull(Queue);
			}
			else if(k==5){
				isempty(Queue);
			}
			else if(k==6){
				check(Queue);
			}
			else{
				printf("Please enter valid Number\n");
			}
		}
		int i;
		if(Queue->rear>0){
			printf("Queue contains\n");
		for(i=0;i<Queue->rear;i++){
		printf("%d ",Queue->items[i]);
			}
		}
		else{
			printf("Queue is Empty");
		}
		free(Queue->items);
		free(Queue);
}
