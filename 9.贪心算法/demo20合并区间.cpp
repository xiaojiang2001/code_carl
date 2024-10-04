#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	static bool cmp(vector<int> &point1, vector<int> &point2)
	{
		if(point1[0] == point2[0])
			return point1[1] < point2[1];
		return point1[0] < point2[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		vector<vector<int>> res;
		// 区间集合为空直接返回
		if (intervals.size() == 0) 
			return res; 
		//排序 相邻的靠在一起
		sort(intervals.begin(), intervals.end(), cmp);
		// 第一个区间就可以放进结果集里，后面如果重叠，在result上直接合并
		res.push_back(intervals[0]);
		int end = intervals[0][1];
		for(int i = 1; i < intervals.size(); i++)
		{
			if(intervals[i][0] <= res.back()[1])	// 有重叠
				// 合并 更新结果集区间的右边界 细节max 存在新的右边界比旧的小的情况
				res.back()[1] = max(res.back()[1], intervals[i][1]);	
			else
				res.push_back(intervals[i]);			// 无重叠 放入区间
		}
		return res;
	}
};
int main()
{
	Solution solution;
	vector<vector<int>> g{{1,2},{3,6},{7,12},{4,8},{10,16}};
	vector<int> s{1,1};
	//int res = solution.eraseOverlapIntervals(g);
	//cout << "res: " << res << endl;
	return 0;
}