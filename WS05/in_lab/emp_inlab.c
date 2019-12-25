//==============================================
// Name:           Jingmin Zhou (Jessica)
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 2		

struct Employee
{
	int id;
	int age;
	double salary;
};

int main(void) 
{
	int option = 0, i; 
	int count = 0, invalid, idAdd;
	int index;
	
	struct Employee emp[SIZE] = { { 0 } };    
    
	printf("---=== EMPLOYEE DATA ===---\n\n");

	do 
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		scanf("%d", &option);
		printf("\n");
		
		switch (option) 
		{
		case 0:	
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: 
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id > 0)
					printf("%6d%9d%11.2f\n", emp[i].id, emp[i].age, emp[i].salary);
			}
			printf("\n");
			break;

		case 2:
			printf("Adding Employee\n");
			printf("===============\n");

			if (count >= 0 && count < SIZE)
			{
				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &idAdd);

					invalid = 0;

					for (i = 0; i < SIZE; i++)
					{
						if (idAdd <= 0 || idAdd == emp[i].id)
							invalid = 1;
					}

					if (invalid)
					{
						printf("\nInvalid Entry. Please enter a valid employee ID!!!\n\n");
					}

				} while (invalid);

				for (i = count; i >= 0; i--)
				{
					if (emp[i].id == 0)
					{
						emp[i].id = idAdd;
						index = i;
					}
				}

				printf("Enter Employee Age: ");
				scanf("%d", &emp[index].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[index].salary);
				printf("\n");
				count++;
			}
			else
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0; 
}