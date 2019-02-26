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
	//use the following to test various inputs
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
	
	//inputs of size 1 <= n <= 3 are SPECIAL CASES
	if(r == 1)
		return false;
	else if(r == 2)
		return (A[0] + A[1] == k) ? true : false;	
	else if(r == 3){
		int possib[3] = {A[0], A[2], A[1]};
		return solves(possib, k) ? true : false;		
	}
	
	
	//MAIN ALGORITHM
	//first possible solution may be contained in A[0]-A[2]
	int possib[3] = {A[0], A[2], A[1]};	
	for(int i = 3; i <= r; ++i){
		//sort the proposed solution
		bubbleSort(possib);
		if(solves(possib, k))
			return true;
		
		//eliminate largest item or smallest item in the 3 possible solutions
		l = (possib[0] + possib[2] > k) ? 0 : 2;
		//next input in A replaces the eliminated number in the possible solution list
		possib[l] = A[i];
	}	
	
	
	//false if solution is never found
	return false;
	//time complexity is O(N)
}

void bubbleSort(int n[]){
	//for sorting a list of length 3
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2-i; ++j)
			if(n[j] > n[j+1])
				swap(n[j], n[j+1]);
	//time complexity is O(1)
}


bool solves(int n[], int k){
	//if any combination of the possible list of 3 has a sum = to key, return true 
	if( n[0] + n[1] == k
	  ||n[0] + n[2] == k
	  ||n[1] + n[2] == k)
		return true;
	return false;
	//time complexity is O(1)
}

void swap(int &n, int &m){
	int h = n;
	n = m;
	m = h;
	//time complexity is O(1)
}

//end doc
