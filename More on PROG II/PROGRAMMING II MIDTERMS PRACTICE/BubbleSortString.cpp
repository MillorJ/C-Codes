#include <stdio.h>
#include <string.h>

void BubbleSort(char str[], int size);

int main()
{
	int i;
	char str[] = {"SAMPLE"};
	int size = strlen(str);
	
	BubbleSort(str, size);
	printf("The sorted string is %s", str);
	
}

void BubbleSort(char str[], int size)
{
	int i,j;
	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-1-i; j++)
		{
			if(str[j] > str[j+1])
			{
				char temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
}
}
