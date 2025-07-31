#include<bits/stdc++.h>
#include<vector>
#include<math.h>
using namespace std;

int upperBound(vector<int>mat,int m,int x ){
    int low=0;
    int high=m-1;
    int ans=m;
    while(low<=high){
        int mid=(low+high)/2;
        if(mat[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int countSealEqual(vector<vector<int>>&mat, int n, int m, int x){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upperBound(mat[i],m,x);
    }
    return cnt;
}

int main(){
    vector<vector<int>>mat = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    };
    int low=INT_MAX;
    int high=INT_MIN;
    int n = mat.size();
    int m = mat[0].size();
    int req = (n*m)/2;
    for(int i=0;i<n;i++){
        low = min(low,mat[i][0]);
        high = max(high,mat[i][m-1]);
        while(low<=high){
            int mid=(low+high)/2;
            int smallEqual = countSealEqual(mat,n,m,mid);
            if(smallEqual<=req) low=mid+1;
            else high = mid-1;
        }
    }
    cout<<low;
    return 0;
}