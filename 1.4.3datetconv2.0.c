#include <stdio.h>
#include <math.h>
#include <time.h>

void sleep(int a)
{
	time_t t1, t2;
	t1 = time(NULL);
	t2 = time(NULL);

	while ((t2 - t1) < a)
		t2 = time(NULL);
}


int main() // inmatningsmetod av data på rätt format yyyy,mm,dd,hh,mmm,ss behövs ännu
{
	int date1[6] = { 2000,4,2,16,40,12 }; // startår
	int date2[6] = { 2002,2,1,14,20,10}; // slutår

	int monthdays[12] = { 31, 28, 31, 30, 31, 30,31,31,30,31,30,31 };


	int times[3] = { 0,0,0 }; // räknade sec minuter timmar
	int tfinal[3] = { date1[5],date1[4],date1[3] };
	int tlimits[3] = { 24,60,60 }; // datagränser

	int days = 0; // dagar från element 3

	int mdays = 0; // dagar från element 2
	int startm = date1[1];
	
	int y = 0; //skillnad i år
	int ydays = 0; // skillnad i år omräknat till dagar

	long int tottime;
	
	for (int i = 2; i >= 0; i--) // beräknar antal sekunder, minuter och timmar, görs förenklingen att varje månad är 30 dagar skulle allt kunna räknas av loopen...
	{
		while (date1[i + 3] != date2[i + 3])
		{
			date1[i + 3]++;
			times[i]++;
			if (date1[i + 3] == tlimits[i])
				{
					date1[i + 3] = 0;
					date1[i + 2]++;
				}
		}
		
	}
	printf("sec: %d\nmin: %d\nhours: %d\n", times[2], times[1], times[0]);

	if (date1[2] > date2[2]) // om månadsgräns korsas för att nå datum
	{
		days = (monthdays[(date1[1] - 1)]-date1[2])+date2[2]; // dagar kvar av start månad  + dagar in i dest
		printf("days: %d\n", days);
		date1[1] = date1[1] + 1;  //övergång till nästa månad efter räknade dagar
	}
	else 
	{
		days = date2[2] - date1[2];
		printf("days: %d\n", days);
	}




		while (startm != date2[1]) 
		{
			mdays = mdays + monthdays[(startm - 1)];
			startm = startm + 1;
			if (startm == 13) // om årsgräns korsas börja om på mån 1 och öka startår 1
			{
				startm = 1;
				date1[0] = date1[0] + 1;
			}
		}
		
	
		printf("days contribution from months %d\n", mdays);

		y = date2[0] - date1[0]; //beräknar dagar från årskillnad, kan ej placeras tidigare pga ökning av startår via månader
		ydays = y * 365;  //konvertering till dagar

		printf("days contribution from years: %d\n", ydays);

		tottime = times[0] + times[1] * 60 + times[2] * 60 * 60 + (days + mdays + ydays) * 24 * 60 * 60;

		printf("secounds between dates: %d\n", tottime);

		sleep(100);
}
