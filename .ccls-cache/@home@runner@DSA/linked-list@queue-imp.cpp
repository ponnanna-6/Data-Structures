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
        cout<<"Queue is empty";
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

void insertBegin(struct Node** head, int new_data){
    struct Node* node=(struct Node*) malloc(sizeof(struct Node));
    
    node->data=new_data;
    if(*head==NULL){
        *head=node;
        return;
    }
    node->next=*head;
    *head=node;
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
        cout<<"QUEUE USING LINKED LIST\nPress 1 to enqueue;Press 2 to dequeue:\n";
        cin>>op;
        if(op==1){
            cout<<"Enter number to insert: ";
            cin>>num;
            insertBegin(&head, num);
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