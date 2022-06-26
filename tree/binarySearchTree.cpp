#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *create(int key){
  struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
  newNode->data=key;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}

struct Node *insert(struct Node* node, int key){
  if(node==NULL){
    return create(key);
  }
  if(key<node->data){
    node->left=insert(node->left, key);
  }else{
    node->right=insert(node->right, key);    
  }
  return node;
}

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
  struct Node* root=NULL;
  int n, nodeData;
  cout<<"Enter number of nodes to enter: ";
  cin>>n;
  for(int i=1; i<=n; i++){
    cout<<"Enter node "<<i<<": ";
    cin>>nodeData;
    root=insert(root, nodeData);
  }
    
  cout<<"INORDER TRANSVERSAL:\n";    
  inorder(root);  
  cout<<"\nPOSTORDER TRANSVERSAL:\n";
  postorder(root);
  cout<<"\nPREORDER TRANSVERSAL:\n";
  preorder(root);
  cout<<"\n";
  return 0;
}