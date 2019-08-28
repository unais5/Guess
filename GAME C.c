#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <MMsystem.h>


// FUNCTIONS PROTOTYPE
void Menuscreen ();
int Playmenu ();
void screen ();
int instructions ();
int highscore ();
void names ();
void Question_P1();
void Answer_P1();
void Question_P2 ();
void Answer_P2 ();
void win_lose ();
//

// VARIABLES DESCRIBED GLOBALLY
char player1[10],player2[10],hint[100],word[50],answer[50],instruction[80],ch;
int i=1,score1=0,score2=0,choice,j=1,len1,len2;
//

int main()
{
	system("color 3F");// SCREEN COLOR
	Menuscreen ();
	Playmenu ();	
}



// MAIN MENU SCREEN
void Menuscreen ()
{
	printf("\n\n\t\t\t\tWORD");
	printf("\n");
	printf("\t\t\t\t    GUESSER");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\tPress : \n");
	printf("\n\n\t\t\t\t1) PLAY \n");
	printf("\n\t\t\t\t2) EXIT \n");
	printf("\n\t\t\t\t3) HOW TO PLAY\n");
	printf("\n\t\t\t\t4) HIGH SCORE\n");
	printf("\n\t\t\t\t\t\t\t  BY: AHMED\n");
	scanf("%d",&choice);// CHOOSING WHICH OPERATION TO PERFORM
	system ("cls");
}


// PROCEEDS PROGRAM WITH USER DIRECTION
int Playmenu ()
{
	if (choice>=1 && choice<=4)
	{
		switch (choice)
		{
			case (1):
				names ();
				while (j!=6)
					{
						screen ();
						Question_P1();
						screen ();
						Answer_P1();
						screen ();
						Question_P2 ();
						screen ();
						Answer_P2 ();
						j++;
					}
				win_lose ();
				break;
				
				
			case (2):
				printf("\n\n\n\n\t\t\t  PRESS ANY KEY TO EXIT\n\n\n\n\n");
				return 0;
				break;
				
				
			case (3):
				instructions ();// READ FROM A FILE
				getch ();
				break;
				
			case (4):
				highscore ();// READ FROM A FILE
				getch ();
				break;	
		}
	}
}


int instructions ()
{
	printf("\n\n\t\t\t\tINSTRUCTIONS\n\n");
	// FILE CREATED 
	FILE *fp = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\Instructions.txt","r");
	
	if (fp == NULL)
	{
		printf("UNABLE TO FIND THE FILE");
		return 0;
	}
	while (1)
	{
	fgets(instruction,"%s",fp);// READ ALL THE INFORMATION FROM FILE 
	printf("\n%s",instruction);
		if (feof(fp))
			break;
	}
	fclose (fp);
}

int highscore ()
{
	char name[80];
	int score;
	system("cls");
	printf("\n\n\t\t\t\tHIGH SCORE\n\n");
	// FILE CREATED 
	FILE *fp = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\highscore.txt","r");
																				
	if (fp == NULL)
	{
		printf("UNABLE TO FIND THE FILE");
		return 0;
	}
	while (1)
	{
		// READING THE NAME AND SCORE
	fscanf(fp," %[^,],%d",name,&score);
	printf("\n\n%s\t:\t%d",name,score);
		if (feof(fp))
			break;
	}
	fclose (fp);
}



// FUNCTION CALLED IN PLAY (ASKING FOR NAMES OF PLAYERS)
void names()
{
	system("cls");
	printf("\n\n\t\t\t\tPLAYER NAMES\n\n\n");
	printf("!!!Enter Names In Capital!!!\n\n");
	printf("Enter Name Of Player1 : ");
	scanf("%s",player1);
	printf("\n\nEnter Name Of Player2 : ");
	scanf("%s",player2);
}


// GAME SCREEN WHILE PLAYING
void screen()
{
	system("cls");	
	printf("\t\t\t\t   WORD");
	printf("\n\t\t\t\t  GUESSER");
	printf("\n\n\t\t\t\t%s:%s",player1,player2);
	printf("\n\t\t\t\t    %d:%d",score1,score2);
	for (i=1;i<8;i++)
	{
		printf("\n");
	}
}



// WORD GIVEN BY PLAYER 1
void Question_P1()
{
	
	printf("\t\t\t\t%s GIVE WORD\n",player1);
	printf("\n\nENTER WORD : ");
	scanf(" %[^\n]",word);
	len1 = strlen(word);
	printf("\nENTER HINT : ");
	scanf(" %[^\n]",hint);
}


// ANSWER BY PLAYER 2 
void Answer_P1()
{
	int lives=4;
	for(i=1;i<=5;i++)
	{
	printf("\t\t\t\t%s GUESS WORD",player2);
	printf("\t\t  LIVES : %d",lives);
	printf("\n\n\t\t\t\t LETTERS : %d",len1);
	printf("\n\nHINT : %s",hint);
	printf("\n_________");
	printf("\n\n\nGUESS WORD : ");
	scanf(" %[^\n]",&answer);
	if((strcmp(word,answer)) == 0)
		{
			printf("\n\n\t\t\t\t!!CORRECT CONGRATULATIONS!!\n\n");
			// SOUND
			PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\correct.wav"),NULL,SND_SYNC);
			break;
		}
	if (i<=4)
		{
			lives--;// LIVES DECREASING WITH EVERY WRONG ANSWER
			printf("\n\n\t\t\t\t!!WRONG TRY AGAIN!!\n\n");
			// SOUND
			PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\wrong.wav"),NULL,SND_SYNC);
		}
	if (i == 5)
		{
			printf("\n\n\t\t\t\t!!YOU LOSE!!");
			// SOUND
			PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\lose.wav"),NULL,SND_SYNC);
			// AWARDING SCORE TO PLAYER 1 BECAUSE PLAYER 2 CAN'T GUESS A WORD IN RESPECTIVE LIVES
			score1++;
		}
	}
	sleep(1);
}


// QUESTION BY PLAYER 2 
void Question_P2 ()
{
	printf("\t\t\t\t%s GIVE WORD\n",player2);
	printf("\n\nENTER WORD : ");
	scanf(" %[^\n]",word);
	len2 = strlen (word);
	printf("\nENTER HINT : ");
	scanf(" %[^\n]",hint);
}



// ANSWER BY PLAYER 1 
void Answer_P2()
{
	int lives=4;
	for(i=1;i<=5;i++)
	{
	printf("\t\t\t\t%s GUESS WORD",player1);
	printf("\t\t  LIVES : %d",lives);
	printf("\n\n\t\t\t\t LETTERS : %d",len2);
	printf("\n\nHINT : %s",hint);
	printf("\n_________");
	printf("\n\n\nGUESS WORD : ");
	scanf(" %[^\n]",&answer);
	if((strcmp(word,answer)) == 0)
		{
			printf("\n\n\t\t\t\t!!CORRECT CONGRATULATIONS!!\n\n");
			// SOUND
			PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\correct.wav"),NULL,SND_SYNC);
			break;
		}
	if (i<=4)
		{
			lives--;// LIVES DECREASING WITH EVERY WRONG ANSWER
			printf("\n\n\t\t\t\t!!WRONG TRY AGAIN!!\n\n");
			// SOUND
			PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\wrong.wav"),NULL,SND_SYNC);
		}
	if (i == 5)
		{
			printf("\n\n\t\t\t\t!!YOU LOSE!!");
			// SOUND
			PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\lose.wav"),NULL,SND_SYNC);
			// AWARDING SCORE TO PLAYER 1 BECAUSE PLAYER 2 CAN'T GUESS A WORD IN RESPECTIVE LIVES
			score2++;
		}
	}
	sleep(1);
}


// DECIDING WINNER AND STORING HIGH SCORE IN FILE 
void win_lose ()
{
	int score;
	char name[10];
		if (score1 > score2)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t  !!!%s IS THE WINNER!!!",player1);
		// SOUND
		PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\win.wav"),NULL,SND_SYNC);
		// READING FROM FILE 
		FILE *fa = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\highscore.txt","r");
		fscanf(fa," %[^,],%d",name,&score);
		fclose	(fa);
		
			FILE *fb = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\highscore.txt","w");
		if (score < score1)
		{
			fprintf(fb,"%s,%d",player1,score1);
		}
		else if (score > score1)
		{
			fprintf(fb,"%s,%d",name,score);
		}
		else if (score == score1)
		{
			fprintf(fb,"%s,%d\n",name,score);
			fprintf(fb,"%s,%d",player1,score1);
		}
		fclose	(fb);	
	}
	
	else if (score1 < score2)
	{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t  !!!%s IS THE WINNER!!!",player2);
			PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\win.wav"),NULL,SND_SYNC);
			FILE *fc = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\highscore.txt","r");
			fscanf(fc," %[^,],%d",name,&score);
			fclose	(fc);
			
			FILE *fd = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\highscore.txt","w");
			if (score < score2)
			{
				fprintf(fd,"%s,%d",player2,score2);
			}
			else if (score > score2)
			{
				fprintf(fd,"%s,%d",name,score);
			}
			else if (score == score2)
			{
				fprintf(fd,"%s,%d\n",name,score);
				fprintf(fd,"%s,%d",player2,score2);
			}
			fclose	(fd);	
	}
		
	else if (score1 == score2)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t  !!!IT'S A DRAW!!!");
		PlaySound(TEXT("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\music\\win.wav"),NULL,SND_SYNC);
		FILE *fe = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\highscore.txt","r");
		fscanf(fe," %[^,],%d",name,&score);
		fclose	(fe);
		
		FILE *fg = fopen ("C:\\Users\\UNIAS\\Desktop\\MAIN PROJECT\\text\\highscore.txt","w");
		if (score < score1)
		{
			fprintf(fg,"%s,%d\n",player1,score1);
			fprintf(fg,"%s,%d",player2,score2);	
		}
		else if (score > score1)
		{
			fprintf(fg,"%s,%d",name,score);
		}
		else if (score == score1)
		{
			fprintf(fg,"%s,%d\n",name,score);
			fprintf(fg,"%s,%d\n",player1,score1);
			fprintf(fg,"%s,%d",player2,score2);
		}
	fclose	(fg);
	}
}
