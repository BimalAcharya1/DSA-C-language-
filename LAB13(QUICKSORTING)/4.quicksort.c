#include<stdio.h>
#include<conio.h>
void quicksort(int a[], int l, int r){
	int p;
	if(l<r){
		p = partition(a, l, r);
		quicksort(a, l, p-1);
		quicksort(a, p+1, r);
	}
}

int partition(int a[], int l, int r){
	int i, j, p, temp;
	i = l;
	j = r;
	p = a[l];
	while(i<j){
		while(a[i]<p){
			i++;
		}
		while(a[j]>p){
			j--;
		}
		if(i<j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	l = a[j];
	a[j] = p;
	return j;
}

void main(){
	int i, a[]={3,1,9,2,6,8,4};
	quicksort(a,0,6);
	printf("Sorted elements: \n");
	for(i=0;i<7;i++){
		printf("%i ",a[i]);
	}
	getch();
}
