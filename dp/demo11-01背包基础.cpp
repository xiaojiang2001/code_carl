#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<int> weight(M);
    vector<int> value(M);

    for (int i = 0; i < M; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> value[i];
    }
    
    vector<int> dp(N+1);
    for (int i = 0; i < M; i++)     // 遍历物品
    {
        for (int j = N; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    
    cout << dp[N];
    
    return 0;
}