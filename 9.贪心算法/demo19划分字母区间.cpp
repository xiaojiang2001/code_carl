#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) 
	{
		vector<int> res;
		// 统计当前区间的左右下标
		int left = 0;
		int right = 0;		
		int hash[27] = {0};			// 记录每个字母最远出现的位置
		for(int i = 0; i < s.size(); i++)
			hash[s[i] - 'a'] = i;
		for(int i = 0; i < s.size(); i++)
		{
			right = max(right, hash[s[i] - 'a']);	// 更新右边界最远下标
			if(i == right)							// 遍历到有边界最远下标
			{
				res.push_back(right - left + 1);
				left = right + 1;
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
	//int res = solution.eraseOverlapIntervals(g);
	//cout << "res: " << res << endl;
	return 0;
}