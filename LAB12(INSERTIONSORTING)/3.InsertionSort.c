#include<stdio.h>

void insertionSort(int a[], int n){
	int i, key, j;
	for(i=0;i<n;i++){
		key = a[i];
		j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main(){
	int i, a[] = {4,2,5,7,280,54,32,64};
	int size = sizeof(a)/sizeof(a[0]);
	insertionSort(a,size);
	printf("Sorted Array: ");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
