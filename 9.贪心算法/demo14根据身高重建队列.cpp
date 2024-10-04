#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	static bool cmp(vector<int> &a, vector<int> &b)
	{
		if(a[0] == b[0])
			return a[1] < b[1];
		else
			return a[0] > b[0];
	}
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
	{
		vector<vector<int>> queue;
		// 按身高从到到低排序
		sort(people.begin(), people.end(), cmp);
		for(int i = 0; i < people.size(); i++)
		{
			int insertPos = people[i][1];
			queue.insert(queue.begin() + insertPos, people[i]);
		}
		return queue;
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