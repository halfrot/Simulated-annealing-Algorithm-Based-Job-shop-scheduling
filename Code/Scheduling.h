#pragma once
#include"DAG.h"

static const int  MAXMACHINE = 25, MAXJOB = 55;

class Scheduling {
private:
	//t[i][j]��ʾ��i���������j��������Ҫ��ʱt[i][j]
	int t[MAXMACHINE][MAXJOB];

	//n��ʾ��������m��ʾ������
	int n, m;
public:
	//sch[i]��ʾ�Ե�i���������й����ӹ�˳���ȫ����
	int sch[MAXMACHINE][MAXJOB];
	//��ӡsch����
	void print();
	//����t���飬�Լ���ʼ��sch���������
	void init();
	//�����ٽ�����һ��״̬
	Scheduling Next_state();
	//������ӳ�䵽DAGͼ�е�����
	int pointmap(int i, int j);
	//�������ۺ�����Ҳ���ǻ��ѵ�ʱ��
	int Calculate_cost(DAG& dag);
};