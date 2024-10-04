#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//nums{5,7,7,8,8,10};
int mySqrt(int x) 
{
	int i;
	int left = 1;
	int right = x/2;
	int mid;
	if(x == 1)
		return 1;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(mid * mid == x)
			return mid;
		else if(mid * mid < x)
			left = mid + 1; 
		else
			right = mid -1; 
	}
	if(mid * mid > x)
		return mid-1;
	else
		return mid;
}
int main()
{
	//Solution s;
	//vector<int> nums{5,7,7,8,8,10};	// C++ 98 不允许这样 
	int a[] ={1,3,5,7};
	vector<int> nums(a,a+sizeof(a)/sizeof(a[0]));
	int ret = mySqrt(2147395599);
	cout << ret;
	return 0;
} 
