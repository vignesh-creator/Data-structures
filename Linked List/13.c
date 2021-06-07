#include<stdio.h>
#include<stdlib.h>
struct linkedlist{
	int data;
	struct linkedlist* link;
};
struct linkedlist *push(int item){
    struct linkedlist *temp=(struct linkedlist*)malloc(sizeof(struct linkedlist));
    temp->data=item;
    temp->link=NULL;
    return temp;
}
int circular(struct linkedlist *head){
 struct linkedlist *temp=head;
 while(temp!=NULL)
 { 
    if(temp->link==head){
    	return 1;	
	}
    temp=temp->link;
}
return 0;
}
main(){
	struct linkedlist* root=push(1);
	root->link=push(2);
	root->link->link=push(3);
    root->link->link->link=root;
	int flag;
	flag=circular(root);
		if(flag==1){
			printf("YES");
		}
		else{
			printf("NO");
		}
}

