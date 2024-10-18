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

vector<int > path;      // 节点数值
vector<string> res;     // 结果

void traversal(TreeNode* root)
{
    path.push_back(root->val);

    // 到叶子节点了 拼接字符串 收集结果
    if (root -> left == nullptr && root ->right == nullptr) {
        string buf;
        for (int  i = 0; i < path.size() - 1; i++)
        {
            buf += to_string(path[i]);
            buf += "->";
        }
        buf += to_string(path[path.size()-1]);
        res.push_back(buf);
        return;
    }

    // 还没到叶子节点
    // 递归遍历左右非空节点
    if (root -> left) {
        traversal(root->left);
        path.pop_back();    //回溯
    }
    if (root -> right)  {
        traversal(root->right);
        path.pop_back();    //回溯
    }
}

vector<string> binaryTreePaths(TreeNode* root) 
{
    if (root == nullptr)    return {""};
    traversal(root);
    return res;
}

int main()
{
    TreeNode* root = init_tree();
    //vector<vector<int>> src = levelOrder(root);
    //showDoubleVec(src);
    vector<string> res = binaryTreePaths(root);
    for (string path:res){
        cout << path << endl;
    }
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left ->left  = new TreeNode(3);
    root->left ->right = new TreeNode(5);
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