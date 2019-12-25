//==============================================
// Name:           Jingmin Zhou
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MINDAYS 3
#define MAXDAYS 10
#define HIGHTEMP 40
#define LOWTEMP -40

int main(void)
{
	int i, numDays, invalid;
	int highTemp[MAXDAYS] = { 0 }; 
	int lowTemp[MAXDAYS] = { 0 };

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	scanf("%d", &numDays);

	do
	{
		invalid = 0;
		if (numDays < MINDAYS || numDays > MAXDAYS)
		{
			printf("\nInvalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
			scanf("%d", &numDays);
			printf("\n");
			invalid = 1;
		}
	} while(invalid == 1);

	for (i = 0; i < numDays; i++)
	{
		do
		{
			invalid = 0;	

			printf("Day %d - High: ", i + 1);
			scanf("%d", &highTemp[i]);

			printf("Day %d - Low: ", i + 1);
			scanf("%d", &lowTemp[i]);

			if (highTemp[i] > HIGHTEMP || lowTemp[i] < LOWTEMP || lowTemp[i] > highTemp[i])
			{
				printf("\nIncorrect values, temperatures must be in the range %d to %d, high must be greater than low.\n", LOWTEMP, HIGHTEMP);
				invalid = 1;
			}

		} while (invalid == 1);					
	}

	printf("\nDay  Hi  Low\n");
	for (i = 0; i < numDays; i++)
	{
		printf("%-5d%-4d%3d\n", i + 1, highTemp[i], lowTemp[i]);
	}

	return 0;
}
