#include<stdio.h>

void selectionSort(int a[], int n){
	int i, j, min, temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min])
				min=j;
		}
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

int main(){
	int i, a[] = {15,20,53,2,24,34,75};
	int size = sizeof(a)/sizeof(a[0]);
	selectionSort(a,size);
	printf("Sorted Elements: ");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
