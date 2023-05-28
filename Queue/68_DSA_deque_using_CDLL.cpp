#include<iostream>
using namespace std;

class node{
    public:
    node *prev,*next;
    int data;
};

class deque{
    public:
    node *f,*r;
    deque(){
        f=r=NULL;
    }
    void enQueue(int x){
        node *temp = new node();
        temp->data = x;
        if(f==NULL){
            f=r=temp;
            temp->prev = temp;
            temp->next = temp;
            return;
        }
        r->next = temp;
        temp->next = f;
        temp->prev = r;
        f->prev = temp;
        r = temp;
    }
    int deQueue(){
        if(f==NULL)return -1;
        node *temp = f;
        int data = f->data;
        r->next = f->next;
        f->next->prev = r;
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
    deque q;
    q.enQueue(4);
    q.enQueue(41);
    q.enQueue(42);
    q.deQueue();
    q.display();
    return 0;
}