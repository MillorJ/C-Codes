#include <stdio.h>


typedef struct person{
	char fname[12];
	char MI;
	char LN[12];
	int age;
}Person;

Person getdata();
void display(Person X);

int main()
{

Person S = getdata();
display(S);
return 0;

}

Person getdata()
{
	Person A;
	printf("Enter your first name: ");
	scanf("%[^\n]s", &A.fname);
	printf("Enter your MI: ");
	scanf(" %c", &A.MI);
	printf("Enter your last name: ");
	scanf(" %[^\n]s", &A.LN);
	printf("Enter your age: ");
	scanf(" %d", &A.age);
	
	return A;
}

void display(Person X)
{
	printf("\n\n");
	printf("Your first name is %s\n", X.fname);
	printf("Your Middle Initial is %c\n", X.MI);
	printf("Your last name is %s\n", X.LN);
	printf("Your age is %d\n", X.age);
	
}
