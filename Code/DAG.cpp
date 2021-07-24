#include "DAG.h"
#include<cstring>
#include<algorithm>
using namespace std;

void DAG::init(int _n) {
	memset(fir, -1, sizeof(fir));
	memset(f, 0, sizeof(f));
	cnt = 0;
	n = _n;
}

//链式前向星加边
void DAG::add(int x, int y, int z) {
	ne[++cnt] = fir[x];
	dgr[y]++;
	to[cnt] = y;
	w[cnt] = z;
	fir[x] = cnt;
}

void DAG::topdp() {
	//首先找到所有入度为0的点，加入队列
	for (int i = 1; i <= n; i++) {
		if (!dgr[i]) {
			que.push(i);
		}
	}

	//使用拓扑序遍历DAG图
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = fir[u]; i != -1; i = ne[i]) {
			int v = to[i];
			//每一个点要对后继节点的f值进行更新
			f[v] = max(f[v], f[u] + w[i]);
			dgr[v]--;
			//若去掉刚刚遍历的边后，入度为0，则入队
			if (!dgr[v]) que.push(v);
		}
	}
}
