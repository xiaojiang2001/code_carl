#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> vec = nums;
		vector<int> hash(101);
		//对数组进行排序 1 2 2 3 8
		sort(vec.begin(), vec.end());
		//计算每个数据比自身小的元素个数 放在hash数组中
		//数据 vec[i] 比自身小的个数为 hash[vec[i]]
		// ☆在构造数组hash的时候，从后向前遍历
		//这样hash里存放的就是相同元素最左面的数值和下标了
		for(int i = vec.size() - 1; i >= 0; i--)
			hash[vec[i]] = i;
		
		//最后在hash数组中查找原数组每个值对应的小于当前数据的个数
		for(int i = 0; i < nums.size(); i++){
			vec[i] = hash[nums[i]];
		}
			
		return vec;
	}
};


int main()
{
	Solution s;
	vector<int> nums ={8,1,2,2,3};
	vector<int> res = s.smallerNumbersThanCurrent(nums);
	for(int num: res)
		cout << num << " ";
	cout << endl;
	
	return 0;
}
