#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;  

vector<int> partitionLabels(string s) {
    vector<int>  res;

}

int main()
{
    string s = "ababcbacadefegdehijhklij";
     vector<int> res = partitionLabels(s);
    for (int num : res)
        cout << num << " ";
}