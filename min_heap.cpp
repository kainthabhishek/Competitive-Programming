#include<bits/stdc++.h>
using namespace std;
int arr[1000002];
void heapify(int arr[],int n,int index){
	if(n){
		int left = 2*index, right = 2*index +1,smallest = index;
		if(left<=n && arr[left] < arr[smallest] )
			smallest = left;
		if(right<=n && arr[right] < arr[smallest] )
			smallest = right;
		if(smallest!=index){
			//swap
			int temp;
			temp = arr[index];
			arr[index] = arr[smallest];
			arr[smallest] = temp;
			//call heapify for swapped variable i.e. smallest
			heapify(arr,n,smallest);
		}
	}
}
void build_heap(int arr[],int n){
	int i;
	for(i=n/2;i>=1;i--){
		heapify(arr,n,i);
	}
}
void pop(int arr[],int& n){
	arr[1] = arr[n--];
	heapify(arr,n,1);
}
void push(int arr[],int& n,int val){
	arr[++n] = val;
	int index = n;
	while(index>1 && arr[index/2] > arr[index]){
		arr[index/2] ^= arr[index];
		arr[index] ^= arr[index/2];
		arr[index/2] ^= arr[index];
		index /= 2;
	}
}
void print_sorted(int arr[],int n){
	while(n){
		printf("%d\n",arr[1]);
		pop(arr,n);
	}
}
int main(){
	int i,n,t,val;
	scanf("%d",&n);
	for(i=1,t=0;i<=n;i++){
		scanf("%d",&val);
		push(arr,t,val);
	}
	//build_heap(arr,n);
	print_sorted(arr,n);
	return 0;
}