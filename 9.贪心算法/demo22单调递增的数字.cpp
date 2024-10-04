#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool judge(int num)	// 10
	{
		int max = 10;
        while (num) 
		{
            int t = num % 10;
            if (max >= t) 
				max = t;
            else 
				return false;
            num = num / 10;
        }
        return true;
	}
    int monotoneIncreasingDigits(int n) 
	{
		string strNum = to_string(n);
		int flag = strNum.size();			// 标记才哪开始起全部赋值为9
		for(int i = strNum.size()-1; i > 0; i--)
		{
			if(strNum[i-1] > strNum[i])		// 第一次出现非递增情况
			{
				strNum[i-1]--;
				flag = i;					// 记录下标，后面全部赋值为9
			}	
		}
		for(int i = flag; i < strNum.size(); i++)
			strNum[i] = '9';
			
		return stoi(strNum);
    }
};
int main()
{
	Solution solution;
	vector<vector<int>> g{{1,2},{3,6},{7,12},{4,8},{10,16}};
	vector<int> s{1,1};
	//int res = solution.eraseOverlapIntervals(g);
	//cout << "res: " << res << endl;
	return 0;
}