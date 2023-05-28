#include<iostream>
using namespace std;

// Implimenting function for selection sort
void selectionSort(int *arr,int n){
    for (int i = 0; i < n-1; i++)
    {
        int min_ind = i;
        for (int k = i+1; k < n-1; k++)
            if(arr[min_ind]>arr[k]) //-->Here i'm searching for the index at which minimum value is present
                min_ind = k;        //   so that i can replace that value at min_ind with the starting position 
        if(min_ind!=i){             //   of the array
        int temp = arr[i];          
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
        }
    }    
}

int main(){
    int n; //--> Size of array
    cin>>n;
    int *arr =new int[n];
    for (int i = 0; i < n; i++)
    cin>>arr[i]; //--> Taking array integers as input

    selectionSort(arr,n); // -->Calling selection sort function

    // Finally printing the sorted array
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;    
}