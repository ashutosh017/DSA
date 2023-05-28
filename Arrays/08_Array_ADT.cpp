#include<iostream>
using namespace std;

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = new int[tSize];
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int[tSize];
}

void setVal(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        int n;
        cin>>n;
        (a->ptr)[i] = n;
    }    
}

void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<a->ptr[i]<<endl;
    }    
}

int main(){
    struct myArray marks;
    createArray(&marks,100,2);
    cout<<"We are running setVal now"<<endl;
    setVal(&marks);
    cout<<"We are running show now"<<endl;
    show(&marks);

    return 0;
}