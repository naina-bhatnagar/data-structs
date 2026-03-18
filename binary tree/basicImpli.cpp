#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;

    Node(int v){
        val = v;
        left = right = nullptr;
    }
};

Node* buildBTree(vector<int> &preorder, int &idx){
    idx ++;
    if(preorder[idx]==-1) return nullptr;
    Node *root = new Node(preorder[idx]);
    root->left = buildBTree(preorder,idx);
    root->right = buildBTree(preorder,idx);
    return root;
}

void preorder(Node* root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    vector <int> pre_order = {1, 2, 4, -1, -1, 5, 6, -1, -1, -1, 3, 7, -1, -1, 8, 9, -1, -1, 10, -1, -1};
    int idx = -1;
    Node *head = buildBTree(pre_order,idx);
    preorder(head);
    cout<<endl;
    inorder(head);
    cout<<endl;
    postorder(head);
    return 0;
}