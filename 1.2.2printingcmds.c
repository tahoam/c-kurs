#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sleep(int a)
{
	time_t t1, t2;
	t1 = time(NULL);
	t2 = time(NULL);

	while ((t2 - t1) < a)
		t2 = time(NULL);
}

int IsNumber(const char * pStr)
{
	if (NULL == pStr || *pStr == '\0')
		return 0;

	int dot;
	int minus;
	int plus;
	dot = 0;
	minus = 0;
	plus = 0;

	while (*pStr)
	{
		char c = *pStr;
		switch (c)
		{
		case '.': // tillåter enbart heltal, >1 för decimal
			if (++dot > 0)
				return 0;
			break;
		case '-':
			if (++minus > 1)
				return 0;
			break;
		case '+':
			if (++plus > 1)
				return 0;
			break;
		default:	// filtrerar bort övriga otillåtna tecken
			if (c < '0' || c > '9')
				return 0;
			break;
		}
		pStr++;
	}
	return 1;
}

int main()
{	
	int P, Q;
	char input1[64];
	char input2[64];

	printf("Input int P: \n");

	scanf("%s", input1); //
	char *test = input1;
	if (IsNumber(test) != 1) // IsNumber returnerar 1 vid heltal annars 0
	{
		printf("input not an integrer, closing program...\a");
		sleep(5);
		return 0;
	}
	P = atoi(input1);

	printf("Input int Q: \n");
	scanf("%s", input2); //
	test = input2;
	if (IsNumber(test) != 1) // IsNumber returnerar 1 vid heltal annars 0
	{
		printf("input not an integrer, closing program...\a");
		sleep(5);
		return 0;
	}
	Q = atoi(input2);

	printf("int Q: %d in hexadecimal: %#x \n" ,P, P);

	float Q2 = Q;
	float P2 = P;
	

	printf(" int P/Q (%d/%d) as a float: %.3f \n",P,Q,(P2/Q2));

	printf("P/Q as an int: %d leftover: %d \n", (P / Q), P%Q); // modulus operator

	printf("P*Q as sci: %e \n", (Q2*P2));

	printf("Q with zero padding: %07d \n", Q);

	sleep(10);
}
