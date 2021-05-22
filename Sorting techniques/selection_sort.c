#include<stdio.h>
void selection_sort(int arr[],int n){
	int i,j,swap_helper,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				min=j;
			}
		}
		swap_helper=arr[i];
		arr[i]=arr[min];
		arr[min]=swap_helper;
	}
}
int main(){
	int n;
	printf("Enter length of Array:");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter elements of Array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	printf("After selection sorting\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
