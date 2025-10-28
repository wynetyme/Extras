#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for(int i = 0; i < nums.size(); i++){
            if(i > k) window.erase(nums[i-k-1]);
            if(window.count(nums[i])) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    vector<int> nums1 = {1,2,3,1};
    int k1 = 3;
    cout << (s.containsNearbyDuplicate(nums1, k1) ? "true" : "false") << '\n';
    vector<int> nums2 = {1,0,1,1};
    int k2 = 1;
    cout << (s.containsNearbyDuplicate(nums2, k2) ? "true" : "false") << '\n';
    vector<int> nums3 = {1,2,3,1,2,3};
    int k3 = 2;
    cout << (s.containsNearbyDuplicate(nums3, k3) ? "true" : "false") << '\n';
    return 0;
}
