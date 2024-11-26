#include <iostream>
#include <vector>

using namespace  std;

bool canJump(vector<int>& nums) 
{
    // 贪在最大的覆盖范围 最后一个不用跳了
    int cover = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        // 记录最大的覆盖范围
        cover = max(cover, i + nums[i]);
        // 覆盖不到后面格子
        if(cover <= i)
            return false;
    }
    return cover >= nums.size() - 1 ? true : false;
}
  

int main()
{
    vector<int> nums {0,2,3};
    bool res = canJump(nums);
    cout << "res: " << res << endl;
}