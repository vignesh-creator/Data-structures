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
struct linkedlist* temp1 = NULL;
struct linkedlist* temp3 = NULL;
struct linkedlist* reverse(struct linkedlist** root)
{
    if((*root)==NULL){
    	return temp1;
	}
	else{
		temp3=(*root)->link;
		(*root)->link=temp1;
		temp1=(*root);
		(*root)=temp3;
		reverse(root);
		
	}
}
main(){
	int n;
	printf("Enter the number of elements you are passing into linked list\n");
	scanf("%d",&n);
	int arr[n],i;
	printf("Enter the elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	struct linkedlist* root=NULL;
	for(i=n-1;i>=0;i--){
		push(arr[i],&root);
	}
	display(reverse(&root));
}
