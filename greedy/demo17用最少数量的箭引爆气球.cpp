#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;  

/*
------
 --------
       ------
          -------
*/

// 升序排序
static bool cmp(vector<int>& point1, vector<int>& point2)
{
    if(point1[0] != point2[0])
        return point1[0] < point2[0];
    else
        return point1[1] < point2[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0)
        return 0;
    // 左对齐排序
    sort(points.begin(), points.end(), cmp);
    int res = 1;        // 默认要一支箭
    for (int i = 1; i < points.size(); i++)
    {
        if(points[i][0] > points[i-1][1])   // 不重叠
            res++;
        else
            points[i][1] = min(points[i][1], points[i-1][1]);  // 更新重叠区间的右端点
    }
    return  res;
}

int main()
{
    vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
    int res = findMinArrowShots(points);
    cout << "res: " << res << endl;
}