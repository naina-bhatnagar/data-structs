#include <iostream>
// this can also be implemented by using built-in linked list 
// #include <list>
// it has functions like : push_front, pop_front, ll.front() {the top element}, ll.size()
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Stack{
    Node *top= NULL; // this is our stack
public:
    bool isEmpty(){
        return top==NULL;
    }
    void push(int val){
        Node *ptr = new Node(val);
        if(top==NULL){
            top = ptr; return;
        }
        ptr->next = top;
        top = ptr;
    }
    void pop(){
        if(isEmpty()) return;
        Node *tmp = top->next;
        delete top;
        top = tmp;
    }

    void peek(){
        if(isEmpty()) return;
        cout<<"TOP: "<<top->val<<endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
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