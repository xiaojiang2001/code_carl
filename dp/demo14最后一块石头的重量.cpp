#include <iostream>
#include <vector>
#include <numeric>
#include <numeric>

using namespace std;

int lastStoneWeightII(vector<int>& stones)
{
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    // 大小为i的背包所能装的最大总价值为 dp[j]
    vector<int> dp(target+1, 0);
    // 遍历物品
    for (int i = 0; i < stones.size(); i++)
    {
        // 遍历背包
        for (int j = target; j >= stones[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-stones[i]] +stones[i]);
        }
    } 
    // 大小为 target 背包最大价值为dp[target]  小堆
    // 大堆石头价值 sum - dp[target] 
    return sum - dp[target] - dp[target];
}


int main()
{
    vector<int> stones{2,7,4,1,8,1};
    int ret = lastStoneWeightII(stones);
    cout << ret << endl;
}