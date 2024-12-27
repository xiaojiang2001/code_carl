#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string startStr, endStr;
    cin >> startStr >> endStr;

    string str;
    unordered_set<string> uset;
    for(size_t i = 0; i < n; i++) {
        cin >> str;
        uset.insert(str);
    }

    // 图中的线是如何连在一起的 自己构造图
    // 起点和终点的最短路径长度 bfs
    unordered_map<string, int> visitedMap; // 记录访问过的字符串，同时记录是第几个点
    queue<string> que;
    que.push(startStr);
    visitedMap[startStr] = 1;
    while (!que.empty())
    {
        string word = que.front();
        que.pop();

        int path = visitedMap[word];        // 这个字符串在路径中的长度
        // 遍历查找只相差一个字母的字符串
        for (size_t i = 0; i < word.size(); i++)
        {
            string newWord = word;

            for (size_t j = 0; j < 26; j++)
            {
                newWord[i] = j + 'a';
                if(newWord == endStr) {      // 发现替换字母后，字符串与终点字符串相同
                    cout << path + 1;
                    return 0;
                }  
                // 新的单词在字典中 且未被访问过
                if(uset.find(newWord) != uset.end() && visitedMap.find(newWord) == visitedMap.end())
                {
                    que.push(newWord);
                    visitedMap.insert(pair<string, int>(newWord, path + 1));
                }
            }
        } 
    }
    // 没找到输出0
    cout << 0 << endl;

    return 0;
}