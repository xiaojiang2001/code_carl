#include <iostream>
#include <vector>

using namespace std;
int extend(string& s, int i, int j, int n);

int countSubstrings(string s) 
{
    // dp[i][j]: 表示s在区间[i,j]上是否为字符串
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    // s[i] == s[j]:
    // (1) i == j dp[i][j] = true; res++
    // (2) i < j  if(dp[i+1][j-1])  dp[i][j] = true; res++
    // s[i] != s[j]: dp[i][j] = false;  

    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)     // 自身或相邻
                {
                    dp[i][j] = true;
                    res++;
                }
                else if (j - i > 1) // 不相邻 
                {
                    if (dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                        res++;
                    }
                }  
            }   
        }
    }
    return res;
}
    
// 双指针法
int countSubstrings2(string& s) 
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += extend(s, i, i, s.size());   // 以i为中心
        res += extend(s, i, i+1, s.size()); // 以i, i+1 为中心
    }
    return res;
}
// 以 i j 为起点，计算长度为n的字符串中含有的回文串数量
int extend(string& s, int i, int j, int n)
{
    int res = 0;
    while (i >= 0 && j < n && s[i] == s[j])
    {
        i--;
        j++;
        res++;
    }
    return res;
}


int main()
{
    string s = "aaa";
    int ret = countSubstrings2(s);
    cout << ret << endl;
}