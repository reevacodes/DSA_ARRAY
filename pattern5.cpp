#include<bits/stdc++.h>
using namespace std;

void print(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    print(n);
}