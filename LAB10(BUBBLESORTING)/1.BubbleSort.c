#include<stdio.h>
void bubbleSort(int a[], int n){
	int i, j, temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main(){
	int a[] = {1,4,19,42,40,7,3};
	int size = sizeof(a)/sizeof(a[0]);
	bubbleSort(a,size);
	
	int i;
	printf("Sorted array using Bubble Sort: ");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
