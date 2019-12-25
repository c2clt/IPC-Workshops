//==============================================
// Name:           Jingmin Zhou
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define NUMS 3
int main(void)
{
	//variable section
	int i, highTemp, lowTemp, invalid;

	//get a temperature analyzer
	printf("---===IPC Temperature Analyzer===---");

	for (i = 0; i < NUMS; i++)
	{
		//prompt for temperature values and enforce the range
		do
		{
			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);
			
			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);
			
			if (highTemp > 40 || lowTemp < -41 || lowTemp > highTemp)
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				invalid = 1;
			}
			else
			{
				invalid = 0;
			}
		} while (invalid == 1);		
	}
	
	return 0;
}
