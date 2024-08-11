#include <iostream>
#include <vector>

using namespace std;

vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n1 && j < n2) {
        // If both elements are the same, add any one of them and move both pointers
        if (arr1[i] == arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        // Add the smaller element and move the corresponding pointer
        else if (arr1[i] < arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else {
            if (unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    // Add remaining elements from arr1
    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements from arr2
    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};

    vector<int> unionArr = findUnion(arr1, arr2);

    cout << "Union of the two sorted arrays: ";
    for (int num : unionArr) {
        cout << num << " ";
    }

    return 0;
}
