#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
            }
        }
        
        string result = "";
        pair<int, char> prev = {-1, '#'};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            result += curr.second;
            
            if (prev.first > 0) {
                pq.push(prev);
            }
            
            curr.first--;
            prev = curr;
        }
        
        return result.length() == s.length() ? result : "";
    }
};

int main() {
    Solution solution;
    cout << solution.reorganizeString("aab") << endl;
    return 0;
}
