#include<iostream>
using namespace std;

class QNode{
    public:
    int data;
    QNode *next;
    QNode(int x){
        data = x;
        next = NULL;
    }
};
class Queue{
    QNode *front,*rear;
    public:
    Queue(){
        front = rear = NULL;
    }
    void enQueue(int x){
        QNode *temp = new QNode(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void deQueue(){
        if(front ==NULL)return;
        QNode *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
    void display(){
        QNode *temp = front;
        if(temp==NULL)return;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp!=NULL);
        cout<<endl;
    }
};
int main(){
    Queue qn;
    for (int i = 0; i < 12; i++)
        qn.enQueue(i+1);
    qn.display();
    for (int i = 0; i < 11; i++)
        qn.deQueue();
    qn.display();
    cout<<"done"<<endl;
    

    return 0;
}