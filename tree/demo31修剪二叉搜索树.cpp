#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

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
    
    
TreeNode* trimBST(TreeNode* root, int low, int high) 
{
    if (root == nullptr)
        return nullptr;

    TreeNode* pre = root;
    // 递归遍历左右子树
    if (root->val >= low && root->val <= high) {
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
    }
    // 左
    if (root->val < low)
        return trimBST(root->right, low, high);
    // 右
    else if (root->val > high)
        return trimBST(root->left, low, high);
    return root;    
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    int low = 1;
    int heigh = 3;
    TreeNode* resRoot = trimBST(root, low, heigh);
    vector<vector<int>> res = levelOrder(resRoot);
    showDoubleVec(res);
    cout << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(0);
    root->right = new TreeNode(4);
    //root->left ->left  = new TreeNode(2);
    root->left ->right = new TreeNode(2);
    //root->right->left  = new TreeNode(2);
    //root->right->right = new TreeNode(7);
    root->left ->right->left = new TreeNode(1);
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