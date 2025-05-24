#include<stdio.h>
#include<conio.h>
#include<string.h>
void mergesort(int a[], int l, int r){
	int mid;
	if(l<r){
		mid =(l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,r,mid);
	}
}

int merge(int a[], int l, int r, int m){
	int i,j,p,k,temp,b[20];
	i=l;
	j=l;
	k=m+1;
	while(j<=m && k<=r){
		if(a[j]<a[k]){
			b[i++]=a[j++];//i++;j++
		}
		else{
			b[i++]=a[k++];
		}
	}
	while(j<=m){
		b[i]=a[k];
		i++;
		k++;
	}
	while(k<=r){
		b[i]=a[k];
		i++;
		k++;
	}
	
	for(i=l;i<=r;i++){
		a[i]=b[i];
	}
}

void main(){
	int i, a[]={13,10,5,12,6,18,14};
	mergesort(a,0,6);
	for(i=0;i<7;i++){
		printf("%d ",a[i]);
	}
	getch();
}


