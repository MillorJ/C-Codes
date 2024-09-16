#include <stdio.h>

typedef struct {
	char fname[12];
	char Lname[12];
	int age;
}Person;


Person Getdata();
void Display(Person X);

int main()
{
	Person P = Getdata();
	DisplayData(P);
	return 0;
}

Person Getdata()
{
	Person P;
	printf("Enter your name: ");
	scanf("%[^\n]s", &P.fname);
	printf("Enter your last name: ");
	scanf(" %[^\n]s", &P.Lname);
	printf("Enter your age: ");
	scanf("%d", &P.age);
	
	return P;
}
void DisplayData(Person X)
{
	printf("\n");
	printf("Your name is: %s\n", X.fname);
	printf("Your last name is: %s\n", X.Lname);
	printf("Your age is: %d", X.age);
}


