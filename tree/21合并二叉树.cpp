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

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
{
    
}


int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    TreeNode* dstRoot = mergeTrees(root, root);
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