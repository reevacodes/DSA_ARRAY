#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;
    vector<int> intersectionArr;

    while (i < n1 && j < n2) {
        // If elements are equal, add to intersection and move both pointers
        if (arr1[i] == arr2[j]) {
            // To avoid duplicates in the intersection array
            if (intersectionArr.empty() || intersectionArr.back() != arr1[i]) {
                intersectionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        // Move the pointer of the smaller element
        else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return intersectionArr;
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};

    vector<int> intersectionArr = findIntersection(arr1, arr2);

    cout << "Intersection of the two sorted arrays: ";
    for (int num : intersectionArr) {
        cout << num << " ";
    }

    return 0;
}
