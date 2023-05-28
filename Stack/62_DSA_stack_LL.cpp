#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};
int isEmpty(node *head){
    return head==NULL;
}
void display(node *head){
    if(isEmpty(head))return;
    while(head!=NULL){
        node *temp = head;
        cout<<temp->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void push(node **head,int x){
    node *temp = new node();
    temp->data = x;
    temp->next = *head;
    *head = temp;
}
int pop(node **head){
    if(isEmpty(*head))return 0;
    node *temp = *head;
    int poped = (*head)->data;
    *head = (*head)->next;
    delete temp;
    return poped;
}
int peek(node *head){
    cout<<head->data<<endl;
}

int main(){
    node *root = new node();
    root->data = 1;
    if(root)cout<<"Yes "<<root->data<<endl;
    else cout<<"No"<<endl;

    peek(root);
    push(&root,10);
    push(&root,11);
    push(&root,12);
    push(&root,13);
    peek(root);
    display(root);
    peek(root);
    return 0;
}