#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int integerBreak(int n) 
{
    // dp[i]: 整数拆分为k个整数后的最大乘积为dp[i]
    vector<int> dp(n+1,0);

    // 初始化dp数组
    dp[0] = dp[1] = 0;  // 无意义
    dp[2] = 1;
    for (int i = 3; i <= n; i++) 
    {
        // 把i拆分成2个数: j 和 i-j
        // 拆成3个数: j * dp[i-j]
        for (int j = 1; j < i; j++) 
            dp[i] = max(dp[i] ,  max(j * dp[i-j], j * (i-j)));
    }

    // for (size_t i = 2; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }

    cout <<  endl;
    return dp[n];
}


int main()
{
    int ret = integerBreak(10);
    cout << "ret: " << ret << endl;
    return 0;
}