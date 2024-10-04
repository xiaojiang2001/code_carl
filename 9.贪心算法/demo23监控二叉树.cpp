#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}	
};

class Solution {
public:
	int result;
	int traversal(TreeNode* cur) {
		// 状态0：无覆盖
		// 状态1：有摄像头
		// 状态2：有覆盖
		
		if(cur == nullptr)		// 空节点 有覆盖状态 使得父节点为无覆盖状态
			return 2;
		
		// 后续遍历
		int left  = traversal(cur->left);		// 左
		int right = traversal(cur->right);		// 右
		
		// 中
		// 情况1: 左右都有覆盖，父节点无覆盖
		if(left == 2 && right ==2)
			return 0;
		// 情况2: 左右至少有一个无覆盖 父节点有摄像头
		if(left == 0 || right == 0)
		{
			result++;
			return 1;
		}
		// 情况3: 左右至少有一个有摄像头 父节点有覆盖
		if(left == 1 || right == 1)
			return 2;
			
		return -1;
	}

	int minCameraCover(TreeNode* root) {
		result = 0;
		// 情况4: 根节点无覆盖
		if(traversal(root) == 0)
			result++;
		return result;
    }
};
int main()
{
	Solution solution;
	vector<vector<int>> g{{1,2},{3,6},{7,12},{4,8},{10,16}};
	vector<int> s{1,1};
	//int res = solution.eraseOverlapIntervals(g);
	//cout << "res: " << res << endl;
	return 0;
}