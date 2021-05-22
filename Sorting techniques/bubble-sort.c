#include<stdio.h>
void bubble_sort(int arr[],int n){
	int i,j,swap_helper;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				swap_helper=arr[i];
				arr[i]=arr[j];
				arr[j]=swap_helper;
			}
		}
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
	bubble_sort(arr,n);
	printf("After Bubble sorting\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
