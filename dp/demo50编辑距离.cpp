#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int minDistance(string word1, string word2) {
    // 以 i-1 为结尾的word1  j-1 为结尾的word1的相同所需的最小步数
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));
    for (int i = 0; i <= word1.size(); i++)
        dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++)
        dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++)
    {
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + 1));            
        }
    }
    
    // for (int i = 0; i <= word1.size(); i++)
    // {
    //     for (int j = 0; j <= word2.size(); j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return dp[word1.size()][word2.size()];
}

int main()
{
    string s = "horse";
    string t = "ros";
    minDistance(s, t);
    return 0;
}