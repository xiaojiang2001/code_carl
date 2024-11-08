#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

// dp[0]偷 dp[1] 不偷
vector<int> traversal(TreeNode* root)
{
    if (root == nullptr)
        return {0,0};

    vector<int> left  = traversal(root->left);
    vector<int> right = traversal(root->right);

    vector<int> dp(2,0);  // 结果集
    // 偷当前节点 不偷左右子节点
    dp[0] += root->val + left[1] + right[1];
    // 不偷当前节点 偷左右子节点
    dp[1] += max(left[0], left[1]) + max(right[0], right[1]);

    return dp;
}

int rob(TreeNode* root) 
{
    //树形dp引入
	// dp[2] : 保存当前节点偷与不偷，dp[0] : 偷     dp[1] : 不偷 
	// 由于递归遍历二叉树，当前层的dp保存当前节点的状态
	vector<int> ret = traversal(root);
	return max(ret[0], ret[1]);
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right  = new TreeNode(3);
    root->right->right = new TreeNode(1);
    return root;
}

int main()
{
    TreeNode *root = init_tree();
    int ret = rob(root);
    cout << ret << endl;
    return 0;
}


   