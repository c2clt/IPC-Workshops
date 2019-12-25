//==============================================
// Name:           Jingmin Zhou
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       4 (at - home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MINDAYS 3
#define MAXDAYS 10
#define HIGHTEMP 40
#define LOWTEMP -40

int main(void)
{
	int i, numDays, numDaysAvg, invalid;
	int highTemp[MAXDAYS] = { 0 }; 
	int lowTemp[MAXDAYS] = { 0 };
	int highestTemp = LOWTEMP - 1, lowestTemp = HIGHTEMP + 1;  
	int highIndex, lowIndex;
	float sumTemp, avgTemp;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	scanf("%d", &numDays);

	// Further simplify this (see below)
	//do
	//{
	//	invalid = 0;
	//	if (numDays < MINDAYS || numDays > MAXDAYS)
	//	{
	//		printf("\nInvalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	//		scanf("%d", &numDays);
	//		printf("\n");
	//		invalid = 1;
	//	}
	//} while (invalid == 1);

	while (numDays < MINDAYS || numDays > MAXDAYS)
	{
		printf("\nInvalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
		scanf("%d", &numDays);
		printf("\n");
	}

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

		if (highTemp[i] > highestTemp)
		{
			highestTemp = highTemp[i];
			highIndex = i + 1;
		}
		if (lowTemp[i] < lowestTemp)
		{
			lowestTemp = lowTemp[i];
			lowIndex = i + 1;
		}
	}

	printf("\nDay  Hi  Low\n");
	for (i = 0; i < numDays; i++)
	{
		printf("%-5d%-4d%3d\n", i + 1, highTemp[i], lowTemp[i]);
	}

	printf("\nThe highest temperature was %d, on day %d\n", highestTemp, highIndex);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowIndex);	

//	while (invalid == 0)

	numDaysAvg = 0;
	while (numDaysAvg >=0)
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numDays);
		
		//scanf("%d", &numDaysAvg);

		//do
		//{
		//	if (numDaysAvg < 0)
		//	{
		//		printf("\nGoodbye!\n");
		//		invalid = 1;  // reset the flag value to jump out of the outer loop (while)
		//		
		//		// !!!! OMG !!!! NO NO NO NO NO NO NO NO!! 
		//		// ---------------------------------------
		//		// NEVER DO THIS!!! this violates the single-entry single-exit principle!! 
		//		// the only only thing that should make the for loop stop is the condition 
		//		// in the "while"... any other method is creating hard to read and matintain code!!!!
		//		//break; //BAD BAD BAD BAD      //jump out of the current loop(do-while)
		//	}
		//	else if (numDaysAvg == 0 || numDaysAvg > numDays)
		//	{
		//		printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", numDays);
		//		scanf("%d", &numDaysAvg);
		//		invalid = 1;
		//	}
		//	else
		//		invalid = 0;

		//} while (invalid == 1);

		do
		{
			scanf("%d", &numDaysAvg);
			invalid = (numDaysAvg == 0 || numDaysAvg > numDays);

			if (invalid)
			{
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", numDays);
			}
		} while (invalid == 1);



		//if (numDaysAvg > 0 && numDaysAvg <= numDays)
		//{
		//	sumTemp = 0.0f;

		//	for (i = 0; i < numDaysAvg; i++)
		//	{
		//		sumTemp += (highTemp[i] + lowTemp[i]);
		//	}
		//	avgTemp = sumTemp / (2 * numDaysAvg);
		//	printf("\nThe average temperature up to day %d is: %.2f\n", numDaysAvg, avgTemp);
		//	invalid = 0;
		//}

		if (!invalid && numDaysAvg > 0)
		{
			sumTemp = 0.0f;

			for (i = 0; i < numDaysAvg; i++)
			{
				sumTemp += (highTemp[i] + lowTemp[i]);
			}

			avgTemp = sumTemp / (2 * numDaysAvg);
			printf("\nThe average temperature up to day %d is: %.2f\n", numDaysAvg, avgTemp);
		}

	}

	printf("\nGoodbye!\n");

	return 0;
}
