// Online C compiler to run C program online
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<"->"<<root->data;
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<"->"<<root->data;
    preorder(root->left);
    
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    
    cout<<"->"<<root->data;
}

int main() {
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(5);
    
    cout<<"INORDER TRANSVERSAL:\n";
    inorder(root);
    
    cout<<"\nPOSTORDER TRANSVERSAL:\n";
    postorder(root);
    cout<<"\nPREORDER TRANSVERSAL:\n";
    preorder(root);
    return 0;
}