#include<bits/stdc++.h>
using namespace std;

void print(int n){
  for(int i=1;i<=n;i++){
        for(int j=1;j<i+1;j++){
            for(int z=j;z<=j;z++){
                cout<<z<<" ";
            } 
        }
    cout<<endl;
    }
}    

int main(){
  int n;
  cin>>n;
  print(n);
}