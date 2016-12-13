/* 
Program Name: Battleship.c
Programmer: Gennady Evtodiev
Class: CS 3335 A 
HW: 04
Problem: 04
Date: 10/27/16
*/ 
#include<stdio.h>
#include<time.h>
void setBoard(int*);
void setComputerBoard(int*);
void printBoard(int*, int*);
int playGame(int*, int*);


int main()
{
	//int *human; Commented to remove errors caused by statement
    int human[10];
	//int *computer; Commented to remove errors caused by statement
	int computer[10];
	srand(time(NULL));
	setBoard(human);
	setComputerBoard(computer);
	int winner = playGame(human,computer);
	if(winner==0)
	{
      printf("Computer wins!\n");
	} 
	else
      printf("Human wins!\n");
	
}
//=====================================================
//setBoard:	sets the ship and empty location of the
//			human player's board
//=====================================================
void setBoard(int *b)
{
   int i;
   int slot1 = -1;
   int slot2 = -1; //Initialized to be invalid
   
   //======== Initialize Array ========
   for(i = 0; i < 10; i++)
      *(b + i) = 0;
      
   //======== Slot 1 Validity Check ========
   while(slot1 < 0 || slot1 > 9)
   {
      printf("Enter 1st position: ");
      scanf("%d",&slot1);  
   }
   //======== Slot 2 Validity Check ========      
   while(slot2 != slot1 + 1 && slot2 != slot1 - 1 || slot2 < 0 || slot2 > 9)
   {
      printf("Enter 2nd position: ");
      scanf("%d",&slot2);
   }
   
   *(b + slot1) = 1;
   *(b + slot2) = 1;
}
//=====================================================
//setComputerBoard:	sets the ship and empty location of
//					the computer's board
//=====================================================
void setComputerBoard(int *j)
{
	int i;
	int slot1 = -1;
	int slot2 = -1;
   	for(i = 0; i < 10; i++)
      *(j + i) = 0;
	  
   	slot1 = rand()%10;
   	if(slot1 == 9)
      slot2 = 8;
      
   	if(slot1 == 0)
      slot2 = 1;
      
   	else
      slot2 = slot1 + 1;
      
   *(j + slot1) = 1;
   *(j + slot2) = 1;
}
//=====================================================
//printBoard:	prints the board in readable form by
//				replacing numbers with letters symbolizing
//				hits, misses, empty spaces, or ship location
//=====================================================
void printBoard(int *h, int *c)
{
	int i;
	printf("=== Human Board ===\n");
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for(i = 0; i < 10; i++)
	{
		if(*(h+i) == 1)
			printf("S ");
			
		else if(*(h+i)== 2)
			printf("H ");
			
		else if(*(h+i) == 3)
			printf("M ");
			
		else if(*(h+i) == 4)
			printf("H ");
			
		else
			printf("* ");
	}
	
	printf("\n\n=== Computer Board ===\n");
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for(i = 0; i < 10; i++)
	{
		if(*(c+i) == 1)
			printf("S ");
			
		else if(*(c+i) == 2)
			printf("H ");
			
		else if(*(c+i) == 3)
			printf("M ");
		
		else if(*(c+i) == 4)
			printf("H ");
		
		else
			printf("* ");
	}
}
//=====================================================
//playGame method: 	Allows the computer & human to make
//					to make guesses until one reaches
//					two hits. Displays results of guess
//					and return integer 0 if computer win
//=====================================================
int playGame(int *h, int *c)
{
   int comphits = 0;
   int humhits = 0;
   int compguess;
   int humguess;
   while(comphits < 2 && humhits < 2)
   {
   	//========== Computer Turn ==========
   	compguess = rand()%10;
	printf("\nComputer guesses %d\n", compguess);
	if(*(h + compguess) == 1)
	{
		printf("HIT!\n");
		*(h + compguess) = 4;
		comphits++;
	}
	else if(*(h + compguess) == 4)
		printf("MISS!\n");
		
	else
	{
		printf("MISS!\n");
		*(h + compguess) = 3;
	}
	printBoard(h, c);
	if(comphits == 2) //prevents human from getting a guess after already losing
		break;
	//========== Human Turn ==========
	printf("\nEnter guess: ");
	scanf("%d",&humguess);
	printf("You guessed %d\n", humguess);
	if(*(c + humguess) == 1)
	{
		printf("HIT!\n");
		*(c + humguess) = 4;
		humhits++;
	}
	else if(*(c + humguess) == 4)
		printf("MISS!\n");
		
	else
	{
		printf("MISS!\n");
		*(c + humguess) = 3;
	}
	
	printf("\n= = = = = = = = = = = = = = = = = = = = = = = = \n");
   }
   if(comphits == 2)
   	return 0;
	
   else
   	return 1;
}
   
   
   
