#include<iostream>
using namespace std;

int sqrt(int n){
    int low = 1;
    int high = n;
    int ans = 1;
    while(low<=high){
    int mid = (low+high)/2;
    if((long long)mid*mid<=n){
        ans = mid;
        low = mid + 1;
    }
    else high = mid -1;
}
    return high;
}

int main(){
    int n = 36;
    int res = sqrt(n);
    cout<<res;
    return 0;
}