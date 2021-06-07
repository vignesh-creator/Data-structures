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
void mth(struct linkedlist* root,int n,int m){
	struct linkedlist* temp=(struct linkedlist* )malloc(sizeof(struct linkedlist));
	struct linkedlist* temp2=root;
	int i;
	if(n-m-1==0){
			root=temp2->link;
	}
	else{
	for(i=1;i<=n;i++){
		if(i==n-m-1){
			temp=temp2->link->link;
			free(temp2->link);
			temp2->link=temp;
		}
		else{
			temp2=temp2->link;
		}
	}
  }
  display(root);
}
main(){
	int m,n;
	printf("Enter number of elements of linkedlist\n");
	scanf("%d",&n);
	int arr[n],i;
	printf("Enter elements of the linkedlist\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	struct linkedlist* root=NULL;
	for(i=n-1;i>=0;i--){
		push(&root,arr[i]);
	}
	printf("Enter m value\n");
	scanf("%d",&m);
	mth(root,n,m);
	
}
