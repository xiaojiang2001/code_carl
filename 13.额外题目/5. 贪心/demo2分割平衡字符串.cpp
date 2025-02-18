#include <bits/stdc++.h>

using namespace std;

int balancedStringSplit(string s) 
{
    int res = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'R') 
            cnt1++;
        else if(s[i] == 'L')
            cnt2++;
        // 分割
        if(cnt1 == cnt2) {
            cnt1 = 0;
            cnt2 = 0;
            res++;
        } 
    }
    return res;
}

int main()
{
    
}