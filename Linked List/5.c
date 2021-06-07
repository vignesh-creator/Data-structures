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
void display(struct linkedlist* root)
{
    struct linkedlist* temp1 = root;
    while (temp1!=NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->link;
    }
}
struct linkedlist* reverse(struct linkedlist** root)
{
    struct linkedlist *temp1 = NULL;
    struct linkedlist* temp2 = *root;
    struct linkedlist* link = NULL;
    while (temp2!= NULL) {
        link = temp2->link;
        temp2->link = temp1;
        temp1 = temp2;
        temp2 = link;
    }
    *root = temp1;
    return *root;
}
void split(struct linkedlist** root,struct linkedlist** list1,struct linkedlist** list2,int n){
	int i=n;
	struct linkedlist* temp1 = NULL;
    struct linkedlist* temp2 = NULL;
    struct linkedlist* temp = *root;
 
    while (temp!= NULL)
    {             
    	struct linkedlist* temp3 = temp;
    	temp = temp->link;    
    	temp3->link = temp1;        
    	temp1 = temp3;  
 
        if (temp!= NULL) {   
    	struct linkedlist* temp4 = temp;
    	temp = (temp)->link;    
    	temp4->link = temp2;        
    	temp2 = temp4;  
    	}
    }
 
    *list1 = reverse(&temp1);
    *list2 = reverse(&temp2);
}
main(){
	int n;
	printf("Enter the number of integers that you are going to enter\n");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter the integers that to be stored in linked list\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	//Passing these elements into our linked list
	struct linkedlist* root=NULL;
	for(i=n-1;i>=0;i--){
		push(arr[i],&root); //We are passing address of root and accessing it using **
	}
	struct linkedlist* li1=NULL;
	struct linkedlist* li2=NULL;
	split(&root,&li1,&li2,n);
	display(li1);
	printf("\n");
	display(li2);
}
