#include<iostream>
using namespace std;

class node{
    public:
    node *prev;
    int data;
    node *next;
};
void display(node *head){
    node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while(temp!=head);
    cout<<endl;
}
void insertAtFirst(node **head,int key){
    node *n = new node(),*temp = *head;
    n->data = key;
    n->next = *head;
    while(temp->next!=*head){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    (*head)->prev = n;
    *head = n;
}

void insertAtLast(node *head,int key){
    node *n = new node();
    n->data = key;
    n->next = head;
    node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    head->prev = n;
}

void insertAfterKey(node *head,int key,int val){
    node *n = new node();
    n->data = val;
    node *temp = head;
    while(temp->data!=key){
        temp = temp->next;
        if(temp==head)return;
    }
    if(temp->next==temp){
        insertAtLast(head,val);
        return;
    }
    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
}

void deleteKey(node **head,int key){
    if((*head)->data ==key && (*head)->next==*head){
        delete *head;
        return;
    }
    node *temp = *head,*d=*head;
    while(d->data!=key){
        d=d->next;
        if(d==*head)return;
    }
    if(d==*head){
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
        delete d;
        return;
    }
    d->prev->next = d->next;
    d->next->prev = d->prev;
    delete d;
}
int main(){
    node *head = new node();
    head->data = 2;
    head->prev = head;
    head->next = head;
    insertAtFirst(&head,1);
    insertAtLast(head,3);
    insertAfterKey(head,3,5);
    display(head);
    deleteKey(&head,2);
    display(head);
    

    return 0;
}