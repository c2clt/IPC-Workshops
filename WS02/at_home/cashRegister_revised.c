//==============================================
// Name:           Jingmin Zhou
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()

{

	// Vars: Calculated GST and Entered amount by user

	double gst, amt;

	// Vars: current coin denomination count and total remaining as cents

	int coins, remaining;



	// Initialize all variables

	gst = amt = coins = remaining = 0;



	printf("Please enter the amount to be paid: $");

	scanf("%lf", &amt);



	// Calculate and show gst (13%) amount based on entered value

	gst = amt * 0.13;

	// Calculate total by adding gst amount to entered amount

	amt += gst;

	printf("GST %.2lf\n", gst);

	printf("Balance owing: $%.2lf\n", amt);



	// Convert to cents by multiplying by 100 (100 cents in a dollar)

	// (Note: add 0.005 to apply rounding rules before casting from float to int when truncation occurs)

	remaining = (amt + 0.005) * 100;



	// Dollars: divide by 100 cents

	coins = remaining / 100;

	remaining %= 100;   // remainder: use modulus

	printf("Loonies required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);



	// Quarters: divide by 25 cents

	coins = remaining / 25;

	remaining %= 25;    // update remainder: use modulus

	printf("Quarters required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);



	// Dimes: divide by 10 cents

	coins = remaining / 10;

	remaining %= 10;

	printf("Dimes required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);



	// Nickels:  divide by 5 cents

	coins = remaining / 5;

	remaining %= 5;

	printf("Nickels required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);



	// Pennies:  Don't need to do anything... already in pennies

	coins = remaining;

	remaining = 0;      // update remaining to zero

	printf("Pennies required: %d, balance owing $%.2lf\n\n", coins, (double)remaining / 100);



	return 0;

}