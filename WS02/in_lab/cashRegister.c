//==============================================
// Name:           Jingmin Zhou
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

int main(void)
{
	double amountOwing, balance;
	int loonies, quarters;	

	printf("Please enter the amount to be paid: $");

	int numOfPara = scanf("%lf", &amountOwing);   //No need to handle the return value of scanf
	assert(numOfPara == 1 && "expect 1 parameter");

	loonies = amountOwing / 1.0;
	balance = amountOwing - loonies;
	printf("Loonies required: %d, balance owing $%.2lf.\n", loonies, balance);

	quarters = balance / 0.25;
	balance = balance - quarters * 0.25;
	printf("Quarters required: %d, balance owing $%.2lf.\n", quarters, balance);

	return 0;
}