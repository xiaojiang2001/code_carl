#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 回溯暴搜
bool backtracking (const string& s, const unordered_set<string>& wordSet, int startIndex) 
{
    if (startIndex >= s.size())
    {
        return true;
    }
    
    for (int i = startIndex; i < s.size(); i++)
    {
        // 各个子串
        string word = s.substr(startIndex, i - startIndex + 1);
        if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i+1))
        {
            return true;
        }
    }
    return false;
}


bool wordBreak(string s, vector<string>& wordDict) 
{
    // 背包 s
    // 物品 wordDict
    // dp[i] = true;    以长度为i的字符串可以用字典单词拼成  
    // dp[0] 表示空字符串
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;                           // 递推根基 长度为0 空字符串 无意义
    // 单词是排列
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    for (int i = 1; i <= s.size(); i++)     // 遍历背包
    {
        for (int j = 0; j < i; j++)         // 遍历物品
        {
            string word = s.substr(j, i - j);   // 截取 j - i 的单词
            // 判断截取的单词是否在字典里面
            if (wordSet.find(word) != wordSet.end() && dp[j] == true)
            {
                dp[i] = true;
            }
        }
    }
    return dp[s.size()];
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool ret = wordBreak(s, wordDict);
    cout << ret << endl;
    return 0;
}