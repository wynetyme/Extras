#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long moves = 0;
    
    // For each element, if it's smaller than the previous one,
    // we need to increase it to match the previous element
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            moves += arr[i-1] - arr[i];
            arr[i] = arr[i-1];  // Update current element
        }
    }
    
    cout << moves << endl;
    
    return 0;
}
