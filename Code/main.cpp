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
	//尝试多个epoch可能找到更优解
	for (int epoch = 1; epoch <= 1; epoch++) sa.SA();
	sa.printAns();
	double endclk = clock();
	//输出测试所用时间
	printf("%lf\n", endclk - startclk);
	return 0;
}