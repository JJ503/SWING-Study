#include <stdio.h>
#include <time.h>

int main()
{
	char test1[25];
	char test2[25];
	char user1[5][5];
	char user2[5][5];
	int t = 0;
	int i, j;
	int a, b;

	srand(time(NULL));

	for (i = 0; i < 25; i++)
	{
		test1[i] = rand() % 25 + 65;

		for (j = 0; j < i; j++)
		{
			if (test1[i] == test1[j])
			{
				i--;
				break;
			}
		}
	}

	for (i = 0; i < 25; i++)
	{
		test2[i] = rand() % 25 + 65;

		for (j = 0; j < i; j++)
		{
			if (test2[i] == test2[j])
			{
				i--;
				break;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{

			user1[i][j] = test1[j + t];
			user2[i][j] = test2[j + t];
		}

		t = t + 5;
	}
	
	printf("        [User 1]                [User 2]\n");

	for (i = 0; i < 5; i++)
	{
		printf("   ");

		for (j = 0; j < 5; j++)
		{
			printf("%c   ", user1[i][j]);
		}
		
		printf(":   ");

		for (j = 0; j < 5; j++)
		{
			printf("%c   ", user2[i][j]);
		}

		printf("\n");
	}
}