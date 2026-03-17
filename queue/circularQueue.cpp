#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
public: 
    int *arr;
    int front, rear;
    int size, capacity;

    CircularQueue(int s){
        capacity = s;
        front=0, rear=-1;
        arr = new int[s];
        size = 0;
    }

    void push(int val){
        if(size >= capacity) return;
        rear = (rear+1) % capacity;
        arr[rear] = val;
        size ++;
    }

    void pop(){
        if(size == 0) return;
        front = (front + 1) % capacity;
        size --;
    }

    int peek(){
        if(size == 0) return -1;
        return arr[front];
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main(){


    return 0;
}