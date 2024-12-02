#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;  

// 升序排序
static bool cmp(vector<int>& point1, vector<int>& point2)
{
    if(point1[0] != point2[0])
        return point1[0] < point2[0];
    else
        return point1[1] < point2[1];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0)
        return {{}};
    // 左对齐排序
    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> res;        // 结果集
    vector<int> path(2);            // 当前区间
    path[0] = intervals[0][0];
    path[1] = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        // 不重叠了 保存上一个区间 始化下个区间
        if(intervals[i][0] > intervals[i-1][1])
        {
            res.push_back(path);
            // 初始化下个区间
            path[0] = intervals[i][0];
            path[1] = intervals[i][1];
        }
        // 重叠 更新区间右端点
        else {
            intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
            path[1] = intervals[i][1];
        }
    }
    res.push_back(path);      // 加入最后一个区间
    return  res;
}

int main()
{
    vector<vector<int>> points{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(points);
    for (auto vec : res) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
