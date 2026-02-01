#include <iostream>
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

class List{
    Node* head;

public:
    List(){
        head = NULL; // we can add a tail to make tc of rear ops O(1)
    }

    void push_front(int val){
        Node* ptr = new Node(val); // dynamic : we can not use the static method: Node ptr(val) {instantiation}
        ptr->next = head;
        head = ptr;
    }

    void pop_front(){
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int peek_front(){
        if (head == NULL) return 0;
        return head->val;
    }
    
    void push_back(int val){
        Node *ptr = new Node(val);
        if(head==NULL){
            head = ptr;
            return;
        }
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = ptr;
    }

    void pop_back(){
        if(head==NULL) return;
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
    
    int peek_back(){
        if(head == NULL) return 0;
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        return temp->val;
    }

    void printll(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void midinsert(int val, int pos){
        if(pos < 0) return;
        if(pos == 0){
            push_front(val);
            return;
        }
        Node *temp = head;
        int ctr = 0;
        while(ctr < pos-1){
            if(temp == NULL) return;
            temp = temp->next;
            ctr ++;
        }
        if(temp == NULL) return;
        
        Node *ptr = new Node(val);
        ptr->next = temp->next;
        temp->next = ptr;
    }

    int search(int val){
        if(head==NULL) return -1;
        int ctr = 0;
        Node *temp = head;
        while(temp != NULL){
            if(temp->val == val) return ctr;
            temp = temp->next;
            ctr ++;
        }
        return -1;
    }

    ~List(){
        while(head!=NULL){
            pop_front();
        }
    }

};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.pop_front();
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.pop_back();
    cout<<"the front el is: "<<ll.peek_front()<<endl;
    cout<<"the rear el is: "<<ll.peek_back()<<endl;
    ll.printll();
    ll.midinsert(6,5);
    ll.midinsert(7,6);
    ll.printll();
    cout<<"found 4 at: "<<ll.search(4)<<endl;
    return 0;
}