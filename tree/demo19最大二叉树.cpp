#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

// 通用功能函数
TreeNode* init_tree();
vector<vector<int>> levelOrder(TreeNode* root);
void showDoubleVec(vector<vector<int>>& vecs);

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    // 1. 递归到了空节点
    if (nums.size() == 0)
        return nullptr;

    // 2. 获取最大值与下标
    int idx = max_element(nums.begin(), nums.end()) - nums.begin();
    int maxNum = nums[idx];
    TreeNode* root = new TreeNode(maxNum);

    // 3. 切割数组 划分左子树和右子树数据
    vector<int> leftTree(nums.begin(), nums.begin() + idx);
    vector<int> rightTree(nums.begin() + idx + 1, nums.end());

    // 4. 递归构造左右子树
    root->left = constructMaximumBinaryTree(leftTree);
    root->right = constructMaximumBinaryTree(rightTree);

    return root;
}


int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    vector<int> nums{3,2,1,6,0,5};
    TreeNode* dstRoot = constructMaximumBinaryTree(nums);
    vector<vector<int>> dst = levelOrder(dstRoot);
    showDoubleVec(dst);
    cout << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(6);
    root->left  = new TreeNode(3);
    root->right = new TreeNode(5);
    //root->left ->left  = new TreeNode(3);
    root->left ->right = new TreeNode(2);
    root->right->left  = new TreeNode(0);
    //root->right->right = new TreeNode(3);
    root->left ->right->right = new TreeNode(1);
    return root;
}
vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> que;
    vector<vector<int>> res;
    if (root != nullptr) {
        que.push(root);
    }
    
    while (!que.empty())
    {
        vector<int> vec;
        //获取每一层的节点个数并处理
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            vec.push_back(node->val);
            que.pop();
            // 把下一层的非空节点加入队列
            if(node->left)      que.push(node->left);
            if(node->right)     que.push(node->right);
        }
        res.push_back(vec);
    }
    return res;
}
void showDoubleVec(vector<vector<int>>& vecs)
{
    for (auto vec: vecs){
        for (int num: vec){
            cout <<  num <<  " ";
        }
        cout << endl;
    }
    cout << endl;
}