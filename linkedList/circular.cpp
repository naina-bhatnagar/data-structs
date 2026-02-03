#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class CLL{
    Node *head = NULL;
    Node *tail = NULL;

public:
    CLL(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node *ptr = new Node(val);
        if(head == NULL){
            head = tail = ptr;
            tail->next = head;
            return;
        }
        ptr->next = head;
        head = ptr;
        tail->next = head;
    }

    void pop_front(){
        if(head==NULL) return;
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node *tmp = head;
        head = head->next;
        tail->next = head;
        delete tmp;
    }

    int peek_front(){
        if(head==NULL) return -1;
        return head->val;
    }
    
    void push_back(int val){
        if(tail==NULL){
            push_front(val); return;
        }
        Node *ptr = new Node(val);
        tail->next = ptr;
        tail = ptr;
        tail->next = head;
    }

    void pop_back(){
        if(tail==NULL || tail==head){
            pop_front(); return;
        }
        Node *ptr = head;
        while(ptr->next != tail){
            ptr = ptr->next;
        }
        delete tail;
        tail = ptr;
        ptr->next = head;
    }

    int peek_back(){
        if(tail==NULL) return -1;
        return tail->val;
    }

    void display(){
        if(head==NULL) return;
        Node *ptr = head;
        do{
            cout<<ptr->val<<" -> ";
            ptr = ptr->next;
        }while(ptr !=head);
        cout<<"(HEAD)"<<endl;
    }

    ~CLL(){
        while(head!=NULL){
            pop_front();
        }
    }
};

int main(){
    CLL l;
    
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_front(0);
    l.push_back(4);
    cout<<l.peek_front()<<endl;
    cout<<l.peek_back()<<endl;
    l.pop_front();
    l.pop_back();
    l.display();

    return 0;
}