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

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(4);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left ->left  = new TreeNode(1);
    root->left ->right = new TreeNode(3);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(9);
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

TreeNode* invertTree(TreeNode* root) 
{
    if (root == nullptr){
        return root;
    }
    // 交换当前节点左右子树
    swap(root->left, root->right);
    // 左子树翻转
    invertTree(root->left);
    // 右子树翻转
    invertTree(root->right);

    return root;
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


int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    TreeNode* res = invertTree(root);
    vector<vector<int>> resVec = levelOrder(root);
    showDoubleVec(resVec);

}