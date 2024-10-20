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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    // 1. 后续遍历为空 空节点
    if (postorder.size() == 0)
        return nullptr;

    // 2. 获取根节点数据（后续遍历的最后一个元素） 
    int midNum = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(midNum);

    // 3. 查找根节点在中序遍历中的位置 
    int midIdx = find(inorder.begin(), inorder.end(), midNum) - inorder.begin();

    // 4. 根据根节点位置 将中序遍历数组 切割成左右子树
    vector<int> leftInorder (inorder.begin(), inorder.begin() + midIdx);
    vector<int> rightinorder(inorder.begin() + midIdx + 1, inorder.end());

    // 获取左右子树长度
    int size1 = leftInorder.size();
    int size2 = rightinorder.size();

    // 5. 切割后续遍历的左右子树
    vector<int> leftPostOrder (postorder.begin(), postorder.begin() + size1);
    vector<int> rightPostOrder(postorder.begin() + size1, postorder.begin() + size1 + size2);

    // 6. 递归创建左右子树
    root->left  = buildTree(leftInorder, leftPostOrder);
    root->right = buildTree(rightinorder, rightPostOrder);

    return root;
}
int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};
    TreeNode* newTree = buildTree(inorder,postorder);
    
    vector<vector<int>> dst = levelOrder(newTree);
    showDoubleVec(dst);
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