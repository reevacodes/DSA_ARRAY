#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& a, int N) {
    int xor1 = 0;
    int xor2 = 0;

    // XOR all elements in the array
    for (int i = 0; i < N - 1; i++) {
        xor1 = xor1 ^ a[i];
    }

    // XOR all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        xor2 = xor2 ^ i;
    }

    // XOR1 ^ XOR2 will give the missing number
    return xor1 ^ xor2;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<int> a(N - 1);
    cout << "Enter " << N - 1 << " elements of the array: ";
    for (int i = 0; i < N - 1; i++) {
        cin >> a[i];
    }

    int missingNum = missingNumber(a, N);
    cout << "The missing number is: " << missingNum << endl;

    return 0;
}
