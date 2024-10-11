#include <iostream>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
	if(ransomNote.size() > magazine.size()){
		return false;
	}
	//统计字典中的每个单词及频率
	int hash[26] = {0};
	for(int i = 0; i < magazine.size();i++){
		hash[magazine[i] - 'a']++;
	}
	//更新字典单词使用次数 小于0 就返回false
	for(int i = 0; i < ransomNote.size(); i++){
		hash[ransomNote[i] - 'a']--;
		if(hash[ransomNote[i] - 'a'] < 0){
			return false;
		}
	}
	return true;
}


int main()
{
	string s = {"anagram"};
	string t = {"nagaram"};
	return 0;
}
