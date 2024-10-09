#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) 
	{
		vector<int> hash(2001);
		//统计每个元素出现的次数
		for(int i = 0; i < arr.size(); i++)
			hash[arr[i] + 1000]++;
		//查看该频率是否出现过
		bool frq[1001] = {false};
		for(int i = 0; i <= 2000; i++){
			if(hash[i])
			{
				// 判断一样的频率在数组中是否出现过
				if(frq[hash[i]] == false){
					frq[hash[i]] = true;
				}
				else
					return false;
			}
		}
		return true;
	}
};


int main()
{
	Solution s;
	vector<int> nums ={1,2,2,1,1,3};
	bool res = s.uniqueOccurrences(nums);
	cout << res << endl;
	return 0;
}
