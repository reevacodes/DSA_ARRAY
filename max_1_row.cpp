#include <iostream>
#include <vector>
using namespace std;

// Function to find the index of first occurrence of 1 using lower bound binary search
int lowerBound(vector<int>& row) {
    int n = row.size();
    int low = 0;
    int high = n - 1;
    int ans = n; // Default if no 1 is found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (row[mid] == 1) {
            ans = mid;       // Possible answer, search left
            high = mid - 1;
        } else {
            low = mid + 1;   // Search right
        }
    }

    return ans;
}

// Function to find the row with maximum number of 1s
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int maxOnes = 0;
    int rowIndex = -1;

    for (int i = 0; i < n; i++) {  // ✅ should be i < n not i < m
        int firstOneIndex = lowerBound(matrix[i]);
        int onesCount = m - firstOneIndex;

        if (onesCount > maxOnes) {
            maxOnes = onesCount;
            rowIndex = i;
        }
    }

    return rowIndex;
}

int main() {
    int n, m;
    cout << "Enter number of rows (n) and columns (m): ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the binary matrix (each row sorted):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = rowWithMax1s(matrix, n, m);
    cout << "Row with maximum number of 1s: " << result << endl;

    return 0;
}
