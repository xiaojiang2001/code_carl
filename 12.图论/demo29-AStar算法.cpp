#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int moves[1001][1001];		// 到下个节点的最短步数
int b1,b2;					// 下一个节点坐标
// 题意的8个方向
int dir[8][2]={-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2};
// F = G + H
// G = 从起点到该节点路径消耗
// H = 该节点到终点的预估消耗

struct Node{
	int x,y;		//起始点
	int g,h,f;		//A*距离
	// 重载运算符， 从小到大排序    处理最小值
	bool operator < (const Node& other) const
	{
		return other.f < f;		// 较小的节点权值f应该有较高的优先级  
	}
};

priority_queue<Node> que;		// 优先级队列

//当前节点到终点的欧拉距离
// 统一不开根号，这样可以提高精度
int Heuristic(const Node& node)
{
	return (node.x - b1) * (node.x - b1) + (node.y - b2) *  (node.y - b2) ;
}

// A*算法入口
void astar(const Node& node)
{
	Node cur, next;				//当前节点 下个节点
	que.push(node);
	while(!que.empty())
	{
		// 获取优先级队列中距离最近的节点
		cur = que.top();
		que.pop();
		// 到达终点
		if(cur.x == b1 && cur.y == b2)
			break;
		// 遍历不同的方向
		for(int i = 0; i < 8; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			// 越界
			if(next.x < 1 || next.y < 1 || next.x > 1000 || next.y > 1000)
				continue;
			if(!moves[next.x][next.y])
			{
				moves[next.x][next.y] = moves[cur.x][cur.y] + 1;	// 步数 + 1
				//开始计算F
				next.g = cur.g + 5;			// 统一不开根号，可以提高精度，马走日，1 * 1 + 2 * 2 = 5
				next.h = Heuristic(next);	// 计算下个点到终点的启发式函数距离
				next.f = next.g  + next.h;	// 计算下个节点的 f
				que.push(next);				// 下个节点加入优先级队列
			}	
		}
	}
}

int main()
{
	int n,a1,a2;
	cin >> n;
	while(n--)
	{
		cin >> a1 >> a2 >> b1 >> b2;
		memset(moves, 0, sizeof(moves));
		Node start;
		start.x = a1;
		start.y = a2;
		start.g = 0;
		start.h = Heuristic(start);
		start.f = start.g + start.h;
		astar(start);
		//清空队列
		while(!que.empty())
			que.pop();
		cout << moves[b1][b2] << endl;
	}
	return 0;
}


