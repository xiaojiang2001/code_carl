#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	unordered_set<int> res;
	
	// 利用set保存数组
	unordered_set<int> uset(nums1.begin(),nums1.end());
	for(int num:nums2){
		if(uset.find(num) != uset.end()){
			res.insert(num);
		}
	}
	return vector<int>(res.begin(),res.end());
}





int main()
{
	
	cout << ret << endl;
	return 0;
}
