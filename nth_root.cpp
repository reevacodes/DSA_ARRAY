#include<iostream>
using namespace std;

int func(int mid,int n,int m){
    long long ans = 1;
    for(int i = 0;i<n;i++){
        ans = ans*mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int nthRoot(int n,int m){
    int low = 1;
    int high = m;
    while(low<=high){
        int mid = (low+high)/2;
        int midN = func(mid,n,m);
        if(midN == 1){
            return mid;
        }
        else if(midN == 0) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    int n = 3;
    int m =27;
    int res = nthRoot(n,m);
    cout<<res;
    return 0;
}