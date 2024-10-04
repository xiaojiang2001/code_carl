#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> result(nums1.size(),-1);
		stack<int> st;
		if(nums1.size() == 0)
			return result;
		
		// 将数组1的值与下标做映射，通过数值找到在nums1中的下标
		unordered_map<int,int> umap;
		for(int i = 0; i < nums1.size(); i++)
			umap[nums1[i]]= i;	
			
		st.push(0);	
		for(int i = 1; i < nums2.size(); i++)
		{
			
			if(nums2[i] <= nums2[st.top()])
				st.push(i);
			else
			{
				while(!st.empty() && nums2[i] > nums2[st.top()])
				{
					if(umap.count(nums2[st.top()]) > 0)			// 看nums1中是否存在该元素
					{
						int idx = umap[nums2[st.top()]];		// 获取数据在nums1中的下标
						result[idx] = nums2[i];
					}
					st.pop();
				}
				st.push(i);
			}
		}
		return result;
    }
};



int main()
{
	
	return 0;
}