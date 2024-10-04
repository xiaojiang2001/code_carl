#include <iostream>
#include <vector>
#include <string>

using namespace std;

//翻转函数 左闭右闭
void reverse(string &s, int left, int right)
{
	while(left < right)
	{
		swap(s[left], s[right]);
		left++;
		right--;
	}
}

// 字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面
string RightHandStr(string& s, int k) 
{
	//将字符串分成2段 左侧长度： n - k 右侧 k
	// 1. 整体翻转	-> 改变左右长度  左侧长度： k，   右侧 n - k
	// 2. 对左右两个区间翻转 -> 改变字母顺序
	
	//1. 整体翻转
	reverse(s, 0, s.size()-1);
	
	// 左侧翻转
	reverse(s, 0, k-1);
	
	//右侧翻转
	reverse(s, k, s.size() -1);
	
	return s;
}


int main()
{
	int k;
	cin >> k;
	string str;
	cin >> str;
	string ret = RightHandStr(str,k);
	cout << ret << endl;
}




