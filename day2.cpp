/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

//not being able to use division makes the algorithm O(n^2)


#include <iostream>

using namespace std;

//prototypes
int* algorithmN2(int[], int);//without division
int* algorithmN(int[], int)throw (invalid_argument);//with division but O(n) instead of O(n^2)
void display(int*, int);

int main(){
	
	//for various inputs
	int 
		a[] = {1, 2, 3, 4, 5},
		b[] = {3, 2, 1},
		c[] = {4, 1, 5, 6},
		d[] = {9, 8, 0, 8};
	
	try{
	display(algorithmN2(a, 5), 5);
	display(algorithmN2(b, 3), 3);
	display(algorithmN2(c, 4), 4);
	display(algorithmN2(d, 4), 4);
	}
	catch (invalid_argument msg){
		cout << msg.what() << endl;
	}
	
	return 0;
}

//performs algorithm in O(n^2) without divison
int* algorithmN2(int n[], int s){
	//allocate a dynamic array so you can return its address
	int *b;
	b = new int[s];
	int product;
	
	//for each item in array, multiply each item that is not i together
	//store this product in the identifier 'product'
	for(int i = 0; i < s; ++i){
		product = 1;
		for(int j = 0; j < s; ++j){
			if (i != j){
				product *= n[j];
			}			
		}
		b[i] = product;
	}
	
	//returns address of your new static array
	return b;
}

//performs algorithm in O(n)
int* algorithmN(int n[], int s)throw (invalid_argument){
	//allocate a dynamic array so you can return its address
	int *b;
	b = new int[s];
	int product = 1;
	
	//make product of 
	for(int i = 0; i < s; ++i){
		if(n[i] == 0)
			throw invalid_argument("cannot handle arrays with any value equal to zero");
		product *= n[i];
	}	
	
	//each item in b is simply the product of all numbers divided by the corosponding entry in n[i]
	for(int i = 0; i < s; ++i)
		b[i] = product / n[i];
	
	//return address of new array
	return b;
}

//for displaying output of any array with address ptr, and size s
void display(int *ptr, int s){
	cout << "{";
	for(int i = 0; i < s; ++i){
		cout << ptr[i];
		if(i != s-1)
			cout << ", ";
	}
	cout << "}" << endl;
}