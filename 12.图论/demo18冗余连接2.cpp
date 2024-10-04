#include <iostream>
#include <vector>

using namespace std;

int n; 		// 节点个数
vector<int> fa(1001, 0);	

void init(void)
{
	for(int i = 1; i <= n; i++)
		fa[i] = i;
}

int find(int i)
{
	if(i == fa[i])
		return fa[i];
	else{
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


// 删一条边之后判断是不是树
bool isTreeAfterRemoveEdge(vector<vector<int>> &edges, int deleteEdge)
{
	init(); // 初始化并查集
	for(int i = 0; i < n; i++)
	{
		if(i == deleteEdge)
			continue;
		// 构成有向环了，一定不是树
		if(isSame(edges[i][0], edges[i][1]))
			return false;
		join(edges[i][0], edges[i][1]);
	}
	return true;
}

// 在有向图里找到删除的那条边，使其变成树
void getRemoveEdge(const vector<vector<int>>& edges) 
{
	init(); // 初始化并查集
	for(int i = 0; i < n; i++)
	{
		//成环的边
		if(isSame(edges[i][0], edges[i][1]))
		{
			cout << edges[i][0] << " " << edges[i][1];
			return;
		}
		else
			join(edges[i][0], edges[i][1]);
	}
}

int main()
{
	int s, t;
	cin >> n;
	vector<vector<int>> edges;		// 记录边
	vector<int> inDegree(n + 1, 0); // 记录节点入度
	for(int i = 0; i < n; i++)
	{
		cin >> s >> t;
		inDegree[t]++;				// 入节点数++
		edges.push_back({s,t});		// 边如容器
		
	}
	
	vector<int> vec; // 记录入度为2的边（如果有的话就两条边）
	// 找入度为2的节点所对应的边，注意要倒序，因为优先删除最后出现的一条边
	for(int i = n - 1; i >= 0; i--){
		if(inDegree[edges[i][1]] == 2){		//edges[i][1]: 输入时候第i条的入节点
			vec.push_back(i);
		}
	}
	// 有入度为2的节点 情况一、二
	if(vec.size() > 0)
	{
		// 放在vec里的边已经按照倒叙放的，所以这里就优先删vec[0]这条边
		if(isTreeAfterRemoveEdge(edges, vec[0])){
			cout << edges[vec[0]][0] << " " << edges[vec[0]][1]; 
		}
		else{
			cout << edges[vec[1]][0] << " " << edges[vec[1]][1]; 
		}
		return 0;
	}
	
	// 处理情况三
	// 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
	getRemoveEdge(edges);
	return 0;
}


