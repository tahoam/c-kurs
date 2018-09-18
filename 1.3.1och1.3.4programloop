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
	// upg 1.3.1 storlek
	int a;

	printf("size of an int in byte: %d \nsize of an int in bit: %d \n", sizeof(a), (sizeof(a) * 8));

	// upg 1.3.4

	int num = 0;
	int c = 1;
	int b;

	char inp[64];
	char *test;

	while (c == 1)
	{
		printf("\nThe number is currently: %d \n\n", num);
		printf("To add 1 enter: 1\nTo multiply with 2 enter: 2\nTo substract 3 enter: 3\nTo quit program enter: 4\n");
		scanf("%s", inp); // motag input och validera
		test = inp;
		b = atoi(inp);
		if (IsNumber(test) != 1) // IsNumber returnerar 1 vid heltal annars 0
		{
			printf("input not an integrer, try again in 5s...\a\n");
			sleep(5);
			b = 0;
		}
		switch (b) // beroende på input välj alternativ
		{
		case 1:
			num = num + 1;
			break;
		case 2:
			num = num * 2;
			break;
		case 3:
			num = num - 3;
			break;
		case 4:
			printf("exiting program in:\n5s\n");
			sleep(1);
			printf("4s\n");
			sleep(1);
			printf("3s\n");
			sleep(1);
			printf("2s\n");
			sleep(1);
			printf("1s\n");
			c = 0;

			break;
		default:
			;
		}

	}



}
