#include<stdio.h>
#include<stdlib.h>
int IsSpecialCharacter(char ch)
{
	if (ch >= 'a' && ch <= 'z') return 0;
	if (ch >= 'A' && ch <= 'Z') return 0;
	if (ch >= '0' && ch <= '9') return 0;
	if (ch == '"') return 0;
	return 1;
}
int main()
{
	FILE *ptr;
	ptr = fopen("in.txt", "r");
	char arr[100001];
	while (fgets(arr, 100001, ptr))
	{
		for (int i = 0; arr[i + 1] != '\0'; i++)
		{
			if (IsSpecialCharacter(arr[i]) == 0)
			{
				// not special character
				printf("%c", arr[i]);
			}
			else
			{
				if (arr[i] == '(')
				{
					//to print the string enclosed in bracket
					printf("\n");
					while (arr[i] != ')')
					{
						printf("%c", arr[i]);
						i++;
					}
					printf("%c\n", arr[i]);
					continue;
				}
				printf("\n%c\n", arr[i]);
			}
		}
	}
}

