#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace  std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
    // 遍历每一个起点
    for (int i = 0; i < gas.size(); i++)
    {
        int rest = gas[i] - cost[i];        // 记录剩余油量
        int index = (i + 1) % cost.size();  // 记录下一个点
        while (rest > 0 && index != i)      // 模拟以i为起点行驶一圈（如果有rest==0，那么答案就不唯一了）
        {
            rest += gas[index] - cost[index];
            index = (index + 1) % cost.size();
        }       
        // 到终点还有油
        if(rest >= 0 && index == i)
            return i;
    }
    return -1;
}

int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) 
{
    int curSum = 0;
    int start = 0;
    int totalSum = 0;
    for (int i = 0; i < gas.size(); i++) {
        curSum += gas[i] - cost[i];         // 计算当前的油量剩余
        totalSum += gas[i] - cost[i];       // 计算总油量
        if(curSum < 0) {
            start = i + 1;                  // 油量为负 更新可能的起点
            curSum = 0;
        }   
    }
    if(totalSum < 0)
        return -1;
    else 				
        return start;
}


int main()
{
    vector<int> gas{4,5,3,1,4};
    vector<int> cost{5,4,3,4,2};
    int res = canCompleteCircuit2(gas, cost);
    cout << res << endl;
}