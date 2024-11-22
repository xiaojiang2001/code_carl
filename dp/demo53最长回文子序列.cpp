#include <iostream>
#include <vector>
#include <string>

using namespace std;


int longestPalindromeSubseq(string s) {
    // dp[i][j]: 表示s在区间[i,j]上的最长回文子序列长度
    // s[i] == s[j]
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    // 初始化 根据递推公式 dp[i][i] 是计算不到的
    for (int i = 0; i < s.size(); i++) 
        dp[i][i] = 1;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j]) 
                dp[i][j] = dp[i+1][j-1] + 2;            // 回文子序列 长度 + 2
            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]); // 不相等 删除一个 编辑距离       
        }
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < s.size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    
    return dp[0][s.size()-1];
}


int main()
{
    string s ="a";
    int ret = longestPalindromeSubseq(s);
    cout << "ret: " << ret << endl;
}