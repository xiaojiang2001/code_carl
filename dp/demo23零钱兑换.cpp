#include <vector>
#include <iostream>

using namespace std;

int coinChange(vector<int>& coins, int amount) 
{
    
}

int main()
{
    vector<int> coins{1, 2, 5};
    int amount = 11;
    int ret = coinChange(coins, amount);
    cout << "ret: " << ret;
}