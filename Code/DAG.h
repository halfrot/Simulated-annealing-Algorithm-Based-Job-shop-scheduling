#pragma once
#include<queue>
using namespace std;

//MAX��DAG�е��������ֵ
static const int MAX = 1010;

class DAG {
public:
	//n��ʾ�����Ŀ
	int n;
	//dgr��ʾ������
	int dgr[MAX];
	//������ʽǰ���������һ��ͼ��fir��ͷ�ڵ㣬neָ����һ���ߣ�to�������ָ��ĵ㣬cnt��ʾ�ߵ���Ŀ
	int fir[MAX], ne[MAX], to[MAX], cnt;
	//w��ʾ�ߵ�Ȩֵ
	int w[MAX];
	//f��ʾÿ����������Կ�ʼ�ӹ���ʱ��
	int f[MAX];
	queue <int> que;
	//���������Ͻ��ж�̬�滮�����ۺ���
	void topdp();
	//��ͼ������һ�������
	void add(int x, int y, int z);
	//��ʼ������
	void init(int _n);
};