#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};
class queue{
    public:
    node *f,*r;
    queue(){
        f=r=NULL;
    }
    void enQueue(int x){
        node *temp = new node();
        temp->data = x;
        if(f==NULL){
            f=r=temp;
            temp->next = f;
            return;
        }           
        r->next = temp;
        r = temp;
        r->next = f;
    }
    int deQueue(){
        if(f==NULL)return -1;
        node *temp = f;
        int data = temp->data;
        r->next = f->next;
        f = f->next;
        delete temp;
        return data;
    }
    void display(){
        node *temp = f;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while (temp!=f);
        cout<<endl;
    }
};


int main(){
    queue q;
    q.enQueue(4);
    q.enQueue(41);
    q.enQueue(42);
    q.deQueue();
    q.display();
    return 0;
}