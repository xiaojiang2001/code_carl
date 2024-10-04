#include <iostream>
#include <vector>
#include <math.h>
#include <string>
 
using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
	// 1 易
	int i;
	int len1 = ransomNote.size();
	int len2 = magazine.size();
		
	//视频优化 减少数组大小
	int tabel1[26] = {0};
	int tabel2[26] = {0};
	
	 
	for(i = 0; i < len1; i++)
	{
		cout << ransomNote[i] << endl;
		tabel1[ransomNote[i]-97] ++;
	}
	
	for(i = 0; i < len2; i++)
	{
		cout << magazine[i] << endl;
		tabel2[magazine[i]-97] ++;
	}
	
	for(i = 0; i < 26; i++)
	{
		if(tabel1[i] > tabel2[i])
			return false;
	}
	return true;
}

int main()
{
	bool ret;
	
	string s = "aa";
	string t = "aab";
	
	ret = canConstruct(s,t);
	cout << ret;
	
	return 0;
} 





