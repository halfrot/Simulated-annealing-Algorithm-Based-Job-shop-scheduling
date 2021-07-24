#include "Simulated_Annealing.h"
#include"Scheduling.h"
#include<climits>
#include<algorithm>
using namespace std;

//��ʼ��Scheduling��
void Simulated_Annealing::init() {
	S.init();
}

void Simulated_Annealing::printAns() {
	Ans.print();
	printf("cost : %d\n", bestcost);
}

void Simulated_Annealing::Set_Parameter(double T, double Z, double D) {
	Temperature = T;
	ZeroT = Z;
	Down_Rate = D;
	bestcost = INT_MAX;
}

void Simulated_Annealing::SA() {
	double T = Temperature, Z = ZeroT, D = Down_Rate;
	//��ȡ�����ʼ���ɵ����ۺ���ֵ
	int val = S.Calculate_cost(dag);

	//Count��Ϊ����м����ĸ�������
	int Count = 0;
	while (T > Z) {
		Count++;
		if (Count == 10000) {
			//ÿ���10000�����1�ε�ǰ״̬
			printf("%lf %d\n", T, val);
			Count = 0;
		}
		Scheduling next = S.Next_state();
		int newval = next.Calculate_cost(dag);

		//����״̬�����ۺ�����ֵ
		int delta_val = newval - val;
		//����״̬���ţ������
		if (delta_val < 0) {
			S = next;
			val = newval;
			if (bestcost > val) {
				bestcost = val;
				Ans = S;
			}
		}//�����Ը��ʽ���
		else if (rand() < exp(-delta_val / T) * RAND_MAX) {
			S = next;
			val = newval;
		}
		//һ����ɣ��¶��½�
		T *= 1.0 - D;
	}
}