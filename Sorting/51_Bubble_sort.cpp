#include<iostream>
using namespace std;

int main(){
    int n; //--> Size of array
    cin>>n;
    int *arr =new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i]; //--> Taking array integers as input
    
    // This is Bubble sort algorithem
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }        
    }
    
    // Finally printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}