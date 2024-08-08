#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int temp=arr[0];
    for(int i=1;i<size;i++){
        arr[i-1]=arr[i];
    }
    arr[size-1]=temp;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// space complexity- O(n)
// Extra space- O(1)

// Time complexity- O(n)