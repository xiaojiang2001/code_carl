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


/*思路1: 遍历树 将数值存入map, 
// 并统计出现的次数，根据次数排序，返回频率最大的几个数*/
/*
unordered_map <int, int> umap; 
void traversal(TreeNode* root)
{
    if (root == nullptr)
        return;
    umap[root->val]++;      // 中 统计每个数的频率
    traversal(root->left);  // 左
    traversal(root->right); // 右
    return;
}

// 按频率降序排序仿函数
bool static cmp(const pair<int, int>& pair1, const pair<int, int>& pair2)
{
    return pair1.second > pair2.second; 
}

vector<int> findMode(TreeNode* root) 
{
    vector<int> result;
    if (root == nullptr)   
        return result;
    traversal(root);

    //map 转 对组类型的vector
    vector<pair<int, int>> vec(umap.begin(), umap.end());
    // 排序
    sort(vec.begin(), vec.end(),cmp);

    // 频率最大的数存入容器
    int maxFre = vec[0].second;
    for (auto pair:vec) {
        if (pair.second < maxFre)
            return result;
        result.push_back(pair.first);
    }
    return result;
}
*/

/*思路2: 递归 中序遍历树 保存当前频率最大的数*/
TreeNode* pre = nullptr;    // 指向上个数
vector<int> res;            // 结果集
int cnt = 0;                // 当前数据的频率
int maxCnt = 0;             // 目前的最大频率
void traversal(TreeNode* root)
{
    if (root == nullptr)    
        return;

    traversal(root->left);  //左

    // 中
    if (pre == nullptr)             // 起点
        cnt = 1;
    else if(root->val == pre->val)  // 数值相等
        cnt++;
    else                             // 新的更大的数据
        cnt = 1; 
    pre = root;                     // 更新慢指针

    //收获频率相等的数
    if (cnt == maxCnt)
        res.push_back(root->val);
    // 频率更大的数
    else if(cnt > maxCnt)
    {
        res.clear();                // 清空结果集
        res.push_back(root->val);   // 保存新的结果
        maxCnt = cnt;               // 更新最大值
    }

    traversal(root->right); // 右
}
vector<int> findMode(TreeNode* root) 
{
	traversal(root);
	return res;
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    vector<int> res = findMode(root);
    for (int num:res)
        cout << num << " ";
    cout << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(1);
    //root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
    //root->left ->left  = new TreeNode(1);
    //root->left ->right = new TreeNode(3);
     root->right->left  = new TreeNode(2);
    // root->right->right = new TreeNode(3);
    // root->left ->right->right = new TreeNode(1);
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