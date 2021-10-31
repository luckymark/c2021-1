#include<iostream>
using namespace std;
int main(){
	int arr[9]={2,4,5,6,8,1,9,3,7};
	for(int i=0;i<9-1;i++){
		for(int j=0;j<9-i-1;j++){
			//arr[j+1]=arr[j]>arr[j+1]?arr[j]:arr[j+1];//不能这么写，因为是两个数交换，而不是大的数直接取代小的数 
	       if(arr[j]>arr[j+1]){
		   int temp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=temp;
	       }
	    }
	}
	for(int a=0;a<9;a++){
		cout<<arr[a]<<" "; 
	}
	return 0;
}
