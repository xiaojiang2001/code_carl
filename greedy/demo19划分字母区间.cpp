#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;  

vector<int> partitionLabels(string s) {
    vector<int>  res;
    int left = 0;
    int right = 0;
    int hash[27];

    // 哈希数组记录每个元素的最远位置
    for (size_t i = 0; i < s.size(); i++)
        hash[s[i] - 'a'] = i;
    
    for (size_t i = 0; i < s.size(); i++)
    {
        if(hash[s[i] - 'a'] > right)    // 计算每个元素的最大距离并记录
            right = hash[s[i] - 'a'];

        if(i == right) {    // 找到分割点
            res.push_back(right - left + 1);
            left = right + 1;
        }
    }
    return res;
}

// s = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]

int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = partitionLabels(s);
    for (int num : res)
        cout << num << " ";
}