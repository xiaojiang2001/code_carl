#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//☆☆☆ 去重 不考虑顺序 哈希数组用set容器的unordered_set

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	int i;
	 // 存放结果，之所以用unordered_set是为了给结果集去重 并且实现效率高
	unordered_set<int> ret;		
	
	unordered_set<int> hash_tabel(nums1.begin(), nums1.end());	//nums1直接转哈希表
	
	//遍历nums2 查询
	for(i = 0; i < nums2.size(); i++)
	{
		// 发现nums2的元素 在nums_set里又出现过
		if(hash_tabel.find(nums2[i]) != hash_tabel.end())
		{
			ret.insert(nums2[i]);
		}
	}

	return vector<int>(ret.begin(), ret.end());
}

int main()
{
	
	return 0;
} 





