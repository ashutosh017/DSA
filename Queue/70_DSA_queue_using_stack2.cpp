#include<iostream>
using namespace std;
#include<stack>

class queue{
    stack<int> s1,s2;
    public:
    void enQueue(int x){
        s1.push(x);
    }
    int dequeue(){
        if(s1.empty() && s2.empty())return INT32_MIN;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

};
int main(){
    queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}