#include <stdio.h>

int main()
{
	const char c[] = "gothenburg";
	char *mptr = c;
	int val = 0;
	int counter = 0;

	while (*mptr)
	{
		printf("the word is: %s\n",c );
		char d = *mptr;
		printf(" pointer i currently pointing towards: %c\n input 1 to move left, input 2 to move right\n", d);
		val = 0;
		scanf("%d\n", &val);
		
		
		if ((val == 2) && (counter != 9))
		{
			++counter;
			++mptr;
		}
		else if ((val == 1) && !(counter == 0))
		{
			--mptr;
			--counter;
		}
		
	}


}
