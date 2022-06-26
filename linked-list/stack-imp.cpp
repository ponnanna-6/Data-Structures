// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};

void deleteEnd(struct Node** head){
    if(*head==NULL){
        cout<<"Stack is empty";
        return;
    }
    struct Node* last = *head;
    struct Node* temp;
    if(last->next==NULL){
        *head=NULL;
        free(last);
        return;
    }
    while(last->next->next!=NULL){
        last=last->next;
    }
    temp=last->next;
    last->next=NULL;
    free(temp);
    return;
}

void insertEnd(struct Node** head, int new_data){
    struct Node* node=(struct Node*) malloc(sizeof(struct Node));
    
    node->data=new_data;
    node->next=NULL;
    if(*head==NULL){
        *head=node;
        return;
    }
    struct Node *last=*head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=node;
    return;
}

void printList(struct Node *node){
    while(node!=NULL){
        cout<<"->"<<node->data;
        node=node->next;
    }
    cout<<"\n";
}

int main() {
    struct Node* head=NULL;
    while(1){
        int op=0, num;
        cout<<"Press 1 to insert;Press 2 to delete:\n";
        cin>>op;
        if(op==1){
            cout<<"Enter number to insert: ";
            cin>>num;
            insertEnd(&head, num);
            printList(head);
        }else if(op==2){
            deleteEnd(&head);
            printList(head);
        }else{
            cout<<"Enter 1 or 2:\n";
            continue;
        }
    }
}

