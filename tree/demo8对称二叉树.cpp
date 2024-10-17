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
bool compare(TreeNode* left, TreeNode* right)
{
    // 左右一个为空 一个不为空
    if (left == nullptr && right != nullptr ||
        left != nullptr && right == nullptr )
        return false;
     // 左右都为空
    if (left == nullptr && right == nullptr)    
        return true;

    // 左右不为空 但值不相等
    if (left != nullptr && right != nullptr && 
        left->val != right->val)
        return false;
    // 值相等 递归下一层
    // 比较外侧和内侧节点
    bool inside  = compare(left->right,right->left);
    bool outside = compare(left->left, right->right);
    bool isSame = inside && outside;
    return isSame;  
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr){
        return true;
    }
    bool res = compare(root->left, root->right);
    return res;
}

int main()
{
    TreeNode* root = init_tree();
    //vector<vector<int>> src = levelOrder(root);
    //showDoubleVec(src);
    bool res = isSymmetric(root);
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