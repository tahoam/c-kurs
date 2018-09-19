#include <stdio.h>
#include <time.h>

void sleep(int a)
{
	time_t t1, t2;
	t1 = time(NULL);
	t2 = time(NULL);

	while ((t2 - t1) < a)
		t2 = time(NULL);
}

void doubble(int x) // variable x is not stored in memory when void is called or void returns nothing
{
	x = 2 * x;
	//printf("%d", x);  // lägg till för att få utskrift
}

int doubble1(int x)
{
	x = 2 * x;
	return x;
}

int main()
{
	int i;
	int x;
	printf("enter int to be doubled\n");
	scanf("%d", &i);

	printf("\n%d\n", doubble1(i));
	sleep(10);


}
