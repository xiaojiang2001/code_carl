#include <iostream>
#include <vector>

using namespace std;

//需要额外空间 ret
string replaceNum(string& s)
{
	string ret;
	for(int i = 0; i <  s.size(); i++)
	{
		//遇到数字
		if(s[i] >= '0' && s[i] <= '9')
			ret.insert(ret.size(), "number");
		else		//字母
			ret += s[i];
	}
	return ret;
}

//极值版：不使用额外空间 ret 双指针
void replaceNum2(string& s)
{
	int cnt = 0;	//统计数字出现的个数 为了扩充空间
	for(int i = 0; i <  s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			cnt++;
	}
	
	// left 对旧字符串从右向左遍历
	int left = s.size()  - 1;		
	s.resize(s.size() + 5 * cnt);
	// left 对新字符串从右向左遍历
	int right = s.size() - 1;	
	while(left < right)
	{
		if(s[left] >= '0' && s[left] <= '9')
		{
			s[right--] = 'r';
			s[right--] = 'e';
			s[right--] = 'b';
			s[right--] = 'm';
			s[right--] = 'u';
			s[right--] = 'n';
		}
		else
			s[right--] = s[left];
		left--;
	}
}

int main()
{
	string str;
	cin >> str;
	replaceNum2(str);
	cout << str;
}
