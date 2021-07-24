#include "Simulated_Annealing.h"
#include"Scheduling.h"
#include<climits>
#include<algorithm>
using namespace std;

//初始化Scheduling类
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
	//获取随机初始生成的评价函数值
	int val = S.Calculate_cost(dag);

	//Count作为输出中间结果的辅助变量
	int Count = 0;
	while (T > Z) {
		Count++;
		if (Count == 10000) {
			//每随机10000次输出1次当前状态
			printf("%lf %d\n", T, val);
			Count = 0;
		}
		Scheduling next = S.Next_state();
		int newval = next.Calculate_cost(dag);

		//两个状态的评价函数差值
		int delta_val = newval - val;
		//若新状态更优，则接受
		if (delta_val < 0) {
			S = next;
			val = newval;
			if (bestcost > val) {
				bestcost = val;
				Ans = S;
			}
		}//否则以概率接受
		else if (rand() < exp(-delta_val / T) * RAND_MAX) {
			S = next;
			val = newval;
		}
		//一轮完成，温度下降
		T *= 1.0 - D;
	}
}