#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Use prefix sum approach with hash map
    // If prefix[j] - prefix[i] = x, then subarray [i+1, j] has sum x
    unordered_map<long long, int> prefixCount;
    prefixCount[0] = 1;  // Empty prefix has sum 0
    
    long long prefixSum = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        // Check if there exists a prefix with sum (prefixSum - x)
        // This means current subarray ending at i has sum x
        if (prefixCount.find(prefixSum - x) != prefixCount.end()) {
            count += prefixCount[prefixSum - x];
        }
        
        // Add current prefix sum to the map
        prefixCount[prefixSum]++;
    }
    
    cout << count << endl;
    
    return 0;
}
