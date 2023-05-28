#include<iostream>
using namespace std;
class Queue{
    public:
    int data,front,rear,size=10,*arr;
    Queue(){front=rear=-1; arr = new int[size];}
    bool isEmpty(){
        if(rear<0)return true;
        return false;
    }
    bool isFull(){
        if(rear>=size-1)return true;
        return false;
    }
    void enqueue(int x){
        if(isFull())return;
        if(front<0)front++;
        arr[++rear] = x;
    }
    int dequeue(){
        if(isEmpty())return -1;
        return arr[front++];
    }
    int frontElem(){
        return arr[front];
    }
    int rearElem(){
        return arr[rear];
    }
    void display(){
        for (int i = 0; i < size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    Queue q;
    for (int i = 0; i < q.size; i++)
        q.enqueue(i+1);
    q.display();
    return 0;
}