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

// 核心算法
// 获取最大深度
int getMaxDepth(TreeNode* node)
{
    if (node == nullptr) {
        return 0;
    }
    int leftDepth  = getMaxDepth(node->left);
    int rightDepth = getMaxDepth(node->right);
    return max(leftDepth, rightDepth) + 1;
}
// 获取最小深度
int getMinDepth(TreeNode* node)
{
    if (node == nullptr) {
        return 0;
    }
    int leftDepth  = getMinDepth(node->left);
    int rightDepth = getMinDepth(node->right);
    return min(leftDepth, rightDepth) + 1;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr){
        return true;
    }
    int maxDepth = getMaxDepth(root);
    int minDepth = getMinDepth(root);
    if (maxDepth - minDepth > 1) {
        return false;
    }   
    return true;    
}

int main()
{
    TreeNode* root = init_tree();
    //vector<vector<int>> src = levelOrder(root);
    //showDoubleVec(src);
    bool res = isBalanced(root);
    cout << res << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(1);
    // root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
    // root->left ->left  = new TreeNode(3);
    // root->left ->right = new TreeNode(4);
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