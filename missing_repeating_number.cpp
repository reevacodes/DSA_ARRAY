#include<iostream>
#include<vector>
using namespace std;

vector<int> missingRepeating(int arr[], int n) {
    long long SN = n * (n + 1) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long sum = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        S2 += (long long)arr[i] * arr[i];
    }

    long long val1 = sum - SN;        // x - y
    long long val2 = S2 - S2N;        // x^2 - y^2
    val2 = val2 / val1;               // x + y

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main() {
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = 6;
    vector<int> res = missingRepeating(arr, n);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}
