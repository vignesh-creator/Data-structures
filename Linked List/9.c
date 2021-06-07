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
struct linkedlist* removeDuplicates(struct linkedlist* head)
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
    return head;
}
void or_op(struct linkedlist** root1,struct linkedlist** root2){
	struct linkedlist* root=NULL;
	int i;
	while(*root1!=NULL || *root2!=NULL){
		if(*root1==NULL){
			while(*root2!=NULL){
				push(((*root2)->data),&root);
				(*root2)=(*root2)->link;
			}
		}
		else if(*root2==NULL){
			while(*root1!=NULL){
				push(((*root1)->data),&root);
				(*root1)=(*root1)->link;
			}
		}
		else{
			while((*root1)!=NULL && (*root2)!=NULL){
				if(((*root1)->data) > ((*root2)->data)){
					push(((*root2)->data),&root);
					(*root2)=(*root2)->link;
				}
				else{
					push(((*root1)->data),&root);
					(*root1)=(*root1)->link;
				}
			}
		}
	}
	printf("List1 or List2\n");
	display(removeDuplicates(reverse(&root)));
	printf("\n");
}
int length(struct linkedlist* root) 
{ 
    int count = 0; 
    struct linkedlist* temp = root; 
    while (temp != NULL) 
    { 
        count++; 
        temp = temp->link; 
    } 
    return count; 
} 
void and_op(struct linkedlist** root1,struct linkedlist** root2){
	struct linkedlist* root=NULL;
	*root1=removeDuplicates(*root1);
	*root2=removeDuplicates(*root2);
	int n1,n2;
	n1=length(*root1);
	n2=length(*root2);
	if(n1>n2){
		while(*root1!=NULL){
			struct linkedlist* temp=*root2;
			while(temp!=NULL){
				if( temp->data == (*root1)->data){
					push(temp->data,&root);
				}
				temp=temp->link;
			}
			(*root1)=(*root1)->link;
		}
	}
	else{
		while(*root2!=NULL){
			struct linkedlist* temp=*root1;
			while(temp!=NULL){
				if( temp->data == (*root2)->data){
					push(temp->data,&root);
				}
				temp=temp->link;
			}
			(*root2)=(*root2)->link;
		}
	}
	printf("list1 and list2\n");
	display( reverse(&root) );
	printf("\n");
}
void or_not_op(struct linkedlist** root1,struct linkedlist** root2){
	printf("list1 or not(list2)\n");
	display(*root1);
	printf("\n");
}
void and_not_op(struct linkedlist** root1,struct linkedlist** root2){
	struct linkedlist* root=NULL;
	*root2=removeDuplicates(*root2);
	while(*root1!=NULL){
		int flag=0;
		struct linkedlist* temp=*root2;
		  while(temp!=NULL){
		  	if(temp->data==(*root1)->data){
					flag=1;		  		
			  }
			  temp=temp->link;
		  }
		  if(flag==0){
		  	push((*root1)->data,&root);
		  }
		  (*root1)=(*root1)->link;
	}
	printf("List1 and not(List2)\n");
	display(reverse(&root));
}
main(){
	int n1,n2;
	printf("Enter size of list 1\n");
	scanf("%d",&n1);
	printf("Enter size of list 2\n");
	scanf("%d",&n2);
	int i,arr1[n1],arr2[n2];
	printf("Enter the integers in ascending order that to be stored in list 1\n");
	for(i=0;i<n1;i++){
		scanf("%d",&arr1[i]);
	}
	printf("Enter the integers in ascending order that to be stored in list 2\n");
	for(i=0;i<n2;i++){
		scanf("%d",&arr2[i]);
	}
	struct linkedlist* root1=NULL;	
	struct linkedlist* root2=NULL;
	for(i=n1-1;i>=0;i--){
		push(arr1[i],&root1); //We are passing address of root and accessing it using **
	}
	for(i=n2-1;i>=0;i--){
		push(arr2[i],&root2); //We are passing address of root and accessing it using **
	}
	struct linkedlist* root1_or=root1;	
	struct linkedlist* root2_or=root2;
	struct linkedlist* root1_and=root1;	
	struct linkedlist* root2_and=root2;
	or_op(&root1_or,&root2_or);
	and_op(&root1_and,&root2_and);
	or_not_op(&root1,&root2);
	and_not_op(&root1,&root2);
}
