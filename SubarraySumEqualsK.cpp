#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int,int> cnt;
		cnt[0]=1;
		int sum=0, ans=0;
		for(int x: nums){
			sum+=x;
			if(cnt.count(sum-k)) ans+=cnt[sum-k];
			cnt[sum]++;
		}
		return ans;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums = {1,1,1};
	int k = 2;
	Solution s;
	cout << s.subarraySum(nums,k) << '\n';
	return 0;
}

