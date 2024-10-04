#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	// g[i] 最小胃口   s[i] 饼干大小		s[i] >= g[i]
    int findContentChildren(vector<int>& g, vector<int>& s) {
		int res = 0;
		int startIdx = 0;				//记录发到第几块饼干了
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		for(int i = 0; i < g.size(); i++)
		{
			for(int j = startIdx; j < s.size(); j++)
			{
				if(s[j] >= g[i])
				{
					res++;
					startIdx = j+1;		//从下一块饼干开始发
					break;	
				}
			}
		}
		return res;
    }
};


int main()
{
	Solution solution;
	vector<int> g{1,2,3};
	vector<int> s{1,1};
	int res = solution.findContentChildren(g,s);
	cout << "res: " << res << endl;
	return 0;
}