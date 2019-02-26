/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#import <iostream>

using namespace std;

//prototypes
bool hasSum(int[], int, int);
void bubbleSort(int[]);
bool solves(int[], int);
void swap(int&, int&);

int main(){	
	int a[] = {9},
		b[] = {8, 9},
		c[] = {10, 15, 3, 7},
		d[] = {3, 8, 6, 1, 7, 4};
	
	cout << "a:" << hasSum(a, 9, 1) << endl
		 << "b:" << hasSum(b, 9, 2) << endl
		 << "c:" << hasSum(c, 17, 4) << endl
		 << "d:" << hasSum(d, 9, 6) << endl;
	
	return 0;
}

bool hasSum(int A[], int k, int r){
	int l;
	
	if(r == 1){
		return (A[0] == k) ? 1 : 0;
	}
	else if(r == 2){
		return (A[0] + A[1] == k) ? 1 : 0;	
	}
	else if(r == 3){
		int possib[3] = {A[0], A[2], A[1]};
		return solves(possib, k) ? true : false;		
	}
	
	
	int possib[3] = {A[0], A[2], A[1]};	
	for(int i = 3; i <= r; ++i){
		bubbleSort(possib);
		if(solves(possib, k)){
			return true;
		}
		l = (possib[0] + possib[2] > k) ? 0 : 2;
		possib[l] = A[i];
	}	
	return false;
}

void bubbleSort(int n[]){
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2-i; ++j)
			if(n[j] > n[j+1])
				swap(n[j], n[j+1]);		
}

bool solves(int n[], int k){
	if( n[0] + n[1] == k
	  ||n[0] + n[2] == k
	  ||n[1] + n[2] == k)
		return true;
	return false;
}

void swap(int &n, int &m){
	int h = n;
	n = m;
	m = h;
}

//end doc
