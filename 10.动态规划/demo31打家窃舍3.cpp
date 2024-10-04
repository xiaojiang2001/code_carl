#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode():val(0),left(nullptr),right(nullptr){}
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right):
	val(x),left(left),right(right){}
};



class Solution {
public:
	int rob(TreeNode* root) 
	{
		//树形dp引入
		// dp[2] : 保存当前节点偷与不偷，dp[0] : 不偷当前节点最大金额
		// 由于递归遍历二叉树，当前层的dp保存当前节点的状态
		vector<int> ret = robTree(root);
		return max(ret[0], ret[1]);
	}
	// 长度为2的数组，0：不偷，1：偷
	vector<int> robTree(TreeNode* cur)
	{
		// 后续遍历二叉树
		if(cur == NULL)
			return vector<int> {0,0};
		
		//向左右遍历
		vector<int> leftdp  = robTree(cur->left);
		vector<int> rightdp = robTree(cur->right);
		
		// 中间节点偷 左右不偷
		int value1 = cur->val + leftdp[0] + rightdp[0];
		// 中间节点不偷 偷左右 
		int value2 = max(leftdp[0],leftdp[1]) + max(rightdp[0], rightdp[1]);
		
		return {value2, value1};
	}
};

int main()
{
	Solution s;
	vector<int> nums{1,2,3,1};
	return 0; 
}

