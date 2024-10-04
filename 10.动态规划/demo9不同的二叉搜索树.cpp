#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numTrees(int n) 
	{
		// dp[i] : 输入 i 能形成的最多二叉搜索树的个数
		vector<int> dp(n+1);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				dp[i] += dp[j-1] * dp[i-j];
			}
		}
		
		for(int num: dp)
			cout << num << " ";
		
		return dp[n];
	}
};

int main()
{
	Solution s;
	int ret = s.numTrees(3);
	cout << "ret: " << ret << endl;
	return 0;
}
