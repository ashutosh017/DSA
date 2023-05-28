#include<iostream>
using namespace std;

void swap(int *arr1,int*arr2){
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
// Implimenting function for insertion sort
void insertionSort(int *arr,int n){
    // for (int i = 1; i <= n-1; i++)
    // {
    //     int j = i;
    //     while(j>0 && arr[j-1]>arr[j]){
    //         int temp = arr[j-1];
    //         arr[j-1] = arr[j];
    //         arr[j] = temp;
    //         j--;
    //     }
    // }    

    for (int i = 1; i < n; i++)
        for (int j = i; j; j--)
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);        
}

int main(){
    int n; //--> Size of array
    cin>>n;
    int *arr =new int[n];
    for (int i = 0; i < n; i++)
    cin>>arr[i]; //--> Taking array integers as input

    insertionSort(arr,n); // -->Calling insertion sort function

    // Finally printing the sorted array
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;    
}