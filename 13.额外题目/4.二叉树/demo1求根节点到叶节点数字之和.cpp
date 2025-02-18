#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

vector<int> path;
vector<vector<int>> res;

void traversal(TreeNode* root)
{
    if(root->left == nullptr && root->right == nullptr) {
        path.push_back(root->val);
        res.push_back(path);
        return;
    }

    path.push_back(root->val);
    if(root->left) {
        traversal(root->left);
        path.pop_back();
    }
    if(root->right) {
        traversal(root->right);
        path.pop_back();
    }

    return;
}

int getVecSum(vector<int> &vec)
{
    int ret = 0;
    for (auto num : vec) {
        ret = ret * 10 + num;
    }
    return ret;
}

int sumNumbers(TreeNode* root) {
    traversal(root);
    int ret = 0;
    for (auto  path : res) {
        ret += getVecSum(path);
    }
    return ret;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left   = new TreeNode(5);
    root->left->right  = new TreeNode(1);
    int ret = sumNumbers(root);
    cout << ret << endl;
    return 0;
}