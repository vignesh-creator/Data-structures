#include<stdio.h>
#include<stdlib.h>
struct linkedlist{
	int data;
	struct linkedlist* prev_link;
	struct linkedlist* post_link;
};
void push(int item,struct linkedlist** root)
{
    struct linkedlist* temp = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    temp->data = item;
    temp->post_link = (*root);
    temp->prev_link = NULL;
    if (*root!= NULL){
    	(*root)->prev_link = temp;
	}
    (*root) = temp;
}
void display(struct linkedlist* root)
{
    struct linkedlist* rev;
    printf("List entered\n");
    while (root != NULL) {
        printf("%d ", root->data);
        rev = root;
        root = root->post_link;
    }
 
    printf("\nReversed list\n");
    while (rev!= NULL) {
        printf("%d ",rev->data);
        rev = rev->prev_link;
    }
}
main(){
	int n;
	printf("Enter size of list\n");
	scanf("%d",&n);
	int arr[n],i;
	printf("Enter elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	struct linkedlist* root=NULL;
	for(i=n-1;i>=0;i--){
		push(arr[i],&root);
	}
	display(root);
}
