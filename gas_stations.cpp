#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>  // for setprecision
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n - 1, 0);  // howMany[i] = # of extra stations between arr[i] and arr[i+1]

    // Max heap: stores {sectionLength, index}
    priority_queue<pair<long double, int>> pq;

    // Initialize heap with initial segment lengths
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        pq.push({diff, i});
    }

    // Place k gas stations greedily
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        auto top = pq.top(); pq.pop();
        int idx = top.second;
        howMany[idx]++;
        long double newLen = (long double)(arr[idx + 1] - arr[idx]) / (howMany[idx] + 1);
        pq.push({newLen, idx});
    }

    return pq.top().first;
}

int main() {
    vector<int> arr = {1, 3, 6, 10};
    int k = 3;

    long double result = minimiseMaxDistance(arr, k);
    
    cout << fixed << setprecision(10);
    cout << "Minimum possible maximum distance: " << result << endl;

    return 0;
}

