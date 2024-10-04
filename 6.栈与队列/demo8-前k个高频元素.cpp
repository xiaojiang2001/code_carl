#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    }
};

//主程序
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	vector<int> ret = s->topKFrequent(nums,3);
	for(int i = 0; i< ret.size();i++)
		cout << ret[i] << endl;
    return 0;
}

