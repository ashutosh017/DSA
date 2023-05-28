#include<iostream>
using namespace std;
class CQueue{
    public:
    int data,size=10,*arr,front,rear;
    CQueue(){
        front=rear=-1;
        arr = new int[size];
    }
    bool isEmpty();
    bool isFull();
    int frontElem();
    int rearElem();
    void enQueue(int x);
    int deQueue();
    void display();
};  
bool CQueue::isEmpty(){
    return front==-1;
}
bool CQueue::isFull(){
    if((front==0 &&rear==size-1)||(rear==front-1))return 1;
    return 0;
}
int CQueue::frontElem(){
    return arr[front];
}
int CQueue::rearElem(){
    return arr[rear];
}
void CQueue::enQueue(int x){
    if(isFull())return;
    if(isEmpty()){
        front=rear=0;
        arr[rear] =x;
    }
    else if(front!=0 &&rear==size-1){
        rear = 0;
        arr[rear] = x;
    }
    else arr[++rear]=x;
}
int CQueue::deQueue(){
    if(isEmpty())return -1;
    int data = arr[front];
    arr[front] = -1;
    if(front==rear)
        front = rear = -1;
    else if(front ==size-1)front = 0;
    else front++;
    return data;
}
void CQueue::display(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    if(rear>=front)
        for (int i = front; i <=rear; i++)
            cout<<arr[i]<<" ";
    else{
        for (int i = front; i < size; i++)
            cout<<arr[i]<<" ";
        for (int i = 0; i <=rear; i++)
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    CQueue q;
    for (int i = 0; i <q.size; i++)
        q.enQueue(i+1);
    q.display();
    return 0;
}