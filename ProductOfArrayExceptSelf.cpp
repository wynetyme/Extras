#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        
        // Calculate prefix products
        // answer[i] will contain the product of all elements to the left of i
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        
        // Calculate suffix products and multiply with prefix
        // answer[i] will contain product of all elements except nums[i]
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        
        return answer;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Example usage
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Example 1: nums = [1,2,3,4]" << endl;
    cout << "Output: ";
    vector<int> result1 = solution.productExceptSelf(nums1);
    printVector(result1);
    cout << "Explanation: Product except self for each index:" << endl;
    cout << "  answer[0] = 2*3*4 = 24" << endl;
    cout << "  answer[1] = 1*3*4 = 12" << endl;
    cout << "  answer[2] = 1*2*4 = 8" << endl;
    cout << "  answer[3] = 1*2*3 = 6" << endl << endl;
    
    // Example 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Example 2: nums = [-1,1,0,-3,3]" << endl;
    cout << "Output: ";
    vector<int> result2 = solution.productExceptSelf(nums2);
    printVector(result2);
    
    return 0;
}
