#include <iostream>
#include <vector>

using namespace std;


 int minCostClimbingStairs(vector<int>& cost)
 {
    // dp[i] 表示爬上第i阶楼梯所需要的费用
    vector<int> dp(cost.size() + 1);
    if (cost.size() <= 1)
        return 0;

    // 初始化dp: 从下标为0或1的楼梯开始爬
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= cost.size(); i++)
    {
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }
    for (int i = 0; i <= cost.size(); i++)
        cout << dp[i] << " ";
    cout << endl;
    return dp[cost.size()];
 }


 int main()
 {
    vector<int> cost{10,15,20};
    int ret = minCostClimbingStairs(cost);
    cout << "ret: " << ret << endl;
    return 0;    
 }