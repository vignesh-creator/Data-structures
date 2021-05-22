#include<stdio.h>
void merge(int arr[],int lb,int mid,int ub){
	/* let's take two temporary arrays. one array contains (lb to mid) and next has (mid+ to ub)
	lb to mid has (mid-lb+1) number of elements and mid+1 to ub contains (ub-mid) number of elements 
	lb stands for lower bound
	mid stands for middle
	ub stands for upper bound */
	int n1,n2;
	n1 = mid-lb+1;
	n2 = ub-mid;
	int arr1[n1],arr2[n2]; 
	int i,j,k;
	for(i=0;i<n1;i++){
		arr1[i] = arr[lb+i];
	}
	for(j=0;j<n2;j++){
		arr2[j] = arr[mid+1+j];
	}
	i=0;
	j=0;
	k = lb;
	while(i<n1 && j<n2){
		if(arr1[i] <= arr2[j]){
			arr[k] = arr1[i];
			i++;
		}
		else{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
 
 
}
void merge_sort(int arr[],int lb,int ub){
	int mid;
	if(lb < ub){
		mid = (lb+ub)/2 ;
		merge_sort(arr,lb,mid); 
		merge_sort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
main(){
	int n,i;
	printf("Enter number of elements of Array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of Array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	printf("Sorted array\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
