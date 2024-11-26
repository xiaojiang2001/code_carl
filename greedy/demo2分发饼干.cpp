#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 找到为每个孩子分发饼干的最小代价，贪在孩子获得饼干
// int findContentChildren(vector<int>& g, vector<int>& s) {
//     sort(g.begin(), g.end());
//     sort(s.begin(), s.end());

//     // g表示孩子胃口, s表示饼干大小
//     int result = 0;     // 结果集
//     int j = 0;          // 分到哪一块饼干了
//     for (int i = 0; i < g.size(); i++)
//     {
//         // 循环找到可以为当前孩子分发饼干的最小代价
//         while (j < s.size() && s[j] < g[i])
//             j++;
//         // 饼干已经发完
//         if (j >= s.size())  
//             break;
//         // 发饼干   
//         else if(s[j] >= g[i])
//         {
//             result++;
//             j++;
//         }           
//     }
//     return result;
// }

// 可能的将饼干发出去，贪在发出饼干
int findContentChildren(vector<int>& g, vector<int>& s) {
    // 从大到小排序, 尽可能发出饼干
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());

    // g表示孩子胃口, s表示饼干大小
    int result = 0;     // 结果集
    int j = 0;          // 分到哪一块饼干了
    for (int i = 0; i < g.size(); i++)
    {
        // 没有饼干了
        if (j >= s.size())
            break;
        // 可以发饼干
        if (s[j] >= g[i]) {
            result++;
            j++;
        }
    }
    return result;
}
int main()
{
    vector<int> g{1,2,3};
    vector<int> s{1,2};
    int ret = findContentChildren(g,s);
    cout << "ret: " << ret << endl;
    return 0;
}