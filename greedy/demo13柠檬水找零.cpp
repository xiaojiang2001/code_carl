#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace  std;    


bool lemonadeChange(vector<int>& bills) {
    // 钱的张数
    int cnt5  = 0;
    int cnt10 = 0;
    int cnt20 = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        switch (bills[i])
        {
            case 5: cnt5++; break;

            case 10:
            {
                cnt10++;
                cnt5--;
                if(cnt5 < 0)
                    return false;
            }
            break;

            case 20:
            {
                cnt20++;
                // 贪在有10块的先找零
                if(cnt10 > 0) {
                    cnt10--;
                    cnt5--;
                }
                else {
                    cnt5 -= 3;
                }
                if(cnt5 < 0)
                    return false;
            }
            break;
        }
    }
    return true;
}


int main()
{
    vector<int> bills{5,5,10,10,20};
    bool res = lemonadeChange(bills);
    cout << "res: " << res << endl;
}
