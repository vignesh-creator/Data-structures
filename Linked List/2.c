#include<stdio.h>
#include<stdlib.h>
struct linkedlist{
	int data;
	struct linkedlist* link;
};
void push(int item,struct linkedlist** root){
	struct linkedlist* temp=(struct linkedlist*)malloc(sizeof(struct linkedlist));
	temp->data=item;
	temp->link=*root;
	*root=temp;
}
void removeDuplicates(struct linkedlist* head)
{
    struct linkedlist* temp2 = head;
    struct linkedlist* nextlink; 
    if (temp2 == NULL) {
    	return;
	}
    while (temp2->link!= NULL) 
    {
       if (temp2->data == temp2->link->data) 
       {        
           nextlink = temp2->link->link;
           free(temp2->link);
           temp2->link = nextlink;  
       }
       else
       {
          temp2 = temp2->link; 
       }
    }
}
void display(struct linkedlist* root)
{
    struct linkedlist* temp1 = root;
    while (temp1!=NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->link;
    }
}

main(){
	int n;
	printf("Enter the number of integers that you are going to enter\n");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter the integers in ascending order that to be stored in linked list\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	//We are passing these elements into linked list
	struct linkedlist* root=NULL;
	for(i=n-1;i>=0;i--){
		push(arr[i],&root); //We are passing address of root and accessing it using **
	}
	display(root);
	printf("\n");
	removeDuplicates(root);
	display(root);
	
}
