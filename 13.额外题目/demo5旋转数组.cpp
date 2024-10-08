#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotateOne(vector<int>& nums)
	{
		int end = nums[nums.size() - 1];
		for(int i = nums.size() - 1; i > 0;i--){
			nums[i] = nums[i-1];
		}
		nums[0] = end;
	}
	
	
	//方法一 编写旋转一次的函数，旋转K次 超时
	//旋转一次的函数：数据右移一位，首位保存末位
//	void rotate(vector<int>& nums, int k) 
//	{
//		for(int i = 0; i < k;i++){
//			rotateOne(nums);
//		}
//	}
	//方法二 拼接 尾巴[size - k, size-1] + 头[0,size - k)
	void rotate2(vector<int>& nums, int k) 
	{
		//K过大 避免循环
		k = k % nums.size();
		
		vector<int> res(nums.size());
		int j = 0;
		//尾巴[size - k, size-1]
		for(int i = nums.size() - k; i < nums.size(); i++)
			res[j++] = nums[i];
		//头[0,size - k)
		for(int i = 0; i < nums.size() - k; i++){
			res[j++] = nums[i];
		}
		nums = res;
		
//		for(int num: nums)
//			cout << num << " ";
	}
	
	
	//方法三：模仿字符串章节的 翻转字符串/右旋转字符串 O(1)操作
	//虽然这里是int类型数据 同字符串 即发翻转数组
	void rotate(vector<int>& nums, int k) 
	{
		//K过大 避免循环
		k = k % nums.size();
		//reverse 左闭右开
		reverse(nums.begin(),nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k,nums.end());
	}
	
	//需要注意的是，本题还有一个小陷阱，题目输入中，
	//如果k大于nums.size了应该怎么办？
};


int main()
{
	Solution s;
	vector<int> nums ={1,2,3,4,5,6,7};
	s.rotate(nums, 3);
	for(int num: nums)
		cout << num << " ";
	return 0;
}
