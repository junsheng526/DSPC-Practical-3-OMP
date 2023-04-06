#include <iostream>
#include <stdio.h>
#include "omp.h"

using namespace std;

static long num_steps = 10000;
double step;

void quick_test() {
#pragma omp parallel
	{
		int id = omp_get_thread_num();
		if (id == 0)
		{
			printf("The total threads is %d\n", omp_get_num_threads());
		}
		printf("Hello world (%d)\n", omp_get_thread_num());
	}
}

void example() {
	float val = 123.456;

	cout << "starting..." << endl;
	omp_set_num_threads(8);

#pragma omp parallel
	{
		int id = omp_get_thread_num();
		//cout << "Hello world" << endl;
		printf("Hello world! (%d)\n", id);
	}

	cout << "ending..." << endl;
}

void testing() {
	omp_set_num_threads(16);

#pragma omp parallel
	{
		int id = omp_get_thread_num();
		if (id == 1) {
			int num = omp_get_num_threads();
			printf("Total Threads: %i\n", num);
		}

	}

}

void q1() {
#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		printf("hello(%d)", ID);
		printf("world(%d)\n", ID);

	}
}

void q2() {
	long num_steps = 100000;
	int i; double x, pi, sum = 0.0;
	double step = 1.0 / num_steps;
	double time, period;

	time = omp_get_wtime();
	for (i = 0; i < num_steps; i++) {
		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}

	pi = step * sum;
	period = omp_get_wtime() - time;
	printf("The calculated pi value is %.12f (in %d steps) in %f secs\n",
		pi, num_steps, period);
}

void q2a() {
	int i;
	double x, pi, sum = 0.0;
	step = 1.0 / (double)num_steps;
	double time, period;

	time = omp_get_wtime();

#pragma omp parallel for
	for (i = 0; i < num_steps; i++) {
		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}

	pi = step * sum;
	period = omp_get_wtime() - time;
	printf("The calculated pi value is %f (in %ld steps) in %f secs\n", pi, num_steps, period);
}

void q2c() {

	long num_steps = 100000;
	double pi, sum = 0.0;
	double step = 1.0 / num_steps;
	double time, period;

	time = omp_get_wtime();
#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < num_steps; i++) {
		double x = (i + 0.5) * step;
		sum += 4.0 / (1.0 + x * x);
	}

	pi = step * sum;
	period = omp_get_wtime() - time;
	printf("The calculated pi value is %.12f (in %ld steps) in %f secs\n", pi, num_steps, period);
}


int main() {

	example();
	q1();
	q2();
	q2a();
	testing();
	quick_test();
	q2a();
	q2a();
	q2a();
	q2a();
	q2a();
	q2a();
	q2a();
	q2();
	q2();
	q2();
	q2();
	q2();
	q2();
	q2();
	q2();
	q2c();
	q2c();
	q2c();
	q2c();
	q2c();
	q2c();



	return 0;
}