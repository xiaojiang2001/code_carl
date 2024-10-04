#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> result(nums.size(),-1);
		stack<int> st;
		if(nums.size() == 0)
			return result;
		st.push(0);	
		 // 模拟遍历两边nums，注意一下都是用i % nums.size()来操作
		for(int i = 1; i < nums.size() * 2; i++)
		{
			if(nums[i % nums.size()] <= nums[st.top()])
				st.push(i % nums.size());
			else
			{
				while(!st.empty() && nums[i % nums.size() ] > nums[st.top()])
				{
					result[st.top()] = nums[i % nums.size()];
					st.pop();
				}
				st.push(i % nums.size());
			}
		}	
		return result;		
    }
};

int main()
{
	
	return 0;
}