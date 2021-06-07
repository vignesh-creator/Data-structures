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
    struct linkedlist* temp3 = NULL;
    while (temp2!= NULL) {
        temp3 = temp2->link;
        temp2->link = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    *root = temp1;
    return *root;
}
void palindrome(struct linkedlist** root,struct linkedlist** rev_root){
	int flag=1;
	while(*root!=NULL){
		if((*root)->data!=(*rev_root)->data){
			flag=0;
			break;
		}
		
		else{
			*root=(*root)->link;
			*rev_root=(*rev_root)->link;
		}
	}
	if(flag==0){
		printf("Not a palindrome\n");
	}
	else{
		printf("Yes! A palinrome\n");
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
	struct linkedlist* org_root=root;
	struct linkedlist* rev_root=reverse(&root);
	palindrome(&org_root,&rev_root);
}
