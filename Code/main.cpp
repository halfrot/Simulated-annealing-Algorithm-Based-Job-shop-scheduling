#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Simulated_Annealing.h"
using namespace std;

int main() {
	double startclk = clock();
	srand(time(NULL));
	Simulated_Annealing sa;
	sa.init();
	sa.Set_Parameter(1000, 0.01, 0.00001);
	//���Զ��epoch�����ҵ����Ž�
	for (int epoch = 1; epoch <= 1; epoch++) sa.SA();
	sa.printAns();
	double endclk = clock();
	//�����������ʱ��
	printf("%lf\n", endclk - startclk);
	return 0;
}