#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	//数据输入
	vector<int> array(n);
	for(int i = 0; i < n; i++)
		cin >> array[i];

	// dp[i]: 加到下标为 i 的时候的总和
	// 也称"前缀和"
	vector<int> dp(n);
	dp[0] = array[0];
	for(int i = 1; i < n;i++)
		dp[i] = dp[i-1] + array[i];
	
	int start;
	int end;
	//计算区间和
	while(cin >> start >> end)
		cout << dp[end] - dp[start] + array[start] << endl;	
	
	return 0;
}

