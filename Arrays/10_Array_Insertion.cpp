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

int sortedInsertion(int arr[], int size, int element, int capacity, int index){
    // Code for Insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    
}   
int main(){
    int arr[100] = {7,8,12,27,88};
    display(arr,5);
    int element = 45, size = 5, index = 3;
    sortedInsertion(arr, size, element, 100, index);
    size++;
    display(arr,size);
    return 0;
}