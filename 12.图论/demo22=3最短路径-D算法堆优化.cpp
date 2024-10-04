#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <queue>

using  namespace std;

//邻接表的定义 
// 定义一个结构体来表示带权重的边
struct Edge {
	int to; 	 	// 链接的节点
	int val; 		// 边的权重
	
	Edge(int t, int w):to(t),val(w){}	// 构造函数
};

//自定义比较器类   小顶堆 
class Mycomparison{
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
		// 这里是根据第二个整数排序  
		return lhs.second > rhs.second;		// 较小的 second 应该有较高的优先级  
	}
};

// 优先队列中存放 pair<节点编号，源点到该节点的权值> 
priority_queue<pair<int, int>, vector<pair<int, int>>,Mycomparison> que;

//说明：
//priority_queue: 这是一个用于存储优先级元素的数据结构，通常是最大堆或最小堆
//默认情况下，priority_queue 是一个最大堆，即队列中最大的元素具有最高优先级
//pair<int, int>: 这指定了优先队列中存储的元素类型为 pair<int, int>，即一对整数
//vector<pair<int, int>>: 这表示优先队列将使用一个 vector 作为底层容器来存储元素。
//mycomparison: 这是一个自定义的比较器，用于定义优先队列中元素的优先级。

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<list<Edge>> grid(n+1);
	int p1,p2,val;
	while(m--)
	{
		cin >> p1 >> p2 >> val;
		grid[p1].push_back(Edge(p2,val));
	}
	
	int start = 1;		// 起点
	int end = n;		// 终点
	
	// 存储从源点到每个节点的最短距离
	vector<int> minDist(n+1, INT_MAX);	
	minDist[start] = 0;				// 起始点到自身的距离为0
	
	// 记录每个节点的遍历情况
	vector<bool> visited(n+1,false);		
	
	// 优先队列中存放 pair<节点编号，源点到该节点的权值> 
	priority_queue<pair<int, int>, vector<pair<int, int>>,Mycomparison> que;
	// 初始化队列，源点到源点的距离为0，所以初始为0
	que.push(pair<int, int>(start, 0));
	
	// 遍历所有节点，第一层for循环 
	while(!que.empty()){
		/// 1. 第一步，选源点到哪个节点近且该节点未被访问过 （通过优先级队列来实现）
		// <节点， 源点到该节点的距离>
		pair<int, int> cur = que.top(); 
			que.pop();
		
		// 第二步（该最近节点被标记访问过） 
		//这个就是将 节点做访问标记，和 基础D算法 一样
		visited[cur.first] = true;  
		
		// 第三步，更新非访问节点到源点的距离（即更新minDist数组）
		// 遍历 cur指向的节点，cur指向的节点为 edge
		for(Edge edge : grid[cur.first]){		
			// cur指向的节点edge.to，这条边的权值为 edge.val
			if(!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]){
				minDist[edge.to] = minDist[cur.first] + edge.val;		//更新下个节点的minDist
				que.push(pair<int, int>(edge.to, minDist[edge.to]));	// 下个节点加入优先级队列
			}
		}
	}	

	
	if (minDist[end] == INT_MAX) 
		cout << -1 << endl; 			// 不能到达终点
	else 
		cout << minDist[end] << endl; 	// 到达终点最短路径
}	

