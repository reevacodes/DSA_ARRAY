#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort
using namespace std;

string read(int n, vector<int> book, int target)
{
    int left = 0, right = n - 1;
    sort(book.begin(), book.end()); // Sort first

    while (left < right) {
        int sum = book[left] + book[right];

        if (sum == target) {
            return "YES"; // Found the pair
        }
        else if (sum < target) {
            left++; // Need a bigger sum
        }
        else {
            right--; // Need a smaller sum
        }
    }
    return "NO"; // No pair found
}

int main()
{
    int n;
    cin >> n;

    vector<int> book;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        book.push_back(x);
    }

    int target;
    cin >> target;

    cout << read(n, book, target) << endl;
    return 0;
}

//TC-> O(n) + O(nlogn)
//               |
//           for sorting