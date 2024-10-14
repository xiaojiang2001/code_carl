#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

// 自定义排序
class cmp
{
public:
    bool operator()(const pair<int, int>& pair1, const pair<int, int>& pair2) {
        return pair1.second > pair2.second;
    }
};

 vector<int> topKFrequent(vector<int>& nums, int k)
 {
    // 将数字和频率做映射
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        umap[nums[i]]++;
    }

    //创建小顶堆 根据频率排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
    for (auto it : umap)
    {
        // 一开始未满 开始存数据
        if (que.empty() || que.size() < k){
            que.push({it.first, it.second});
        }
        // 遇到频率更大的
        else if(it.second > que.top().second)
        {
            que.pop();
            que.push({it.first, it.second});
        }
    }

    // 从队列中收集结果
    vector<int> res;
    while (!que.empty()) {
        res.push_back(que.top().first);
        que.pop();
    }
    return res;
 }


int main()
{
    vector<int> arg{1,1,1,2,2,3};
    vector<int> res = topKFrequent(arg,2);
    for(int num: res)
        cout << num << " ";
    cout << endl;
    return 0;
}

