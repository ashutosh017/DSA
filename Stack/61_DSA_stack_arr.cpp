#include<iostream>
using namespace std;

class stack{
    int top;
    public:
    int size;
    int *arr;
    stack(){
        top=-1;
        size =10;
        arr = new int[size];
    }
    void push(int x);
    int pop();
    void display();
    int peek();
    bool isFull();
    bool isEmpty();
    // int stackTop();
    // int stackBottom();
};
bool stack::isFull(){
    if(top>=size-1)return 1;
    return 0;
}
bool stack::isEmpty(){
    if(top<0)return 1;
    return 0;
}

void stack::push(int x){
    if(isFull())return;
    arr[++top] = x;
} 
int stack::pop(){
    if(isEmpty())return 0;
    return arr[top--];
}
int stack::peek(){
    if(isEmpty())return 0;
    return arr[top];
}

void stack::display(){
    while(!isEmpty()){
        cout<<peek()<<" ";
        pop();
    }
    cout<<endl;
}
int main(){

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    return 0;
}