#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<string> commonChars(vector<string>& words) 
{
	if(words.size() == 0){
		return {""};
	}
	
	int hash[26] = {0};
	// 将第一个单词出现的字符频率存入hash表
	for(int i = 0; i < words[0].size();i++){
		hash[words[0][i] - 'a']++;
	}
	
	//获取后续每个的单词的hash数组
	int hashTemp[26] = {0};
	for(int i = 1; i < words.size();i++){
		//每轮清空hashTemp
		memset(hashTemp, 0, 26 * sizeof(int));
		//获取单词的hash数组
		for(int j = 0; j < words[i].size();j++){
			hashTemp[words[i][j] - 'a']++;
		}
		//每轮更新hash表 求并集
		// 然后hash 和 hashOtherStr 取最小值，这是本题关键所在，
		// 此时取最小值，就是 一个字符在所有字符串里出现的最小次数了。
		for(int i = 0; i < 26; i++){
			hash[i] = min(hash[i], hashTemp[i]);
		}
	}

	//收集结果
	vector<string> res;
	for(int i = 0; i < 26; i++)
	{
		while(hash[i] != 0){
			string s(1, i + 'a');
			res.push_back(s);
			hash[i]--;
		}
	}
	
	return res;
}



int main()
{
	
	return 0;
}
