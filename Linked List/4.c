#include<stdio.h>
#include<stdlib.h>
struct linkedlist{
	int data;
	struct linkedlist* link;
};
void push(struct linkedlist** root,int item){
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
void sorting(struct linkedlist** root){
	struct linkedlist* sorted = NULL;
	struct linkedlist* temp = *root;
	while(temp!=NULL){
		struct linkedlist *temp1=(struct linkedlist*)malloc(sizeof(struct linkedlist));
		temp1=temp->link;
		struct linkedlist *temp2=(struct linkedlist*)malloc(sizeof(struct linkedlist));
		if(sorted!=NULL && sorted->data < temp->data){
			temp2=sorted;
			while(temp2->link!=NULL && (temp2->link->data) < (temp->data)){
				temp2=temp2->link;
			}
			temp->link = temp2->link; 
        	temp2->link = temp;
		}
		else{
        	temp->link = sorted; 
        	sorted = temp;
		}
		temp=temp1;
	}
	*root=sorted;
}
main(){
	int n;
	printf("Enter the number of elements that are need to be stored in Linkedlist\n");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter numbers to be stored in linked list\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	struct linkedlist* root=NULL;
	for(i=n-1;i>=0;i--){
		push(&root,arr[i]);
	}
	sorting(&root);
	display(root);
}
