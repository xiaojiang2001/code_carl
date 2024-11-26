#include <iostream>
#include <vector>

using namespace  std;

int jump(vector<int>& nums) 
{
    if(nums.size() == 1)
        return 0;

    // 贪在最大的覆盖范围 最后一个不用跳了
    int curCover = 0;   // 当前的最大覆盖范围   
    int nextCover = 0;  // 下一步跳完的最大覆盖范围
    int step = 0;       // 步数
   
    for (int i = 0; i < nums.size() - 1; i++) {
        // 记录下一步跳完的最大的覆盖范围
        nextCover = max(nextCover, i + nums[i]);    // 更新下一步覆盖最远距离下标
        if (i == curCover)                          // 遇到当前覆盖最远距离下标
        {
            if ( i != nums.size() - 1)  // 还没到终点
            {
                step++;                 // 启动下一步
                curCover = nextCover;   // 更新当前覆盖最远距离下标（相当于加油了）
                // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
                if(curCover >= nums.size() -1)
                    break;  
            }
            else {
                break;
            }
        }
    }
    return step;
}
  

int main()
{
    vector<int> nums {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    int res = jump(nums);
    cout << "res: " << res << endl;
}