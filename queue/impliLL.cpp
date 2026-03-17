#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int v){
        val = v;
        next = nullptr;
    }
};

class Queue{
public:
    Node *front;
    Node *rear;
    Queue(){
        front = rear = nullptr;
    }

    void push(int val){
        Node *ptr = new Node(val);
        if(rear == nullptr){
            front = rear = ptr;
        }else{
            rear->next = ptr;
            rear = ptr;
        }
    }

    void pop(){
        if(front == nullptr) return;
        Node *ptr = front->next;
        delete front;
        front = ptr;
        if(front == nullptr) rear = nullptr;
    }

    int peek(){
        if(front == nullptr) return -1;
        return front->val;
    }

    ~Queue(){
        while(front != nullptr){
            pop();
        }
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    return 0;
}