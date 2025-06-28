#include<bits/stdc++.h>
using namespace std;

void print(int n){
    for(int i=n;i>0;i--){
        for(int z=1;z<=i;z++){
                cout<<z<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    print(n);
    return 0;
}