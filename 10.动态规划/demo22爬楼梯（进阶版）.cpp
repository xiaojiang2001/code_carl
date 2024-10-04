#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	//爬到有i个台阶的楼顶，有dp[i]种方法。
	vector<int> dp(n+1,0);
	dp[0] = 1;
	//求排列数
	//先遍历背包
	for(int i = 1; i <= n; i++)
	{
		//先遍历物品
		for(int j = 1; j <= m; j++){
			if(i - j >= 0)	
				dp[i] += dp[i-j];
		}
	}
	cout << "ret: " << dp[n];
	return 0; 
}

