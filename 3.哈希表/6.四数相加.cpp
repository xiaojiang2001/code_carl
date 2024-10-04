#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


 // ☆☆☆ map + 哈希
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
{
        //key:a+b的数值，value:a+b数值出现的次数
        unordered_map<int,int> map;
        
        // 遍历nums1和nums2数组，统计两个数组元素之和，和出现的次数，放到map中  
        //遍历nums1 和 nums2 数组 
        // for(int i: nums1)
        // {
        //     for(int j: nums2)
        //          map[i+j]++;
        // }

        int i,j;
        for(i = 0; i < nums1.size(); i++)
        {
            for(j = 0; j < nums2.size(); j++)
            {
                map.insert(make_pair(nums1[i]+nums2[j], 0));
                map[nums1[i]+nums2[j]]++;
            }    
        }

        //遍历nums3 和 nums4 数组 
        //找到如果 0-i-j 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
        int cnt = 0;
        // for(int i: nums3)
        // {
        //     for(int j: nums4)
        //     {
        //         auto iter = map.find(0-i-j);
        //         if(iter != map.end())
        //         {
        //             cnt += map[0-i-j];
        //         }
        //     }
        // }


        for(i = 0; i < nums3.size(); i++)
        {
            for(j = 0; j < nums4.size(); j++)
            {
                auto iter = map.find(-nums3[i]-nums4[j]);
                if(iter != map.end())
                {
                    cnt += map[-nums3[i]-nums4[j]];
                }
            }    
        }
        return cnt;
		
}

int main()
{
	unordered_map<int,int> map{{1,85}};
	auto iter = map.insert({2,90});
	
	return 0;
} 





