#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2) 
{
    // dp[i][j]: 当 text1 以 i-1 为下标, text2 以 j-1 为下标形成的最长重复子数组长度
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size()+1));
    int res = 0;

    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            
        }
    }
    

}


int main()
{

}