#include <iostream>
using namespace std;

class Solution {
public:
    // nums: input array, n: size of array
    // ans: output array of size 2
    bool twoSum(int nums[], int n, int target, int ans[2]) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return true; // found
                }
            }
        }
        return false; // no solution
    }
};

int main() {
    Solution sol;
    int nums[] = {2, 7, 11, 15};
    int ans[2];
    if (sol.twoSum(nums, 4, 9, ans)) {
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }
}
