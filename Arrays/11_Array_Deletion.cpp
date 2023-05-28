#include<iostream>
using namespace std;

void display(int arr[],int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int indDeletion(int arr[], int size, int index){
    // Code for Deletion

    for (int i = index; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }

    
}   
int main(){
    int arr[100] = {7,8,12,27,88};
    display(arr,5);
    int size = 5, index = 3;
    indDeletion(arr, size, index);
    size--;
    display(arr,size);
    return 0;
}