#include <iostream>
#include <vector>

using namespace  std;

int n;		//节点数量

vector<int> fa(n+1);

void init()
{
	for(int i = 0; i < n;i++)
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
	return u_fa == v_fa;
}


int main()
{
	int s, t;
	cin >> n;
	init();
	
	for(int i = 0; i < n; i++)
	{
		cin >> s >> t;
		if(isSame(s,t))
		{
			cout << s << " " << t << endl;
			return 0;
		}
		else
			join(s,t);
	}
}
