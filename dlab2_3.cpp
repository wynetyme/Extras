#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Kadane's Algorithm
    long long maxSum = arr[0];
    long long currentSum = arr[0];
    
    for (int i = 1; i < n; i++) {
        // Either extend the existing subarray or start a new one
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    cout << maxSum << endl;
    
    return 0;
}
