#include <iostream>
#include <vector>
#include <vector>

using namespace std;

int n;		// 人数

vector<int> fa(n+1);

void init(void)
{
	for(int i = 1; i <= n; i++)
		fa[i] = i;
}  

int find(int i)
{
	if(fa[i] == i)
		return fa[i];
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
	int m, s, t, q;
	cin >> n >> m;
	init();
	while(m--){
		cin >> s >> t;
		join(s,t);
	}
	
	cin >> q;
	vector<bool> res(q+1);
	for(int i = 1; i <= q;i++)
	{
		cin >> s >> t;
		if(isSame(s,t))
			res[i] = true;
		else
			res[i] = false;
	}
	
	for(int i = 1; i <= q;i++)
	{
		if(res[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}
