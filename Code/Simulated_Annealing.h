#pragma once
#include"Scheduling.h"

class Simulated_Annealing {
public:
	//Temperature��ʼ�¶�
	double Temperature;
	//ZeroT��������
	double ZeroT;
	//Down_Rate���±���
	double Down_Rate;
	//S��¼��ǰ״̬��Ans��bestcost��¼���Ž�
	Scheduling S, Ans;
	int bestcost;

	DAG dag;
	void init();
	void SA();
	void printAns();
	//�ṩ�����¶Ⱥͱ��ʵĽӿ�
	void Set_Parameter(double T, double Z, double D);
};