#pragma once
#include"Scheduling.h"

class Simulated_Annealing {
public:
	//Temperature初始温度
	double Temperature;
	//ZeroT结束零温
	double ZeroT;
	//Down_Rate降温比率
	double Down_Rate;
	//S记录当前状态，Ans和bestcost记录最优解
	Scheduling S, Ans;
	int bestcost;

	DAG dag;
	void init();
	void SA();
	void printAns();
	//提供设置温度和比率的接口
	void Set_Parameter(double T, double Z, double D);
};