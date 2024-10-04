#include <iostream>
#include <vector>
#include <math.h>
#include <string>
 
using namespace std;

bool isAnagram(string s, string t) {
	// 1 易 未看视频  数组 解出
	int i;
	int len1 = s.size();
	int len2 = t.size();
		
//	int tabel1[128] = {0};
//	int tabel2[128] = {0};

	//视频优化 减少数组大小
	int tabel1[26] = {0};
	int tabel2[26] = {0};
	
	 
	for(i = 0; i < len1; i++)
	{
		cout << s[i] << endl;
		tabel1[s[i]-97] = ++;
	}
	
	for(i = 0; i < len2; i++)
	{
		cout << t[i] << endl;
		tabel2[t[i]-97] = ++;
	}
	
	for(i = 0; i < 26; i++)
	{
		if(tabel1[i] != tabel2[i])
			return false;
	}
	return true;
}

int main()
{
	bool ret;
	
	string s = "hello";
	string t = "loeh";
	
	ret = isAnagram(s,t);
	cout << ret;
	
	return 0;
} 





