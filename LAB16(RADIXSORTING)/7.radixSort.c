#include<stdio.h>
#include<conio.h>
int getMax(int a[], int n){
	int i, max = a[0];
	for(i=0;i<n;i++){
		if(max<a[i]){
			max = a[i];
		}
	}
	return max;
}

void countingSort(int a[], int size, int place){
	int i, output[size+1];
	int max = (a[0]/place)%10;
	
	for(i=1;i<size;i++){
		if(((a[i]/place)%10)>max){
			max = a[i];
		}
	}
	int count[max+1];
	
	for(i=0;i<max;++i)
		count[i]=0;
	
	for(i=0;i<size;i++)
		count[(a[i]/place)%10]++;
	
	for(i=1;i<10;i++)
		count[i] += count[i-1];
	
	for(i=size-1; i>=0;i--){
		output[count[(a[i]/place)%10]-1] = a[i];
		count[(a[i]/place)%10]--;
	}
	
	for(i=0;i<size;i++)
		a[i] = output[i];
}

void radixSort(int a[], int size){
	int place, max=getMax(a, size);
	for(place=1;max/place>0;place*=10){
		countingSort(a, size, place);
	}
}
 
void printArr(int a[], int size){
	int i;
	printf("Radix Sort: ");
	for(i=0;i<size;++i)
		printf("%d ",a[i]);
	printf("\n");
}

int main(){
	int a[]={121, 423, 7372, 32, 52, 5, 2, 12};
	int n = sizeof(a)/sizeof(a[0]);
	radixSort(a,n);
	printArr(a,n);\
	return 0;
}
