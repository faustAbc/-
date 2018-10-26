#include <windows.h>
#include <process.h>
#include <stdio.h>

double pi;
int n = 10000000;

int main()
{
	LARGE_INTEGER liFrequency, liStartTime, liFinishTime;	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&liStartTime);

	printf("Pi Consistently\n");

	
	int i, start;
	double h, sum, x;
	h = 1. / n;
	start = 0;
	sum = 0.;

	for (i = start; i < n; i += 1)
	{
		x = h * i;
		sum += 4. / (1. + x * x);
	}

	pi = h * sum;

	QueryPerformanceCounter(&liFinishTime);	double dElapsedTime = 1000.*(liFinishTime.QuadPart - liStartTime.QuadPart) / liFrequency.QuadPart;
	printf("PI = %.16f\n", pi);
	printf("TIME = %.16f ms\n", dElapsedTime);

	return 0;
}

