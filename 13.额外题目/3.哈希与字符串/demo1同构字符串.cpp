#include <iostream>
#include <unordered_map>


using namespace std;

bool isIsomorphic(string s, string t) 
{
	unordered_map<char, char> map1;
	unordered_map<char, char> map2;
	
	for(int i = 0; i < s.size(); i++)
	{
		//未出现过 进行映射
		if(map1.find(s[i]) == map1.end()){
			map1[s[i]] = t[i];
		}
		if(map2.find(t[i]) == map2.end()){
			map2[t[i]] = s[i];
		}
		// 出现过了 进行判断
		if(map1[s[i]] != t[i] || map2[t[i]] != s[i]){
			return false;
		}
	}
	return true;
}


int main()
{

}
