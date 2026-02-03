#include <iostream>
#include <vector>
using namespace std;

class Stack{
    vector<int> v; // this is our stack
public:
    bool isEmpty(){
        return v.size()==0;
    }
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        if(isEmpty()) return;
        v.pop_back();
    }
    void peek(){
        if(isEmpty()) return;
        cout<<"TOP: "<<v[v.size()-1]<<endl;
    }

};

int main(){
    Stack s;
    s.push(4);
    s.push(3);
    s.peek();
    s.push(2);
    s.push(1);
    s.push(0);
    s.peek();
    s.pop();
    s.peek();


    return 0;
}