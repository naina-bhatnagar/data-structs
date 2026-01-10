#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // defining a string
    string str1 = "this is cpp"; // dynamic (can be changed), // contiguous
    cout<< str1 << endl;

    str1 = "string2"; // this **
    cout<<"Modified string: "<< str1 << endl;

    //combining strings : concatenation
    string str2 = " is the modified string"; // and this **
    string str3 = str1 + str2;
    cout<< str3<< endl;

    //compairing two strings...
    cout<<(str2==str3)<<endl; // false --> 0
    cout<<(str1<str2)<<endl; // alphabetically s>i : false --> 0
    
    // to find length of the string : name.length()
    cout<<str1.length()<<endl; // 7

    // to take input : getline(cin,str_name)
    string str4;
    getline(cin,str4);
    cout<<"Output: "<<str4<<endl;

    //loops
    for(int i=0;i<str4.length();i++){
        cout<<str4[i]<<" ";
    }
    cout<<endl;

    for(char el : str4){
        cout<<el<<" ";
    }
    cout<<endl;

    // reversing a string
    reverse(str4.begin(),str4.end());
    cout<<str4<<endl;

    return 0;
}