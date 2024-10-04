#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	static bool cmp(vector<int> &point1, vector<int> &point2)
	{
		return point1[0] < point2[0];
	}
    int findMinArrowShots(vector<vector<int>>& points) {
    	if (points.size() == 0) 
			return 0;
			
		 int result = 1; // points 不为空至少需要一支箭
    	// 对气球起点从小到大排序
		sort(points.begin(), points.end(), cmp);
		for(int i = 1; i < points.size(); i++)
		{
			if(points[i][0] > points[i-1][1])	// 气球i和气球i-1不挨着 注意不是 >=
			{
				result++;						// 需要一支箭
			}
			else								// 气球i和气球i-1挨着
			{
				points[i][1] = min(points[i-1][1], points[i][1]);	// 更新重叠气球最小右边界
			}
		}
		return result;
    }
};

int main()
{
	Solution solution;
	vector<int> g{5,5,10,10,20};
	vector<int> s{1,1};
	//bool res = solution.lemonadeChange(g);
	//cout << "res: " << res << endl;
	return 0;
}