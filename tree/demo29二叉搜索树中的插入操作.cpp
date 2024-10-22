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

//按照二叉搜索树的规则去遍历，遇到空节点就插入节点就可以了。
//理解思路 很重要 递归法
/*
TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if (root == nullptr) {
        TreeNode* node = new TreeNode(val);
        return node;
    }

    // 递归遍历到叶子节点
    if (val > root->val)
        root->right = insertIntoBST(root->right, val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);

    return root;    
}
*/

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if (root == nullptr) {
        TreeNode* node = new TreeNode(val);
        return node;
    }

    TreeNode* cur = root;
    TreeNode* pre = nullptr;    // 保存最后需要插入节点的上个节点
    // 遍历到空节点
    while (cur != nullptr)
    {
        pre = cur;
        if (cur->val > val)
            cur = cur->left;
        else if(cur->val < val)
            cur = cur->right;
    }
    //加入新节点
    TreeNode* node = new TreeNode(val);
    if(pre->val > val)
        pre->left = node;	// 此时是用pre节点的进行赋值
    else	
        pre->right = node;
    return root;
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    int val = 5;
    TreeNode* dstRoot = insertIntoBST(root, 5);
    vector<vector<int>> res = levelOrder(dstRoot);
    showDoubleVec(res);
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(4);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left ->left  = new TreeNode(1);
    root->left ->right = new TreeNode(3);
    // root->right->left  = new TreeNode(4);
    // root->right->right = new TreeNode(3);
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