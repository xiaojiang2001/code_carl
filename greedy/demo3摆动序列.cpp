#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
    
int wiggleMaxLength(vector<int>& nums) {
    // int prediff = nums[i] - nums[i-1];
    // int curdiff = nums[i+1] - nums[i];
   
    if(nums.size() == 1)
        return 1;
    int result = 1;     // 默认数组尾有一个摆动
    int prediff = 0;    // 类似添加了一个虚拟头节点 平坡 
    int curdiff;        // 初始化任意值均可
    for (int i = 0; i < nums.size() - 1; i++)
    {
        curdiff = nums[i+1] - nums[i]; 
        if(prediff <= 0 && curdiff > 0 || prediff >= 0 && curdiff < 0) {
            result++;
            prediff = curdiff;
        }
    }
    return result;
}
int main()
{
    vector<int> nums{3,3,3,2,5};
    int res = wiggleMaxLength(nums);
    cout << "res: " << res << endl;
    return 0;
}