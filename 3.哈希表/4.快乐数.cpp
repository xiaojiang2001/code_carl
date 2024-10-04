#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


bool isHappy(int n) 
{
	//题目中说了会 无限循环，那么也就是说求和的过程中，sum会重复出现，这对解题很重要！
	//重复出现  哈希表
	unordered_set<int> hash_table(0);
	
	int sum = 0;
	int cnt = 0;
    while(n != 1)
    {
    	cout << "n= " << n << endl;
        while(n != 0)
        {
        	
        	sum = sum +  pow(n % 10, 2);
        	n = n/10;
		}
		cout << "sum= " << sum << endl;
		n = sum;
		
		//没想到
		//自己想的 不用哈希 居然通过了力扣系统
/*
		cnt ++;
		if(cnt > 50)
			return false;
*/			
		
		//查找sum是否已经出现过在哈希表中 重复则表示循环了
		if(hash_table.find(sum) != hash_table.end())
			return false;
		
		//往哈希表中插入sum数据
		hash_table.insert(sum);	
			
			
		sum = 0;
    }
    return true;
}


bool isHappy(int n) 
{
	
	
	int sum = 0;
    while(n != 1)
    {
    	cout << "n= " << n << endl;
        while(n != 0)
        {
        	
        	sum = sum +  pow(n % 10, 2);
        	n = n/10;
		}
		cout << "sum= " << sum << endl;
		n = sum;
		

		
		sum = 0;
    }
    return true;
}

int main()
{
	bool ret = isHappy(2);
	cout << "ret= " << ret << endl;
	return 0;
} 





