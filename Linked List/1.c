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
void split(struct linkedlist** first,struct linkedlist** last,int len,struct linkedlist* root){
	struct linkedlist* temp2 = root;
    if (len==1)
    {
        *first = root;
    }
    else
	{
    int i;
    for (i = 0; i < (len - 1) / 2; i++) {
        temp2 = temp2->link;
    }
    *first = root;
    *last = temp2->link;
    temp2->link = NULL;
    }
    printf("Roo\n");
    display(root);
}
main(){
	int n;
	printf("Enter the number of integers that you are going to enter\n");
	scanf("%d",&n);
	if(n>0){
		int i,arr[n];
	printf("Enter the integers that to be stored in linked list\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	//We are passing these elements into linked list
	struct linkedlist* root=NULL;
	for(i=n-1;i>=0;i--){
		push(arr[i],&root); //We are passing address of root and accessing it using **
	}
	struct linkedlist* first=NULL;
	struct linkedlist* last=NULL;
	split(&first,&last,n,root);
	display(first);
	printf("\n");
	display(last);
	}
	else{
		printf("Code ended\n");
	}
}
