#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

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


// 回收所有可达路径
vector<int> path;
vector<vector<int>> res;
void traversal(TreeNode* root)
{
    //递归条件保存只递归非空节点
    path.push_back(root->val);

    // 到达叶子节点 回收结果
    if (root->left == nullptr && root->right == nullptr)
    {
        res.push_back(path);
        return;
    }
    // 未到达叶子节点
    if (root->left) {
        traversal(root->left);
        path.pop_back();
    }
    if (root->right){
        traversal(root->right);
        path.pop_back();
    }
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr)
        return false;

    
    traversal(root);
    // 计算所有路径的和
    for (auto path: res)
    {
        int pathSum = accumulate(path.begin(), path.end(), 0);
        if (pathSum == targetSum)
            return true;
    }
    return false;
}

int main()
{
    TreeNode* root = init_tree();
    //vector<vector<int>> src = levelOrder(root);
    //showDoubleVec(src);
    int targetSum = 22;  
    bool res = hasPathSum(root,targetSum);
    cout << res << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->left ->left  = new TreeNode(3);
    // root->left ->right = new TreeNode(5);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);
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