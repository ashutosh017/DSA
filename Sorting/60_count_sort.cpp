#include<iostream>
using namespace std;

int main(){
    int *arr,*arr2,n,max=0;
    cin>>n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(max<arr[i])max=arr[i];
    }
    max++;
    arr2 = new int[max];
    for (int i = 0; i < max; i++)
        arr2[i] = 0;
    for (int i = 0; i < max; i++)
        arr2[arr[i]]+=1;
    for (int i = 0; i < max; i++)
        if(arr2[i]!=0)
            for(int j=0;j<arr2[i];j++)cout<<i<<" ";
    cout<<endl;
    
    
    return 0;
}