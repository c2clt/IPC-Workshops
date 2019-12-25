//==============================================
// Name:           Jingmin Zhou
// Student Number: 119766194
// Email:          jzhou175@myseneca.ca
// Section:        NNN
// Workshop:       5 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4		

struct Employee
{
	int id;
	int age;
	double salary;
};

int main(void)
{
	int option = 0, count = 0;
	int i = 0;
	int idCheck, idAdd, invalid = 0;
	double newSalary;
	int index;

	struct Employee emp[SIZE] = { { 0 } };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
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
						printf("\nInvalid Entry. Please enter the valid employee ID!!!\n\n");
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

		case 3: 
			if (count > 0 && count <= SIZE)
			{
				printf("Update Employee Salary\n");
				printf("======================\n");

				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &idCheck);

					invalid = 1;
					for (i = 0; i < SIZE; i++)
					{
						if (idCheck > 0 && idCheck == emp[i].id)
						{
							index = i;
							invalid = 0;
						}
					}

					if (invalid)
					{
						printf("*** ERROR: Employee ID not found! ***\n");
					}

				} while (invalid);

				printf("The current salary is %.2lf\n", emp[index].salary);
				printf("Enter Employee New Salary: ");
				scanf("%lf", &newSalary);
				emp[index].salary = newSalary;
				printf("\n");
			}
			break;

		case 4:
			if (count > 0 && count <= SIZE)
			{
				printf("Remove Employee\n");
				printf("===============\n");

				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &idCheck);

					invalid = 1;
					for (i = 0; i < SIZE; i++)
					{
						if (idCheck > 0 && idCheck == emp[i].id)
						{
							index = i;
							invalid = 0;
						}
					}

					if (invalid)
					{
						printf("*** ERROR: Employee ID not found! ***\n");
					}

				} while (invalid);

				printf("Employee %d will be removed\n\n", emp[index].id);
				emp[index].id = 0;
				count--;
			}
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}
