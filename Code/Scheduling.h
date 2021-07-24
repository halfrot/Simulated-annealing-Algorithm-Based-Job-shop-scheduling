#pragma once
#include"DAG.h"

static const int  MAXMACHINE = 25, MAXJOB = 55;

class Scheduling {
private:
	//t[i][j]表示第i道工序里，第j个工件需要耗时t[i][j]
	int t[MAXMACHINE][MAXJOB];

	//n表示工序数，m表示工件数
	int n, m;
public:
	//sch[i]表示对第i道工序，所有工件加工顺序的全排列
	int sch[MAXMACHINE][MAXJOB];
	//打印sch数组
	void print();
	//输入t数组，以及初始化sch数组的排列
	void init();
	//产生临近的下一个状态
	Scheduling Next_state();
	//将工件映射到DAG图中点的序号
	int pointmap(int i, int j);
	//计算评价函数，也就是花费的时间
	int Calculate_cost(DAG& dag);
};