#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace  std;    
    
int candy(vector<int>& ratings) {
    // 初始化结果集 每人至少一颗
    vector<int> res(ratings.size(), 1);

    // 右孩子更大
    for (int i = 0; i < ratings.size() - 1; i++) {
        if(ratings[i] < ratings[i+1])
            res[i+1] = res[i] + 1;      // 直接多一颗
    }

    // 左孩子更大 这里要逆序
    for (int i = ratings.size() - 1; i > 0; i--) {
        if(ratings[i-1] > ratings[i]) {
            res[i-1] = max(res[i-1], res[i]+ 1);        // 还要考虑上面顺序后，手上的糖果
        }
    }

    return accumulate(res.begin(), res.end(), 0);
}


int main()
{
    vector<int> ratings{1,2,2};
    int res = candy(ratings);
    cout << "res: " << res << endl;
}
