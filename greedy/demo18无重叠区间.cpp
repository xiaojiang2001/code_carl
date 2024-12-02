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

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() == 0)
        return 0;
    // 左对齐排序
    sort(intervals.begin(), intervals.end(), cmp);
    int res = 0;                                    // 默认不需要移除
    for (int i = 1; i < intervals.size(); i++)
    {
         // 重叠需要移除
        if(intervals[i][0] < intervals[i-1][1]) {
            res++;
            intervals[i][1] = min(intervals[i-1][1], intervals[i][1]);  // 更新右区间
        }
    }
    return  res;
}


int main()
{
    vector<vector<int>> points{{1,2},{2,3}};
    int res = eraseOverlapIntervals(points);
    cout << "res: " << res << endl;
}
