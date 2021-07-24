#include "Scheduling.h"
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

//打印当前状态所表示的工件加工顺序
void Scheduling::print() {
	puts("--------Sch Info--------");
	for (int i = 1; i <= n; i++) {
		printf("Machine %d :", i);
		for (int j = 1; j <= m; j++) {
			printf(" %d", sch[i][j]);
		}
		printf("\n");
	}
}

void Scheduling::init() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int index;
			scanf("%d", &index);
			scanf("%d", &t[index + 1][i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sch[i][j] = j;
		}
	}
	//随机交换两个数n*m次，以达到随机初始化的效果
	for (int i = 1; i <= n * m; i++) {
		int randmachine = rand() % n + 1;
		int randx = rand() % m + 1,
			randy = rand() % m + 1;
		swap(sch[randmachine][randx], sch[randmachine][randy]);
	}
	puts("--------Init End--------");
}

//随机化下一个状态
Scheduling Scheduling::Next_state() {
	Scheduling next = (*this);
	int randmachine = rand() % n + 1;
	int randx = rand() % m + 1,
		randy = rand() % m + 1;
	swap(next.sch[randmachine][randx], next.sch[randmachine][randy]);
	return next;
}

int Scheduling::pointmap(int i, int j) {
	return (i - 1) * m + j;
}

int Scheduling::Calculate_cost(DAG& dag) {
	//DAG中点的数目为n*m
	dag.init(n * m);
	//同一道工序i中，排在前的工件k向排在后一位的工件连边，边权为t[i][k]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			dag.add(pointmap(i, sch[i][j]), pointmap(i, sch[i][j + 1]), t[i][sch[i][j]]);
		}
	}

	//同一个工件i中，排在前面的工序k向排在后一位的工序连边，边权为[k][i]
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			dag.add(pointmap(j, i), pointmap(j + 1, i), t[j][i]);
		}
	}

	//计算评价函数
	dag.topdp();
	int cost = dag.f[pointmap(n, sch[n][m])] + t[n][sch[n][m]];
	return cost;
}