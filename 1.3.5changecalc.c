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


int main()
{
	double totalSum, kontantBet, vxl, ore;
	
	int change;
	int value[8] = { 1000,500,100,50,20,10,5,1 };
	int n[8] = { 0,0,0,0,0,0,0,0 };
	int c = 0;
	
	printf("Skriv in hur mycket kunden ska betala?\n");
	scanf("%lf", &totalSum);
	printf("Hur mycket betalar kunden? \n");
	scanf("%lf", &kontantBet);

	vxl = kontantBet - totalSum;
	vxl = round(vxl * 2) / 2; // gör om vxl till jämn multipel utav 0.5
	printf("Kunden ska få tillbaka %3.2lf kr.\n", vxl);
	ore = 2 * (vxl - (int)vxl);

	printf("change:\n");
	
	change = vxl;


	for (int i = 0; i <= 7; ++i) // beräknar antalet pengar av valörer 1000-1
	{
		while ((change - value[i]) >= 0 && (change >= value[i]))
		{
			change = change - value[i];
			c++;
		}
		n[i] = c;
		printf("	%d-%d \n", n[i], value[i]);
		c = 0;
	}

	printf("	%1.0f-0.50", ore); // skriver ut tidigare beräknade ören

	sleep(10);
}
