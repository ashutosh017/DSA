// Doubly Linked list
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
};

void display(node *head){
    if(head==NULL)return;
    node *temp = head;
    do{
        cout<<temp->data<<" ";    
        temp = temp->next;
    }
    while(temp!=NULL);
    cout<<endl;
}
// Insertion methods
void insertAtFirst(node **head,int val){
    if(*head==NULL){
        (*head)->data = val;
        return;
    }
    node *new_node = new node();
    new_node->data = val;
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

void insertAtLast(node *head,int val){
    if(head==NULL){
        (head)->data = val;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    node *new_node = new node();
    temp->next = new_node;
    new_node->prev = temp;
    new_node->data = val;

}

void insertAfterGivenPosition(node *head,int position,int val){
    if(head==NULL){
        (head)->data = val;
        return;
    }
    node *temp = head,*new_node = new node();
    new_node->data = val;
    for (int i = 0; i < position-1 && temp->next!=NULL; i++)
        temp = temp->next;
    if(temp->next!=NULL){
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
    else{
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insertAfterKey(node *head,int key,int data){
    if(head==NULL){
        head->data = key;
        return;
    }
    node *new_node = new node();
    new_node->data = data;
    node *temp = head;
    while(temp->data!=key){
        temp = temp->next;
        if(temp==NULL){
            return;
        }
    }
    if(temp->next==NULL){
        temp->next = new_node;
        new_node->prev = temp;
    }
    else{
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void deleteWithKey(node **head,int key){
    node *temp = *head;
    if(temp->data ==key && temp->next==NULL){
        delete temp;
        return;
    }
    while(temp->data!=key){
        temp = temp->next;
        if(temp==NULL)
            return;        
    }
    if(temp->next==NULL)
        delete temp;
    else if(temp->prev ==NULL){
        *head = temp->next;
        delete temp;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

}
int main(){
    node *head = new node();
    head->data = 1;
    // Insertion methods
    insertAtFirst(&head,12);
    insertAtLast(head,8);
    insertAfterGivenPosition(head,2,10);
    insertAfterKey(head,1,6);

    // Deletion methods
    display(head);
    deleteWithKey(&head,12);
    display(head);
    
    return 0;
}