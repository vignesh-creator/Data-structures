#include<stdio.h>
void Heapify(int arr[],int n,int i){
	int largest,l,r,temp;
	l = 2*i+1;
	r = 2*r+2;
	largest = i;
	if(l < n && arr[largest] < arr[l]){
		largest = l;
	}
	if(r < n && arr[largest] < arr[r]){
		largest = r;
	}
	if(largest != i){
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		Heapify(arr,n,largest);
	}
}
void Heapsort(int arr[],int n){
	int i,temp;
	for(i=(n/2)-1; i>=0 ; i--){
		Heapify(arr,n,i);
	}
	for(i=n-1; i>=0 ; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		Heapify(arr,i,0);
	}
}
int main(){
	int n;
	printf("Enter the size of Array:");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter elements of Array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	Heapsort(arr,n);
	printf("Sorted Array\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
