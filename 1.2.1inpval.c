#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	char input[64];

	printf("Input integrer to be multiplied with 2:\n");
	scanf("%s", input); // skapar \0 terminerad sträng
	printf("\n You have entered: %s\n", input);

	char *test = input; // pekare till input, oklart varför men verkar hjälpa
	
	if (IsNumber(test) != 1) // IsNumber returnerar 1 vid heltal annars 0
	{
		printf("input not an integrer, closing program...\a");
		sleep(5);
		return 0;
	}
	
	int number;
	int product;
	int length;
	number = atoi(input);
	product = number * 2;
	
	if ( number >> 0)
		length = floor(log10(abs(number)));

	if (number << 0)
	length =  floor(log10(abs(number))) + 2; // för att ta hänsyn till minus tecken

	if (number == 0)
		length = 1;
	

	printf("%d multiplied with 2= %d \n Length of product is: %d numbers \n", number, product, length);


	sleep(10);

}
