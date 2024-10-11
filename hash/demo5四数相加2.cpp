#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	//统计 a+b是否出现过与出现的次数
	unordered_map<int, int> umap;
	for(int num1:nums1){
		for(int num2:nums2){
			umap[num1 + num2]++;
		}
	}
	
	//判断 -(c+d)是否在集合里面出现过
	int cnt = 0;
	for(int num3:nums3){
		for(int num4:nums4){
			if(umap.find(0-(num3 + num4)) != umap.end())
				cnt += umap[0-num3 - num4];
		}
	}
	return cnt;
}


int main()
{
	vector<int>  nums {2,7,11,15};
		
	return 0;
}
