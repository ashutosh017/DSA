// Circular Linked list
#include<iostream>
using namespace std;

class node{
    public:
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

// Insertion methods
void insertAtFirst(node **head_ref,int data){
    node *new_node = new node();
    new_node->data = data;
    new_node->next = *head_ref;
    node *temp = *head_ref;
    while(temp->next!=*head_ref){
        temp = temp->next;
    }
    temp->next = new_node;
    *head_ref = new_node;
}
void insertAtLast(node **head_ref,int data){
    node *new_node = new node();
    new_node->data = data;
    new_node->next = *head_ref;
    node *temp = *head_ref;
    while(temp->next!=*head_ref){
        temp = temp->next;
    }
    temp->next = new_node;
}
void insertAtGivenPosition(node *head_ref,int position,int val){
    node *temp = head_ref;
    for (int i = 0; i < position-1; i++)
        temp = temp->next;
    node *new_node = new node();
    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
}
void insertAfterGivenVal(node *head,int givenVal,int val){
    node *new_node = new node();
    new_node->data = val;
    node *temp = head;
    while(temp->data!=givenVal){
        temp = temp->next;
        if(temp==head)return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Deletion in Circular linked list
void deleteNodeWithGivenKey(node **head,int key){
    if(*head==NULL)return;
    if((*head)->data==key && (*head)->next==*head){
        delete (*head);
        *head = NULL;
        return;
    }
    node *last=*head,*d;
    if((*head)->data == key){
        while(last->next!=*head)
            last = last->next;
        last->next = (*head)->next;
        delete *head;
        *head = last->next;
        return;
    }
    while(last->next!=*head && last->next->data!=key)
        last = last->next;
    if(last->next->data==key){
        d = last->next;
        last->next = d->next;
        delete d;
    }
    
}
int main(){
    node *head = new node();
    head->data = 1;
    head->next = head;
    insertAtFirst(&head,12);
    insertAtLast(&head,3);
    insertAtGivenPosition(head,3,44);
    insertAfterGivenVal(head,44,45);
    display(head);

    deleteNodeWithGivenKey(&head,44);
    display(head);

    return 0;

}