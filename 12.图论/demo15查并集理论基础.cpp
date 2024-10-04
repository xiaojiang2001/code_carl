#include <iostream>
#include <vector>

using namespace std;

int n = 100;

vector<int> fa(n,0);

// 并查集初始化
void init()
{
	for(int i = 0; i < n; i++)
		fa[i] = i;
}
// 并查集里寻根的过程
int find(int i)
{
	if(fa[i] == i)
		return fa[i];			//递归出口，当到达了祖先位置，就返回祖先
	else
	{
		fa[i] = find(fa[i]);	// 	不断往上查找祖先
		return fa[i];
	}
}

void join(int u, int v)
{
	int u_fa = find(u);		// 寻找u的根
	int v_fa = find(v);		// 寻找v的根
	// 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
	if(u_fa == v_fa)
		return;
	//否则v的根 = u的根
	else
		fa[v_fa] = u_fa;
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v)
{
	int u_fa = find(u);
	int v_fa = find(v);
	//根相同
	if(u_fa == v_fa)
		return true;
	else
		return false;
}

int main()
{
	
	
	
	return 0;	
}
