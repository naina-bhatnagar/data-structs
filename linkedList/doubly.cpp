#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val){
        this->val = val;
        this->prev = this->next = NULL;
    }
};

class DLL{
    Node *head;
    Node *tail;

public:
    // constructor...
    DLL(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node *ptr = new Node(val);
        if(head==NULL){
            head = tail = ptr;
            return;
        }
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }

    void pop_front(){
        if(head == NULL) return;
        if(head->next == NULL){
            delete head;
            head = tail = NULL;
            return;
        }
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }

    int peek_front(){
        if(head==NULL) return -1;
        return head->val;
    }

    void push_back(int val){
        Node *ptr = new Node(val);
        if(tail == NULL){
            head = tail = ptr;
            return;
        }
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }

    void pop_back(){
        if(tail==NULL) return;
        if(tail->prev==NULL){
            delete tail;
            head = tail = NULL;
            return;
        }
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }

    int peek_back(){
        if(tail==NULL) return -1;
        return tail->val;
    }

    void display(){
        if(head==NULL) return;
        Node* ptr = head;
        while(ptr!=NULL){
            cout<<ptr->val<<" -> ";
            ptr = ptr->next;
        }
        cout<<endl;
    }

    void revdisplay(){
        if(tail==NULL) return;
        Node* ptr = tail;
        while(ptr!=NULL){
            cout<<ptr->val<<" -> ";
            ptr = ptr->prev;
        }
        cout<<endl;
    }

    void midInsert(int val, int pos){
        if(pos<0){ // reverse midInsert !
            if(tail==NULL || pos == -1){push_back(val); return;}
            Node *ptr = tail;

            for(int i=-1;i>pos+1;i--){
                if(ptr==NULL) return;
                ptr = ptr->prev;
            }
            if(ptr==head){push_front(val); return;}
            Node *n = new Node(val);
            n->next = ptr;
            n->prev = ptr->prev;
            ptr->prev = n;
            n->prev->next = n;
            return;
        }
        if(head==NULL || pos == 0){
            push_front(val);
            return;
        }
        Node *ptr = head;

        for(int i=0;i<pos-1;i++){
            if(ptr==NULL) return;
            ptr = ptr->next;
        }
        if(ptr==tail){push_back(val); return;}
        Node *n = new Node(val);
        n->prev = ptr;
        n->next = ptr->next;
        ptr->next = n;
        n->next->prev = n;
    }

    int search(int val){
        if(head==NULL) return -1;
        Node *ptr = head;
        int ctr = 0;
        while(ptr!=NULL){
            if(ptr->val==val) return ctr;
            ctr++;
            ptr = ptr->next;
        }
        return -1;
    }

    ~DLL(){
        while(head != NULL){
            pop_front();
        }
    }

};

int main(){
    DLL dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);
    dll.midInsert(8,-5);
    dll.display();
    dll.revdisplay();

    return 0;
}