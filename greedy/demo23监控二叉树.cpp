#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :
        val(x), left(left), right(right) {}
};

// 状态0: 无覆盖
// 状态1: 安装摄像头
// 状态2: 有覆盖

int camcer = 0;                // 监控数量

// 返回左右节点识别被监控
int traversal(TreeNode* root)
{
    // 空节点已监控
    if(root == nullptr)
        return 2;

    int left  = traversal(root->left);
    int right = traversal(root->right);

    // X 1.  左右覆盖      父节点无覆盖   
    if(left == 2 && right == 2)
        return 0;
    // √ 2. 左右至少有一个无覆盖
    if(left == 0 || right == 0) {
        camcer++;
        return 1;
    }
    // √ 3. 左右至少有一个有摄像头
    if (left == 1 ||  right == 1)
        return 2;

    // 逻辑不会到这 随便返回 防报错
    return -1;
}

int minCameraCover(TreeNode* root) {
    camcer = 0;
    // X 4. 特殊情况 到根节点无覆盖
    int ret = traversal(root);
    if(ret == 0)
        camcer++;
    return camcer;
}

TreeNode* initTree()
{
    TreeNode* root = new TreeNode();
    root->left = new TreeNode();
    root->left->left = new TreeNode();
    root->left->right = new TreeNode();
    return root;
}


int main()
{
    TreeNode* root = initTree();
    int res = minCameraCover(root);
    cout << "res: " << res;
}
