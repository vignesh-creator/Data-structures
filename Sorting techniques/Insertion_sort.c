#include<stdio.h>
void insertion_sort(int arr[],int n){
	int i,j,k,swap_helper,temp;
	for(i=1;i<n;i++){
		k=i;
		temp=arr[k];
		for(j=i-1;j>=0;j--){
			if(temp<arr[j]){
				swap_helper=arr[k];
				arr[k]=arr[j];
				arr[j]=swap_helper;
				k--;
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
	insertion_sort(arr,n);
	printf("After insertion sorting\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
