#include <iostream>
#include <string>

using namespace std;


int monotoneIncreasingDigits(int n) {
    string s = to_string(n);
    // 从后往前遍历 遇到递增的前面数-1，后面全部变9(贪心)
    for (size_t i = s.size() - 1; i > 0; i--)
    {
        if(s[i] < s[i-1])
        {
            s[i-1]--;
            s.replace(i, s.size() - i, s.size() - i, '9');
        }
    }
    return stoi(s);
}

int main()
{
    int num = 10;
    int ret = monotoneIncreasingDigits(num);
    cout << "res: " << ret <<  endl;
    return 0;
}