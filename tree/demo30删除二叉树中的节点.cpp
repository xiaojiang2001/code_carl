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

TreeNode* pre = nullptr;
TreeNode* deleteNode(TreeNode* root, int key) 
{
    if (root == nullptr)
        return nullptr;

    // 找到删除的节点
    if (root->val == key)
    {
        if(root->left == nullptr &&  root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr && root->right != nullptr) {
            return root->right;
        }
        else if (root->left != nullptr && root->right == nullptr) {
            return root->left;
        }
        // 左右都不为空 将左子树挂到右子树的最左下角
        else    
        {

        }

    }
    


    // 单层递归逻辑
    if (root->val > key)        // 左
        root->left = deleteNode(root->left, key);
    else if (root->val < key)   // 右
        root->right = deleteNode(root->right, key);
    return root;
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    int key = 3;
    TreeNode* resRoot = deleteNode(root,key);
    vector<vector<int>> res = levelOrder(resRoot);
    showDoubleVec(res);
    cout << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(5);
    root->left  = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left ->left  = new TreeNode(2);
    root->left ->right = new TreeNode(4);
    //root->right->left  = new TreeNode(2);
    root->right->right = new TreeNode(7);
    //root->left ->right->right = new TreeNode(1);
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