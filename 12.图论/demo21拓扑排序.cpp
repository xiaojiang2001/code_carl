#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	int s, t;
	vector<int> inDegree(n, 0); 			// 记录每个节点的入度
	vector<int> result;  					// 记录结果排序集
	unordered_map<int, vector<int>> umap;	// 记录依赖关系
	while(m--)
	{
		cin >> s >> t;
		inDegree[t]++;				// s->t t的入度++
		umap[s].push_back(t);		// 记录节点s指向哪些节点 建立依赖
	}
	
	//找入度为0 的节点，我们需要用一个队列放存放。
	//因为每次寻找入度为0的节点，不一定只有一个节点，可能很多节点入度都为0，
	//所以要将这些入度为0的节点放到队列里，依次去处理。
	queue<int> que;
	for(int i = 0; i < n; i++)
	{
		if(inDegree[i] == 0)
			que.push(i);
	}
	//队列不为空 存在入度0的节点
	while(que.size())
	{
		int  cur = que.front(); // 当前选中的节点
		que.pop();
		result.push_back(cur);	//当前节点加入结果集
		vector<int> nodes = umap[cur];	//获取当前节点所连接的节点
		// cur后续有连接的节点
		if(nodes.size())
		{
			//顺序处理这些连接的节点
			for (int i = 0; i < nodes.size(); i++) 
			{
				// cur的指向的文件入度-1
				inDegree[nodes[i]]--;
				// 如果入度减到0, 加入队列
				if(inDegree[nodes[i]] == 0)
					que.push(nodes[i]);
			}
		}	
	}
	
	if( n == result.size())
	{
		for(int i = 0; i < n-1;i++)
			cout << result[i] << " ";
		cout << result[n-1];
	}
	else
		cout << -1 << endl;
	
	return 0;
}
