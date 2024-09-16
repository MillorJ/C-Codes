#include <stdio.h>


typedef struct {
	char fname[12];
	char MI;
	char Lname[12];
	int age;
}Student;


Student getdata();
void display(Student P);

int main()
{
	Student A = getdata();
	display(A);
	
	return 0;
}

Student getdata()
{
	Student X;
	printf("Enter your first name: ");
	scanf("%[^\n]s", &X.fname);
	printf("Enter your middle initial: ");
	scanf(" %c", &X.MI);
	printf("Enter your Last name: ");
	scanf(" %[^\n]s", &X.Lname);
	printf("Enter your age: ");
	scanf(" %d", &X.age);
	
	return X;
}
void display(Student P)
{
	printf("\n\n\n");
	printf("Your first name is %s\n", P.fname);
	printf("Your middle inital is %c\n", P.MI);
	printf("Your last name is %s\n", P.Lname);
	printf("Your age is %d\n",P.age);

	
}
