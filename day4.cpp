/*
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/
#include <iostream>

using namespace std;

int lowestMissin(int[], int);
void printL(int[], int);

int main(){
	int a[] = {3, 4, -1, 1};
	int n = sizeof(a)/sizeof(a[0]);
	sort(a, a+n);
	cout << "lowest: " << lowestMissin(a, n) << endl;
	printL(a, n);
	
	int b[] = {1, 2, 0};
	n = sizeof(b)/sizeof(b[0]);
	sort(b, b+n);
	cout << "lowest: " << lowestMissin(b, n) << endl;
	printL(b, n);
	
	return 0;
}

int lowestMissin(int a[], int n){
	int lowest = 1;
	for(int i = 0; i < n; ++i){
		if(a[i] == lowest){
			++lowest;
		}			
	}
	
	return lowest;
}

void printL(int a[], int n){
	for(int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}