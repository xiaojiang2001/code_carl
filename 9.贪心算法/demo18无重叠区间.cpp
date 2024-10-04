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
	int eraseOverlapIntervals(vector<vector<int>>& intervals) 
	{
		int res = 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int end = intervals[0][1];
		for(int i = 1; i < intervals.size(); i++)
		{
			if(intervals[i][0] >= end)	// 无重叠
				end = intervals[i][1];
			else		
			{
				end = min(end,intervals[i][1]);		//有重叠 更新重叠右边界
				res++;
			}
		}
		return res;
	}
};
int main()
{
	Solution solution;
	vector<vector<int>> g{{1,2},{3,6},{7,12},{4,8},{10,16}};
	vector<int> s{1,1};
	int res = solution.eraseOverlapIntervals(g);
	cout << "res: " << res << endl;
	return 0;
}