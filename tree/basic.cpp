#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

TreeNode* initTree() 
{  
    // 构建一个简单的二叉树  
    TreeNode* root = new TreeNode(5);
    root->left  = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left   = new TreeNode(1);
    root->left->right  = new TreeNode(2);
    root->right->left  = new TreeNode(7);
    root->right->right = new TreeNode(8);

    return root;  
}  

// 创建二叉树
TreeNode* createTree()
{
    int val;  
    cout << "输入节点值(输入-1表示空节点): ";  
    cin >> val;  

    if (val == -1) {  
        return nullptr; // 返回空指针  
    }  

    // 创建新节点
    TreeNode* node = new TreeNode(val);
    //创建左子树
    node->left = createTree();
    node->right = createTree();
    // 返回根节点
    return node;
}

//二叉树的递归遍历
/* 
// 二叉树的递归前序遍历    Preamble
void preOrder(TreeNode* root)
{
    if (root == nullptr){
        return;
    }
    cout << root->val << " ";   // 访问根节点  
    preOrder(root->left);       // 递归遍历左子树
    preOrder(root->right);      // 递归遍历右子树
}

// 二叉树的递归中序遍历    
void inOrder(TreeNode* root)
{
    if (root == nullptr){
        return;
    }
    inOrder(root->left);       // 递归遍历左子树
    cout << root->val << " ";   // 访问根节点  
    inOrder(root->right);       // 递归遍历右子树
}

// 二叉树的递归后序遍历 Postscript
void posOrder(TreeNode* root)
{
    if (root == nullptr){
        return;
    }
    posOrder(root->left);       // 递归遍历左子树
    posOrder(root->right);       // 递归遍历右子树
    cout << root->val << " ";   // 访问根节点  
}
*/


// 二叉树的层序遍历

//二叉树的迭代前序遍历
/*
 vector<int> preOrder(TreeNode* root)
 {
    stack<TreeNode*> st;
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    st.push(root);
    while (!st.empty())
    {
        //获取中间节点并保存结果
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);
        // 先加右节点 因为栈是先入后出
        // 右节点入栈（空节点不入栈）
        if (node->right)    st.push(node->right);
        // 左节点入栈（空节点不入栈）
        if (node->left)     st.push(node->left);
    }
    return res;
 }

//二叉树的迭代中序遍历
 vector<int> inOrder(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    TreeNode* cur = root;
    while (!st.empty() || cur != NULL)
    {
        // 处理最左边节点
        if (cur != nullptr) {       // 指针来访问节点，访问到最底层
            st.push(cur);           // 将访问的节点放进栈
            cur = cur->left;        // 左
        }
        else {
            // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            cur = st.top();
            st.pop();
            res.push_back(cur->val);    // 中 
            cur = cur->right;           // 右
        }
    }
    return res;
}

//二叉树的迭代后续遍历
 vector<int> preOrder(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    st.push(root); 
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);               // 收集中间节点数据
        // 相对于前序遍历，这更改一下入栈顺序
        if (node->left)  st.push(node->left);   // 左节点入栈
        if (node->right) st.push(node->right);  // 右节点入栈
    }
    // 左右中 <- 中右左
    reverse(res.begin(), res.end());
    return res;
}
*/



// 迭代遍历复习
void preOrder(TreeNode* root)
{
    if (root == nullptr)
        return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        cout << node->val;     // 中
        if (node->right)    st.push(node->right);
        if (node->left)     st.push(node->left);    
    } 
    return;
}

void inOrder(TreeNode* root)
{
    if (root == nullptr)
        return;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty())
    {
        // 处理最左边节点
        if (cur != nullptr) {       // 指针来访问节点 访问到最底层
            st.push(cur);           // 每次访问节点入栈
            cur = cur->left;        // 左
        }
        else
        {
            cur = st.top();         //从栈里弹出的数据，就是要处理的数据(放进result数组里的数据)
            st.pop();
            cout << cur->val;       // 中
            cur = cur->right;       // 右
        }        
    }
    return;
}


vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if (root != nullptr)   
        que.push(root);
    while (!que.empty())
    {
        int size = que.size();                  // 获取每一层节点数
        vector<int> vec(size);                  // 每层的节点容器
        for (int i = 0; i < size; i++){         // 遍历层的每个节点
            TreeNode* node = que.front();       
            que.pop();

            vec[i] = node->val;                     // 收集每一层结果      
            if(node->left)  que.push(node->left);   // 加入左子树节点
            if(node->right) que.push(node->right);  // 加入右子树节点
        }
        res.push_back(vec);
    }
    return res;
}

void deleteTree(TreeNode* root)
{
    if (root == root) {
        return;
    }
    deleteTree(root->left);      // 删除左子树  
    deleteTree(root->right);     // 删除右子树   
    delete root;                 // 删除当前节
}

int main()
{
    // 创建树
    TreeNode* root = initTree(); 
    vector<vector<int>> res = levelOrder(root); // 前序遍历
    for (auto line: res){
        for (int num: line){
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "preOrder" << endl;
    preOrder(root);
    cout << endl;


    cout << "inOrder" << endl;
    inOrder(root);
    cout << endl;

    deleteTree(root);   // 释放内存    
    return 0;   
}