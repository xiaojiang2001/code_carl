#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
	{
		int money5 = 0;
		int money10 = 0;
		for(int i = 0; i < bills.size();i++)
		{
			if(bills[i] == 5)
				money5++;
			else if(bills[i] == 10)
			{
				money10++;
				if(money5 > 0)	
					money5--;
				else
					return false;
			}
			else if(bills[i] == 20)
			{
				if(money5 > 0 && money10 > 0)
				{
					money5--;
					money10--;
				}
				else if(money5 >= 3)
					money5 -= 3;
				else
					return false;
			}
		}
		return true;
    }
};

int main()
{
	Solution solution;
	vector<int> g{5,5,10,10,20};
	vector<int> s{1,1};
	bool res = solution.lemonadeChange(g);
	cout << "res: " << res << endl;
	return 0;
}