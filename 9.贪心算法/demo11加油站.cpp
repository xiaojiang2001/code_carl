#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	// 贪心 时间复杂度过大
/*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		for(int i = 0; i < gas.size(); i++)			// 从第一个点开始
		{
			int rest = gas[i] - cost[i];			// 起点剩余的油
			int idx = (i + 1) % gas.size();			// 下一站
			while(rest > 0 && idx != i)				// 还没进入下一圈
			{
				rest = rest + gas[idx] - cost[idx];	//计算下一站的剩余
				idx = (idx + 1) % cost.size();		// 更新下一站的站点
				if(rest < 0)
					break;
			}
			if(rest >= 0 && idx == i)
				return i;							//一圈结束，还有油
		}
		return -1;
    }
*/
	
	//可以换一个思路，首先如果总油量减去总消耗大于等于零那么一定可以跑完一圈，
	//说明 各个站点的加油站 剩油量rest[i]相加一定是大于等于零的。
	// 贪心 
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
	{
		int rest;
		int restTotal = 0;				// 一圈总剩余
		int curSum = 0;					// 跑过路的总剩余
		int start = 0;	
		for(int i = 0; i < gas.size(); i++)
		{
			rest = gas[i] - cost[i];
			curSum += gas[i] - cost[i];
			restTotal += rest;
			if(curSum < 0)
			{
				curSum = 0;
				start = i + 1;
			}
		}
		if(restTotal < 0)	return -1;		//说明怎么走都不可能跑一圈了
		else 				return start;
	}


	// 贪心  该方法不直观
	// 情况1: 总油量小于总消耗，一定无法到达
	// 情况2：rest[i] = gas[i]-cost[i]为一天剩下的油，i从0开始计算累加到最后一站，
	//如果累加和没有出现负数，说明从0出发，油就没有断过，那么0就是起点
	//情况3：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前
	//看哪个节点能把这个负数填平，能把这个负数填平的节点就是出发节点。
/*
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int rest;
		int restMin = INT32_MAX;
		int restSum = 0;
		for(int i = 0; i < gas.size(); i++)
		{
			rest = gas[i]-cost[i];
			if(rest < restMin)
				restMin = rest;
			restSum += rest;
		}
		if(restSum < 0)	return -1;	// 情况1
		if(restMin > 0)	return 0;	// 情况2
		// 情况3: 全部的剩余相加大于0 不从0开始
		for(int i = gas.size()-1; i >= 0; i--)
		{
			rest = gas[i]-cost[i];
			restMin += rest;
			if(restMin >= 0)
				return i;
		}
		return -1;
	}
*/
};

int main()
{
	Solution solution;
	vector<int> gas{1,2,3,4,5};
	vector<int> cost{3,4,5,1,2};
	int res = solution.canCompleteCircuit(gas,cost);
	cout << "res: " << res << endl;
	return 0;
}