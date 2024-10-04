#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;


void show(vector<int> &v)
{
	//非常常用的容器遍历方式 必须熟悉
	vector<int>::iterator it;	//创建vector容器迭代器
	for(it=v.begin(); it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


 // 双指针法 如何去重是关键
vector<vector<int>> threeSum1(vector<int>& nums) 
{
    vector<vector<int>> ret;	//结果容器
    
    //先从小到大排序
    int i,j, min, temp;
    for(i = 0; i < nums.size(); i++)
    {
        min = i;
        for(j = i+1; j < nums.size(); j++)
        {
            if(nums[j] < nums[min])
                min = j;
        }
        if(min != i)
        {
            temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
    
    //容器排序 可以选用自带的排序算法 要头文件
    //sort(nums.begin(),nums.end());
    
    
    
    
    
    // 找出a + b + c = 0
    // a = nums[i], b = nums[left], c = nums[right]
    int left, right; 
    for(i = 0; i < nums.size(); i++)
    {
    	// 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
    	if(nums[i] > 0)
    		break;
    		
    	// 错误去重a方法，将会漏掉-1,-1,2 这种情况
        /*
        if (nums[i] == nums[i + 1]) {
                continue;
        }
        */
    	
    	//如何去重是关键  对加数a进行去重 
     	if(nums[i] == nums[i-1] && i > 0)
    		continue;
    		
        left = i+1;
        right = nums.size() - 1;
		
		 
        while(left < right)
        {
    	    // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
    	    //因此b,c 的去重要放在收集结果后面
            /*
            while (right > left && nums[right] == nums[right - 1]) right--;
            while (right > left && nums[left] == nums[left + 1]) left++;
            */
            
            if(nums[i] + nums[left] + nums[right] > 0)
                right--;
            else if(nums[i] + nums[left] + nums[right] < 0)
                left++;
            else
            {
            	ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
            	
            	// 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
            	// while去重 而不是if 可能有多个重复
            	while (nums[right] == nums[right-1])
            		right--;
            	while (nums[left] == nums[left+1])
            		left++;
            	
            	// 找到答案时，双指针同时收缩
            	right--;
                left++;
            }
        }
    }

    return ret;
}

void show_vetor2(vector< vector<int> > &v)
{
	for(vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)	//创建大容器迭代器
	{
		//*it ------vector<int> 还是个容器
		for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)	//创建小容器迭代器
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}




vector<vector<int>> threeSum2(vector<int>& nums) 
{
	//哈希法
	vector<vector<int>> ret;	//结果容器
	
	int i,j;
	
	sort(nums.begin(),nums.end());
	show(nums);
	
	
	// 找出a + b + c = 0
    // a = nums[i], b = nums[j], c = -(a + b)
	for(i = 0; i < nums.size(); i++)
	{
		// 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
		if(nums[i] > 0)
			break;
		//三元组元素a去重
		if(i > 0 && nums[i] == nums[i-1] )
			continue;
		
		unordered_set<int> uset;
		for(j = i + 1; j < nums.size(); j++)
		{
			// 三元组元素b去重
			if(j > i+2 && nums[j] == nums[j-1] && nums[j] == nums[j-2])
				continue;
				
			int c = 0-nums[i]-nums[j];
			if(uset.find(c) != uset.end())
			{
				ret.push_back({nums[i],nums[j],c});
				uset.erase(c);// 三元组元素c去重
			}
			else
				uset.insert(nums[j]);
		}
	}
	return ret;
}
int main()
{
	vector< vector<int> > ret;
	
	vector<int> nums{-1,0,1,2,-1,-4};
	
	ret = threeSum2(nums);
	
	show_vetor2(ret);
	
	return 0;
} 





