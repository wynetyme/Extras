#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            if (first != second) {
                pq.push(first - second);
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    Solution solution;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << solution.lastStoneWeight(stones) << endl;
    return 0;
}
