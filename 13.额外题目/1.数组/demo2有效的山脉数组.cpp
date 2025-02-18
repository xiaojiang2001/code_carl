#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool validMountainArray(vector<int>& arr)
	{
		int flag =  true;
		
		if(arr.size() < 3){
			return false;
		}
		//找山顶
		int top;
		int i = 0;
		for(i = 0; i < arr.size() - 1; i++)
		{
			if(arr[i] >= arr[i+1])
			{
				top = i;
				break;
			}	
		}
		//全部递增或递减
		if(i == arr.size()- 1 || i == 0)
			flag = false;
		
		//判断是否严格递减
		for(int i = top; i < arr.size() - 1; i++)
		{
			if(arr[i] <= arr[i+1])
			{
				flag = false;
				break;
			}
		}
		
		if(flag)
			return true;
		else
			return false;
	}
};


int main()
{
	Solution s;
	vector<int> nums ={0,3,2,1};
	bool res = s.validMountainArray(nums);
	cout << res << endl;
	return 0;
}
