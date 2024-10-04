#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//本题可以分隔单词，然后定义一个新的string字符串，
	//最后再把单词倒序相加，但这就失去了它的意义。
	//不要使用辅助空间，空间复杂度要求为O(1)。
	//我们将整个字符串都反转过来，那么单词的顺序指定是倒序了，
	//只不过单词本身也倒序了，那么再把单词反转一下，单词不就正过来了。
	
	//所以解题思路如下：
	//1. 移除多余空格			双指针删除
	//2. 将整个字符串反转		
	//3. 将每个单词反转			自定义区间的翻转
	
	//去除所有空格并在相邻单词之间添加空格, 快慢指针
	void removeExtraSpaces(string& s) 
	{
		int slow= 0;
		for(int fast = 0; fast < s.size(); fast++){
			if(s[fast] != ' ')		 //遇到非空格就处理，即删除所有空格。
			{
				if(slow != 0)
					s[slow++] = ' ';		// 补上单词
				while(fast < s.size() && s[fast] != ' ')
					s[slow++] = s[fast++];
			}
		}
		s.resize(slow);
	}
	
	//指定区域的翻转
	void reverswWord(string& s, int left, int right)
	{
		while(left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
	
	string reverseWords(string& s) 
	{
		//删除多余的空格
		removeExtraSpaces(s);
		
		//翻转字符串
		reverswWord(s, 0, s.size()-1);
		
		//翻转每个单词
		int left = 0;
		for(int right = 0; right <= s.size(); right++)
		{
			if(s[right] == ' ' || right == s.size())
			{
				//翻转，注意是左闭右闭 []的翻转。
				reverswWord(s, left, right-1);
				//更新下一个单词的开始下标start
				left = right + 1;
			}
		}

		return s;
	}

};


int main()
{
	Solution s;
	string str = {"the sky is blue"};
	// cin >> str;
	string ret = s.reverseWords(str);
	cout << ret << endl;
}




