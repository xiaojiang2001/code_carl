#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDistinct(string s, string t) {
    // 以 i-1 为结尾的s子序列中出现以 j-1 为结尾的t的个数为 dp[i][j]
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
    // dp[i][0] = 1     dp[0][j] = 0;
    for (int i = 0; i <= s.size(); i++)
        dp[i][0] = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]  + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }     
    }
    // for (int i = 0; i <= s.size(); i++)
    // {
    //     for (int j = 0; j <= t.size(); j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[s.size()][t.size()]; 
}

int main()
{
    string s = "babgbag";
    string t = "bag";
    numDistinct(s, t);
    return 0;
}
