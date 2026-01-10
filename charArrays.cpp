#include <iostream>
#include <cstring>
using namespace std;

int main(){
    // defining strings... 
    char str1[] = {'N','a','i','n','a','\0'}; // (it is an array of characters with end: '\0')
    char str2[] = "hello"; // this is a string literal

    // concatenates on printing
    cout<< str1 <<endl;
    // to find length: strlen
    cout<< strlen(str2)<<endl; // cstring header required...

    // indexing possible. (contiguously stored data) (end: /0)
    cout<<str2[2]<<" "<<str2[5]<<" "<< str1[0]<<endl;

    // unintialized string
    char str3[100];

    cout<<"Provide a character array: ";
    cin>> str3;

    // printing the string taken as input:
    cout<<"The character array you entered is: "<<str3<<endl;

    // the above method with cin cannot save sentences. it ignores anything that is mentioned beyond a '\s'
    // we use cin.getline(str,len,delimiter)... {delimeter: the char at which line should be ended, def: \n}

    cin.getline(str3,100);
    cout<<str3<<endl;

    // to find the length of a char array with a loop...
    char str4[] = "This is an example!";
    int carrlen = 0;
    for(int i=0;str4[i]!='\0';i++){
        carrlen ++;
    }
    cout<<"Length of char array is: "<<carrlen<<endl;

    return 0;
}