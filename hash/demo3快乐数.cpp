#include <iostream>
#include <unordered_set>

using namespace std;

int get_sum(int n)
{
	int sum = 0;
	int num = 0;
	while(n){
		num = n % 10;
		sum += num * num; 
		n /= 10;
	}
	return sum;
}

bool isHappy(int n) {
	unordered_set<int> uset;
	while(1){
		int sum = get_sum(n);
		cout << sum << endl;
		if(sum == 1)	return true;
		// sum 重复出现
		if(uset.find(sum) != uset.end()){
			return false;
		}
		//sum未出现过 加入容器
		else
			uset.insert(sum);
		n = sum;
	}
}


int main()
{
	int n = 19;
	bool ret = isHappy(n);
	cout << "ret:" << ret << endl;
	return 0;
}
