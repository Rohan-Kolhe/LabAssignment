#include<iostream>
using namespace std;

void print(int *arr, int size){
	int x;
	int count=0;
	cin >> x;
	for(int i=0; i<size; i++){
		if(arr[i] <= x) count++;	
	}
	cout << count << endl;
}

void arr_input(){
	int size;
	cin >> size;
	int *arr = new int[size];
	for(int i= 0; i<size; i++){
		cin >> arr[i];
	}
	print(arr, size);
}

int main()
{
	int T;
	cin >> T;
	for(int i=0; i<T; i++)
		arr_input();
return 0;
}
