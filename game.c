#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int targetNumber[4], guessNumber[4];

int generateNumber()
{
	int i=0;
	
	srand(time(NULL));

	// GENERATE FIRST DIGIT (1-9)
	targetNumber[0] = 1+rand()%9;
	

	// GENERATE SECOND DIGIT (0-9)
	targetNumber[1] = rand()%10;
	while(targetNumber[1] == targetNumber[0])
	{
		targetNumber[1] = rand()%10;
	}
	
	
	// GENERATE THIRD DIGIT (0-9)
	targetNumber[2] = rand()%10;
	while(targetNumber[2] == targetNumber[0] || targetNumber[2] == targetNumber[1])
	{
		targetNumber[2] = rand()%10;
	}
	

	// GENERATE LAST DIGIT (0-9)
	targetNumber[3] = rand()%10;
	while(targetNumber[3] == targetNumber[0] || targetNumber[3] == targetNumber[1] || targetNumber[3] == targetNumber[2])
	{
		targetNumber[3] = rand()%10;
	}
	
}
int printNumber(int a[4])
{
	int i;

	for(i=0; i<4; i++)
	{
		printf("%d", a[i]);
	}
}

int guess()
{
	int i, temp;

	printf("Enter your 4-digit guess number: ");
	
	scanf("%d", &temp);
	
	// CONVERT USER INPUT TO ARRAY
	for(i=3; i>=0; i--)
	{
		guessNumber[i] = temp%10;
		temp = temp/10;
	}

	printf("\n+--------+----------------------------+\n");
	printf("|  ");
	printNumber(guessNumber);
	printf("  |");
}
	
int checkNumber()
{
	int bulls=0, cows=0, i=0, j=0;

	while(i<=3)
	{
		if(guessNumber[i] == targetNumber[i])
		{
			bulls++;
		}
		i++;
	}

	for(i=0; i<=3; i++)
	{
		for(j=0; j<=3; j++)
		{
			if(j == i)
			{
				continue;
			}
			if(guessNumber[i] == targetNumber[j])
			{
				cows++;
			}
		}
	}

	printf("   %d bull(s)\t", bulls);
	printf("   %d cows(s)  |\n", cows);
	printf("+--------+----------------------------+\n");
	if(bulls == 4)
		return 1;
	else
		return 0;

}

int gameScreen()
{
	system("clear");

	printf("You have a maximum of 10 tries to guess the number. Good luck!\n");

	int tries = 0;
	int checkWin = 0;
	
	generateNumber();
	
	do
	{
		guess();
		tries++;
		printf("%d",tries);
		checkWin = checkNumber();
	}while(tries < 10 && checkWin == 0);

	if(tries == 10)
	{
		printf("\nGAME OVER\n");
		printf("\nThe number was:\t");
		printNumber(targetNumber);
		printf("\n");
		return 0;
	}

	if(checkWin == 1)
	{
		printf("Congratulations!\n");
	}
}	
	
int main(void)
{
	int choice;
	system("clear");
	do
	{
		
		printf("+------------------------------------+\n");
		printf("|            BULLS AND COWS          |\n");
		printf("+------------------------------------+\n");
		printf("|           1. New Game              |\n");
		printf("|           2. Exit                  |\n");
		printf("+------------------------------------+\n");

	
		printf("\nEnter your choice:\t");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				gameScreen();
				break;
			case 2:
				printf("\nBye\n");
				break;
			default:
				printf("\nInvalid choice!\n");
		}
	}while(choice !=2);
}
