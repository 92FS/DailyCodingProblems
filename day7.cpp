/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/
#include <string>
#include <iostream>

using namespace std;

int toChar(int);
int possible(int);

int main(){
	int j;
	cout << "input a string of integers: ";
	cin >> j;
	
	cout << possible(j) << endl;
	
	return 0;
}

int possible(int n){
	string test = to_string(n);
	int count = 0;
	for(int i = 0; i < test.length(); ++i){
		++count;
		if(i == test.length())
			continue;
		for(int j = i+1; j < test.length(); ++j){
			if(test[i] == 1)
				++count;
			else if(test[i] == 2 && test[j] <= 6)
				++count;
		}
	}
	return count;
}