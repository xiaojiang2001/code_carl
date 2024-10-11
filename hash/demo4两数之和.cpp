#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res(2,0);
	//固定一个数 nums[i] 在 umap 中查找 target - nums[i] 
	unordered_map<int, int> umap;
	for(int i = 0; i < nums.size();i++){
		auto it = umap.find(target - nums[i]);
		if(it != umap.end()){
			return {it->second, i};
		}
		else
			umap.insert({nums[i], i});
	}   
	return {};
}

int main()
{
	vector<int>  nums {2,7,11,15};
	
	return 0;
}
