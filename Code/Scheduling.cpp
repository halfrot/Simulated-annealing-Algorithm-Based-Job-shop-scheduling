#include "Scheduling.h"
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

//��ӡ��ǰ״̬����ʾ�Ĺ����ӹ�˳��
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
	//�������������n*m�Σ��Դﵽ�����ʼ����Ч��
	for (int i = 1; i <= n * m; i++) {
		int randmachine = rand() % n + 1;
		int randx = rand() % m + 1,
			randy = rand() % m + 1;
		swap(sch[randmachine][randx], sch[randmachine][randy]);
	}
	puts("--------Init End--------");
}

//�������һ��״̬
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
	//DAG�е����ĿΪn*m
	dag.init(n * m);
	//ͬһ������i�У�����ǰ�Ĺ���k�����ں�һλ�Ĺ������ߣ���ȨΪt[i][k]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			dag.add(pointmap(i, sch[i][j]), pointmap(i, sch[i][j + 1]), t[i][sch[i][j]]);
		}
	}

	//ͬһ������i�У�����ǰ��Ĺ���k�����ں�һλ�Ĺ������ߣ���ȨΪ[k][i]
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			dag.add(pointmap(j, i), pointmap(j + 1, i), t[j][i]);
		}
	}

	//�������ۺ���
	dag.topdp();
	int cost = dag.f[pointmap(n, sch[n][m])] + t[n][sch[n][m]];
	return cost;
}