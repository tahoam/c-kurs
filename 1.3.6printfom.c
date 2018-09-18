#include <stdio.h>
#include <time.h>
#include <math.h>

void sleep(int a)
{
	time_t t1, t2;
	t1 = time(NULL);
	t2 = time(NULL);

	while ((t2 - t1) < a)
		t2 = time(NULL);
}


int main()
{
	double fx;
	double i;

	printf("y=4x^3+3sin(x)^2-5x*5 x=[-15,15,1]\n");
		for (int x = -15; x <= 15; x++) 
		{
			fx = 4 * (pow(x,3)) + 3 * pow(sin(x), 2) - 5*x - 7;
			printf("x = %02.0d	y = %05.3f\n", x, fx);
		}

		printf("\n\n\n\n\n");
		printf("y=4x^3+3sin(x)^2-5x*5 x=[-1,1,0.1]\n");

		i = -1;
		while (i <= 1)
		{
			fx = 4 * (pow(i, 3)) + 3 * pow(sin(i), 2) - 5 * i - 7;
			printf("x = %2.1f y = %05.3f\n", i, fx);
			i = i + 0.1;
		}

		sleep(100);
}
