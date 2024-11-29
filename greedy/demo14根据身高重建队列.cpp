#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;  

// 先根据人数排序
static bool cmp(vector<int>& left, vector<int>& right)
{
    if(left[0] != right[0])
        return left[0] > right[0];
    else
        return left[1] < right[1];
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // 身高从大到小排，确定了每个人前面身高更高
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> res;
    // 根据k插入到队列 因为前面的都比他高 那么就是根据k依次确定下标
    for (auto it : people) {
        res.insert(res.begin() + it[1], it);
    }
    return res;
}

int main()
{
    vector<vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    reconstructQueue(people);    
}
