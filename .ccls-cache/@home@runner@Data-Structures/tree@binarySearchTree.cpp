#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

int height(struct Node* root){
  if(root==NULL)return 0;
  int leftH, rightH;
  
  leftH=height(root->left);
  rightH=height(root->right);
  return max(leftH, rightH)+1;
  
}

void boundary(struct Node* root){
  //Code pending
  
}

struct Node *create(int key){
  struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
  newNode->data=key;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}

struct Node *minValueNode(struct Node *node){
  struct Node* current = node;
  while(current && current->left!=NULL){
    current=current->left;
  }
  return current;
}

struct Node *deleteNode(struct Node* root, int key){
  if(root==NULL)return root;
  if(key< root->data){
    root->left=deleteNode(root->left, key);
  }else if(key>root->data){
    root->right=deleteNode(root->right, key);
  }else{
    if(root->left==NULL){
      struct Node* temp=root->right;
      free(root);
      return temp;
    }else if(root->right==NULL){
      struct Node* temp=root->left;
      free(root);
      return temp;
    }
    struct Node* min=minValueNode(root->right);
    root->data=min->data;
    root->right = deleteNode(root->right, min->data);
  }
  return root;
}

struct Node *insertNode(struct Node* node, int key){
  if(node==NULL){
    return create(key);
  }
  if(key<node->data){
    node->left=insertNode(node->left, key);
  }else{
    node->right=insertNode(node->right, key);    
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
  int n, nodeData, del;
  cout<<"Enter number of nodes to enter: ";
  cin>>n;
  for(int i=1; i<=n; i++){
    cout<<"Enter node "<<i<<": ";
    cin>>nodeData;
    root=insertNode(root, nodeData);
  }
    
  cout<<"INORDER TRANSVERSAL:\n";    
  inorder(root);  
  cout<<endl;
  cout<<"\nEnter Node to delete: ";
  cin>>del;
  root=deleteNode(root, del);
  cout<<"\nINORDER TRANSVERSAL AFTER DELETION:\n";
  inorder(root);
  cout<<"\nHeight: "<<height(root)-1;
  return 0;
}