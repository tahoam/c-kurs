// Header.h
#pragma once // ignorerar dubletter utav inkluderade bibliotek

int convert(int a)
{
	return (a * 1000);
}


// source.c
#include <stdio.h>

int main()
{
	int m=0;
	printf("enter distance in m:\n");
	scanf("%d", &m);
	int c;
	c = convert(m);

	printf("%dm is equal to: %dmm",m, c);

	sleep(10);
}

// #include <> vs "": <> search for file in compiler prespecified location.
// "" search same directory as file cointaining the 
