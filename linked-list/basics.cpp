// Online C++ compiler to run C++ program online
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void insertBegin(struct Node** head_ref, int new_data){
    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
    
    new_node->data=new_data;
    new_node->next=(*head_ref);
    
    (*head_ref)=new_node;
} 

void insertEnd(struct Node** head_ref, int new_data){
    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
    
    new_node->data=new_data;
    new_node->next=NULL;
    
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    struct Node *last=*head_ref;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
}

void deleteEnd(struct Node** head_ref){
    if(*head_ref==NULL){
        cout<<"no node to delete";
        return;
    }
    struct Node *temp;
    struct Node *last=*head_ref;
    if(last->next==NULL){
        *head_ref=NULL;
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

void deleteBegin(struct Node** head_ref){
    if(*head_ref==NULL){
        cout<<"No node to delete";
        return;
    }
    struct Node *temp;
    struct Node *last=*head_ref;
    if(last->next==NULL){
        *head_ref=NULL;
        free(last);
        return;
    }
    *head_ref=last->next;
    free(last);
    return;
}

void printList(struct Node *node){
    while(node!=NULL){
        cout<<"->"<<node->data;
        node=node->next;
    }
    cout<<"\n";
}

void insertPos(struct Node** head_ref, int new_data,int pos){
    if(pos==1){
        insertBegin(head_ref, new_data);
        return;
    }
    struct Node *temp=*head_ref;
    
    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
    new_node->data=new_data;
    for(int i=2; i<pos;i++){
        temp=temp->next;
        if(temp->next==NULL){
            cout<<"Invalid position \n";
            return;
        }
    }
    new_node->next=temp->next;
    temp->next=new_node;
    return;
}

void deletePos(struct Node** head_ref, int pos){
    if(*head_ref==NULL){
        cout<<"No node to delete";
        return;
    }
    if(pos==1){
        deleteBegin(head_ref);
    }
    struct Node *temp=*head_ref;
    struct Node *del;
    for(int i=2; i<pos; i++){
        temp=temp->next;
    }
    del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return;
}

void search(struct Node *node, int data){
    int i=1;
    while(node!=NULL){
        if(node->data==data){
            cout<<data<< " found at position: "<<i;
            return;
        }
        node=node->next;
        i++;
    }
    cout<<"\n Not found";
}

void sort(struct Node **head_ref){
    struct Node *current=*head_ref;
    struct Node *index=NULL;
    int temp;
    if(*head_ref==NULL){
        return;
    }
    while(current!=NULL){
        index=current->next;
        while(index!=NULL){
            if(current->data>=index->data){
                temp=current->data;
                current->data=index->data;
                index->data=temp;
            }
            index=index->next;
        }
        current=current->next;
    }
}
int main() {
    struct Node *head=NULL;
    
    insertBegin(&head, 1);
    insertBegin(&head, 2);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    insertEnd(&head, 7);
    insertPos(&head, 99, 1);
    printList(head);
    sort(&head);
    printList(head);
    search(head,100);
    return 0;
}