#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int max = INT32_MIN;
    	int sum = 0;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		sum += nums[i];
			if(sum > max)
				max = sum;
			if(sum <= 0)
    			sum = 0;

		}
		return max;
	}
};



int main()
{
	Solution solution;
	vector<int> nums{0};
	int res = solution.maxSubArray(nums);
	cout << "res: " << res << endl;
	return 0;
}