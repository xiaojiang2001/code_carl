#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void rever(string& s, int left, int right)
	{
		while(left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
	string reverseStr(string s, int k) 
	{
		for(int i = 0; i < s.size(); i += 2 * k)
		{
			//如果剩余字符少于 k 个，则将剩余字符全部反转。
			if(i + k >=  s.size())
				rever(s, i, s.size() - 1);
			else		//反转前 k 个字符
				rever(s, i, i + k - 1);		// 因为 rever 左闭右闭 这里需要-1
		}
		return s;
	}
};


int main()
{
	Solution s;
	string str = {"abcdefg"};
	int k = 2;
	string ret = s.reverseStr(str,k);
	cout << ret << endl;
}




