#include<stdio.h>
#define size 7
int arr[size];
void linearprobe(int value){
	int i,key;
	for(i=1;i<10;i++){
		key=(value+i)%size;
		if(arr[key]==-1){
			arr[key]=value;
			break;
		}
	}
}
void insert(int value){
	int key=value%size;
	if(arr[key]==-1){
		arr[key]=value;
		printf("%d inserted at arr[%d]\n",value,key);
	}	
	else{
		printf("Collison occured !!! arr[%d] has element %d already!\n",key,arr[key]);
		linearprobe(value);
	}
}
void del(int value){
	int key=value%size;
	if(arr[key]==value)
		arr[key]=-1;
		else
		printf("%d not present in the hash table\n",value);
}
void search(int value){
	int key=value%size;
	if(arr[key]==value)
		printf("Search found.\n");
	else
		printf("Search not found.\n");
}
void print(){
	int i;
	for(i=0;i<size;i++)
	printf("arr[%d]=%d\n",i,arr[i]);
	printf("\n");
}
int main(){
	int i;
	for(i=0;i<size;i++)
	arr[i]=-1;
	insert(10);
	insert(4);
	insert(2);
	insert(3);
	insert(17);
	printf("Hash table\n");
	print();
	
	printf("Deleting value 10...\n");
	del(10);
	printf("After deletion hash table\n");
	print();
	
	printf("Deleting value 5...\n");
	del(5);
	printf("After deletion hash table\n");
	print();
	printf("Searching value 4...\n");
	search(4);
	printf("Searching value 10...\n");
	search(10);
	return 0;
}

