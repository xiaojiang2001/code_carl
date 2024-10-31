#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int numTrees(int n) 
{
    // dp[i] : 由i个节点构成的二叉搜索树有dp[i]种
    vector<int> dp(n+1);

    // 初始化dp数组
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // 画图发现 全部挂在左边/右边的数量就是上一状态的全部数量
        int left = dp[i-1];
        int right = dp[i-1];
        // 中序
        int mid = 0;
        for (int j = 1; j <= i -2; j++) {
            mid += dp[j] * dp[i-1-j];
        }
        dp[i] = left + right + mid;
    }
    for (int i = 1; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    return dp[n];
}

int main()
{
    int n = 6;
    int ret = numTrees(n);
    cout << "ret:" << ret << endl;
    return 0;
}