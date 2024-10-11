#include <iostream>

using namespace std;



bool isAnagram(string s, string t) {
	if(s.size() != t.size()){
		return false;
	}
	
	//统计字母频率
	int hash1[26] = {0};
	int hash2[26] = {0};
	for(int i = 0; i < s.size(); i++)
	{
		hash1[s[i] - 'a']++;
		hash2[t[i] - 'a']++;
	}
	
	//判断字母频率是否相等
	for(int i = 0; i < 26; i++){
		if(hash1[i] != hash2[i]){
			return false;
		}
	}
	
	return true;
}


int main()
{
	string s = {"anagram"};
	string t = {"nagaram"};
	bool ret = isAnagram(s,t);
	cout << ret << endl;
	return 0;
}
