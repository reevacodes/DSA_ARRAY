// Give rows and cols, tell the element at that place

// #include<iostream>
// using namespace std;

// void pascal(int row,int col){
//     int res=1;
//     for(int i=0;i<col;i++){
//         res = res*(row-1-i);
//         res = res/(i+1);
//     }
//     cout<<res;
// }

// int main(){
//     pascal(6,3);
//     return 0;
// }


//PRINT ANY NTH ROW OF PASCAL TRIANGLE

// #include<iostream>
// using namespace std;

// void pascal(int n){
//     int res=1;
//     for(int i=0;i<n;i++){
//         if(i==0){
//             cout<<"1 ";
//         }
//         else{
//     res = res*(n-i);
//     res = res/i;
//     cout<<res<<" ";
//         }
//     }
// }

// int main(){
//     pascal(5);
//     return 0;
// }


// GIVEN N, PRINT THE ENTIRE PASCAL TRIANGLE

#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
