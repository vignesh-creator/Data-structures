#include<stdio.h>
#include<stdlib.h>
int partition(int arr[],int lb,int up){
	int pivot,swap_helper,start,end;
	pivot=arr[lb];
	start=lb;
	end=up;
	while(start<end){
		while(arr[start]<pivot){
			start++;
		}
		while(arr[end]>pivot){
			end--;
		}
		swap_helper=arr[end];
		arr[end]=arr[start];
		arr[start]=swap_helper;
	}
	return end;
}
void quick_sort(int arr[],int lb,int up){
	int mid_up;
	if(lb<up){
		mid_up=partition(arr,lb,up);
		quick_sort(arr,lb,mid_up-1);
		quick_sort(arr,mid_up+1,up);
	}
}
main(){
	int n;
	printf("Enter size of array:");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter array elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n-1);
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
