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

//��ʽǰ���Ǽӱ�
void DAG::add(int x, int y, int z) {
	ne[++cnt] = fir[x];
	dgr[y]++;
	to[cnt] = y;
	w[cnt] = z;
	fir[x] = cnt;
}

void DAG::topdp() {
	//�����ҵ��������Ϊ0�ĵ㣬�������
	for (int i = 1; i <= n; i++) {
		if (!dgr[i]) {
			que.push(i);
		}
	}

	//ʹ�����������DAGͼ
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = fir[u]; i != -1; i = ne[i]) {
			int v = to[i];
			//ÿһ����Ҫ�Ժ�̽ڵ��fֵ���и���
			f[v] = max(f[v], f[u] + w[i]);
			dgr[v]--;
			//��ȥ���ոձ����ıߺ����Ϊ0�������
			if (!dgr[v]) que.push(v);
		}
	}
}
