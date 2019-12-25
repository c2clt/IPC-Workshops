//==============================================
// Name:           Jingmin Zhou
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define NUMS 4
int main(void)
{
	//variable section
	int i, highTemp, lowTemp, invalid;
	float sumHighTemp = 0.0f, sumLowTemp = 0.0f;
	float avgHighTemp, avgLowTemp;
	int highestTemp = -41, lowestTemp = 41;
	int highIndex, lowIndex;

	//get a temperature analyzer
	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; i++)
	{
		//prompt for temperature values and enforce the range
		do
		{
            invalid = 0;

			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);

			if (highTemp > 40 || lowTemp < -40 || lowTemp > highTemp)
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				invalid = 1;
			}
			else
			{
				sumHighTemp += highTemp;
				sumLowTemp += lowTemp;

				//find the highest temperature on which day
				if (highTemp > highestTemp)
				{
					highestTemp = highTemp;
					highIndex = i + 1;
				}
				//find the lowest temperature on which day
				if (lowTemp < lowestTemp)
				{
					lowestTemp = lowTemp;
					lowIndex = i + 1;
				}
			}
		} while (invalid == 1);
	}

	//display summary
	avgLowTemp = sumLowTemp / NUMS;
	printf("\nThe average (mean) LOW temperature was: %.2f\n", avgLowTemp);
	avgHighTemp = sumHighTemp / NUMS;
	printf("The average (mean) HIGH temperature was: %.2f\n", avgHighTemp);

	printf("The average (mean) temperature was: %.2f\n", (avgLowTemp + avgHighTemp) / 2.0f);

	printf("The highest temperature was %d, on day %d\n", highestTemp, highIndex);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowIndex);

	return 0;
}
