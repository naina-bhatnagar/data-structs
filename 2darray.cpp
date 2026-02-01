#include <iostream>
#include <vector>
using namespace std;

// here we define our linear search function...
vector<int> linearSearch(int mat[][3],int row, int col, int key){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==key){
                return {i,j};
            }
        }
    }
    return {-1,-1}; // return pair (this is not)
}

int main(){
    // define an empty matrix
    int mat[4][3] ;
    int row = 4, col=3;

    // input
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Input: ";
            cin>>mat[i][j];
        }
    }

    // printing the contents
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    // the elements of a 2d array are stored in the memory in two ways:-
    // 1. row major
    // 1. column major

    // Linear Search...
    int key;
    cout<<"To search for: ";
    cin>>key;

    cout<<"the location of the key in the array: "<<endl;
    for(int el : linearSearch(mat, row, col, key)){
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}