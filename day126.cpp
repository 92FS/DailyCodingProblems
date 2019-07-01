//JMT June 30, 2019 DCP #126
#include <iostream>

using namespace std;

//prototypes
void rotate( int ls[], const int &inter, const int size );
void printList( int ls[], const int &size );

int main(){

    const int SIZE = 6;
    int interval = 2;
    int list[SIZE] = { 1, 2, 3, 4, 5, 6 };

    cout << "list rotation by: " << SIZE << endl;
    printList( list, SIZE );
    rotate( list, interval, SIZE );
    printList( list, SIZE );
    
    return 0;
}

void rotate( int ls[], const int &inter, const int size ){
    int h;
    for( int i = 0; i + inter < size; ++i ){
        h = ls[i];
        ls[i] = ls[ i + inter ];
        ls[ i + inter ] = h;
        //printList(ls, size);
    }
}

void printList( int ls[], const int &size ){
    for( int i = 0; i < size; ++i )
        cout << ls[i] << " ";
    
    cout << endl;
}
