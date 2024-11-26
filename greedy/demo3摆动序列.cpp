#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
    
int wiggleMaxLength(vector<int>& nums) {
    // 插入个0, 计算第一个差值
    nums.insert(nums.begin(), 0);
    unordered_set<int> uset;
    for (int i = 0; i < nums.size(); i++)
        uset.insert(nums[i]);

    int res = 1;    
    // 初始化第一个差值性
    if (uset.size() <= 1)
        return uset.size();
    auto it = uset.begin();

    for (int i = 0; i < nums.size() - 1; i++)
    {
        // 计算当前差值性
        bool temp = nums[i+1] - nums[i] > 0 ? true : false;

        // 判断差值性是否一致
        if (temp == flag && nums[i+1] != nums[i]) {
            flag = !flag;
            res++;
        }    
    }
    return res;
}

int main()
{
    vector<int> nums{3,3,3,2,5};
    int res = wiggleMaxLength(nums);
    cout << "res: " << res << endl;
    return 0;
}