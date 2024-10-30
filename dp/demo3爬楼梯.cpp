#include <iostream>
#include <vector>

using namespace std;


int climbStairs(int n) {
    if(n <= 2)
        return n;
    vector<int> dp(n+1);    // dp[i] 表示爬上i阶楼梯有dp[1]种方法
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        // 最后一步为爬一阶还是2阶
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
 int main()
 {
    for (int i = 0; i < 10; i++)
    {
        cout << climbStairs(i) << " ";
    }
    cout << endl;
    return 0;    
 }