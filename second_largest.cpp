#include<iostream>
using namespace std;

int main(){
    int size,max=0,max2=-1;
    cout<<"Enter size"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    
    for(int i=0;i<size;i++){
        if(arr[i]>max2&&arr[i]<max){
            max2=arr[i];
        }
    }
    cout<<"Second largest element "<<max2;
    return 0;
}