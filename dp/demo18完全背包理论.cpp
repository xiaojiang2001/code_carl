#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,V;    // N: 物品种类 V背包大小
    cin >> N >> V;

    vector<int> weight(N);
    vector<int> value(N);
    vector<int> dp(V+1);

    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    // 组合数
    for (int i = 0; i < N; i++)
    {
        for (int j = weight[i]; j <= V; j++)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    
    cout << dp[V];
    return 0;
}