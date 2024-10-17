#include <iostream>
#include <vector>
#include <queue>

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

int traverse(TreeNode* left, TreeNode* right)
{
    // 叶子节点
    if (left == nullptr && right == nullptr)
        return 1;
    // 左节点不为空 
    if (left != nullptr && right == nullptr)
        return traverse(left->left, left->right) + 1;
    // 右节点不为空
    if (right != nullptr && left == nullptr)
        return traverse(right->left, right->right) + 1;
    // 左右都不为空 返回大的
    int leftDepth  = traverse(left->left,left->right);
    int rightDepth = traverse(right->left,right->right);
    return max(leftDepth, rightDepth) + 1;
}



int maxDepth(TreeNode* root) 
{
    if (root == nullptr )
        return 0;
    return traverse(root->left, root->right);
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    int res = maxDepth(root);
    cout << res << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left ->left  = new TreeNode(3);
    root->left ->right = new TreeNode(4);
    root->right->left  = new TreeNode(4);
    root->right->right = new TreeNode(3);
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