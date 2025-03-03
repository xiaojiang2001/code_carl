#include <bits/stdc++.h>

using namespace std;

// 背包最多装多少
int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int weight = sum / 2;       // 背包大小
    vector<int> dp(weight+1, 0);
    for (size_t i = 0; i < stones.size(); i++)
    {
        for (size_t j = weight; j >= stones[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
        }
    }
    // 小的一堆石头   dp[weight]
    // 大的一堆石头  sum - dp[weight]
    return  sum - dp[weight] * 2;
}

int main()
{
    return 0;
}