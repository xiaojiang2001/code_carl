#include <iostream>

using namespace std;

bool isLongPressedName(string name, string typed) 
{
    int i = 0;      // name的下标
    int j = 0;      // typed的下标    
    while (i < name.size() && j < typed.size())
    {
        // 相等
        if(name[i] == typed[j]){
            i++;
            j++;
        }
        // 不相等
        else{
            if(j == 0)  return false;   // 第一位就不相等
            // 跳过长按项目
            while (j < typed.size() && typed[j] == typed[j-1]) {
                j++;
            }
            if(name[i] == typed[j]) {
                i++;
                j++;
            }
            else
                return false;
        }
    }
    
    // 未匹配完
    // 说明name没有匹配完
    if (i < name.size()) 
        return false;
    // typed未匹配完，是长按还是其他字符
    while (j < typed.size()) {
        if(typed[j] == typed[j-1])
            j++;
        else
            return false;
    }
    return true;
}

int main()
{
    string name =  "alex";
    string typed = "aaleex";
    bool ret = isLongPressedName(name, typed);
    cout << ret << endl;
    return 0;
}