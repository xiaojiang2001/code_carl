#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubsequence(string s, string t) 
{
    // dp[i][j]: s的前 i 个字母与 t前 j 字母的 LCS
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  // 直接套LCS模板
                dp[i][j] = dp[i][j-1];                   // 编辑距离 优化              
        }
    }
    
    for (int i = 0; i <= s.size(); i++)
    {
        for (int j = 0; j <= t.size(); j++)
        {
            cout << dp[i][j] << " ";
        } 
        cout << endl;
    }
    cout << endl;
    return dp[s.size()][t.size()] == s.size();
}

int main()
{
    string s = "abc";
    string t = "ahbgdc";
    bool ret = isSubsequence(s, t);
    cout << "ret: " << ret << endl;
}