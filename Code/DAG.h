#pragma once
#include<queue>
using namespace std;

//MAX是DAG中点数的最大值
static const int MAX = 1010;

class DAG {
public:
	//n表示点的数目
	int n;
	//dgr表示点的入度
	int dgr[MAX];
	//采用链式前向星来表达一张图，fir是头节点，ne指向下一条边，to是有向边指向的点，cnt表示边的数目
	int fir[MAX], ne[MAX], to[MAX], cnt;
	//w表示边的权值
	int w[MAX];
	//f表示每个点最早可以开始加工的时间
	int f[MAX];
	queue <int> que;
	//在拓扑序上进行动态规划求评价函数
	void topdp();
	//向图中增加一条有向边
	void add(int x, int y, int z);
	//初始化数组
	void init(int _n);
};