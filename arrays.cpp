#include <iostream>
using namespace std;

// FEATURES :-
// 1. only one type of data
// 2. occupy a contiguous block of memory
// 3. linear
// creation : (1) dtype name[size];
//            (2) dtype name[size] = {el1,el2,...,el(size)};
//            (3) dtype name[] = {el1,el2,...,el(size)};

// indexing present (startswith 0) : eg : name[index]


int main(){
    int size;
    cout<<"Provide size of array: ";
    cin>>size;
    
    int marks[size];

    for(int i=0;i<size;i++){ // takes input using a loop
        cin>>marks[i];
    }

    for(int i=0;i<size;i++){ // prints the elements of the array
        cout<<marks[i]<<" ";
    }
    cout<<endl;

    int minval = INT8_MAX;
    int maxval = INT8_MIN;

    for(int i=0;i<size;i++){
        if(marks[i]<minval){ // to find the minimum value in an array: use INT_MAX
            minval = marks[i];
        }
        maxval = max(maxval,marks[i]); // to find the maximum value in an array: using max function
    
    }
    cout<<"the minimum value in the array is: "<<minval<<endl;
    cout<<"the maximum value in the array is: "<<maxval<<endl;

    

    return 0;
}