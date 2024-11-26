#include <iostream>
#include <vector>

using namespace  std;

int maxProfit(vector<int>& prices) 
{
    int sum = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        // 贪心 只要有一天有收入就进行买卖
        if (prices[i+1] > prices[i])
            sum += prices[i+1] - prices[i];      
    }
    return sum;
}

int main()
{
    vector<int> price{1,2,3,4,5};
    int res = maxProfit(price);
    cout << "res: " << res << endl;
}