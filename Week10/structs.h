#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char name[20];
	int hours;
	int sessions;
	float average;
}participants;


int comp(const void*a, const void*b );

