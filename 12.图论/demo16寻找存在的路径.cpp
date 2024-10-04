#include <iostream>
#include <vector>

using namespace  std;


int n;		//节点数量
vector<int> fa(n+1);

void init()
{
	for(int i = 1; i <= n; i++)
		fa[i] = i;
}

int find(int i)
{
	if(fa[i] == i)
		return i;
	else
	{
		fa[i] = find(fa[i]);
		return fa[i];
	}
}

void join(int u, int v)
{
	int u_fa = find(u);
	int v_fa = find(v);
	if(u_fa == v_fa)
		return;
	fa[v_fa] = u_fa;
}

bool isSame(int u, int v)
{
	int u_fa = find(u);
	int v_fa = find(v);
	if(u_fa == v_fa)
		return true;
	else
		return false;
}

int main()
{
	int m, s, t, src, dst;
	cin >> n >> m;
	init();
	while(m--)
	{
		cin >> s >> t;
		join(s,t);
	}
	cin >> src >> dst;
	if(isSame(src,dst))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	
	return 0;	
}
