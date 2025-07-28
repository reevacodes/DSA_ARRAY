// BRUTE FORCE

// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;

// int reqTime(vector<int>&bananas,int hours){
//     int n = bananas.size();
//     int rTime=0;
//     for(int i=0;i<n;i++){
//         rTime += bananas[i]/hours;
//     }
//     return rTime;
// }

// int main(){
//     vector<int>bananas={2,6,7,11};
//         int maxi=-1;
//         int k=8;
//         for(int i=0;i<bananas.size();i++){
//             maxi=max(maxi,bananas[i]);
//         }
//         for(int i=1;i<=maxi;i++){
//             int time = reqTime(bananas,i);
//             if(time<=k){
//                 cout<< i;
//                 break;
//             }
            
//         }
//         return 0;
// }

// BINARY SEARCH

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int reqTime(vector<int>&bananas,int hours){
    int n = bananas.size();
    int rTime=0;
    for(int i=0;i<n;i++){
        rTime += bananas[i]/hours;
    }
    return rTime;
}

int main(){
    vector<int>bananas={2,6,7,11};
        int maxi=-1;
        int k=8;
        for(int i=0;i<bananas.size();i++){
            maxi=max(maxi,bananas[i]);
        }
        int low=1;
        int high=maxi;
        int ans = 0;
        while(low<=high){
            int mid=(low+high)/2;
            int Time = reqTime(bananas,mid);
            if(Time<=k){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        cout<<ans;
        return 0;
}