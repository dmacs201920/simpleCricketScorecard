		/* PURPOSE: THIS FILE CONTAINS THE PROGRAMME WHICH IS USEFUL FOR DISPLAYING THE SCORECARD OF THE MATCH WHENEVER IT IS REQUIRED AFTER AMTCH IS OVER
		 * WRITTEN BY: RAMU.V
		 * REGD.NO:    173230
		 */

#include<stdio.h>
#include<stdlib.h>
#include"header.h"
void display_score(FILE*f1,FILE*f2)
{
    batsman p;
    bowler q;
    static int score,score1,wickets;
    rewind(f1);
    printf("             BATSMEN SCORECARD         \n");
    printf("     PLAYER    RUNS    BALLS     FOURS      SIXES     STATUS\n");
    while(!feof(f1))
	while(fread(&p,sizeof(batsman),1,f1)==1)
	{ 
	    printf(" %10s   %4d     %4d     %5d     %5d     %5c\n",p.name,p.score,p.balls,p.fours,p.sixes,p.flag);
	}
    rewind(f1);
    rewind(f2);
    while(!feof(f2))
    {
	while(fread(&q,sizeof(bowler),1,f2))
	{
	    score+=q.runs;
	    wickets+=q.wickets;
	}
    }
    printf(" score: %d-%d \n",score,wickets);
    score1=score;
    score=0;
    wickets=0;
    rewind(f2);
    {
	printf("            BOWLER CARD       \n");
	printf("    BOWLER     RUNS     OVERS     BALLS     WICKETS\n");
	while(!feof(f2))
	{
	    while(fread(&q,sizeof(bowler),1,f2)==1)

		printf("%10s     %4d     %5d     %5d     %7d \n",q.name,q.runs,q.overs,q.balls,q.wickets);
	}
	rewind(f2);
    }
    if(score1>score)
	printf("TEAM1 WON \n");
    else if (score>score1)
	printf(" TEAM2 WON \n");
    else
	printf(" MATCH DRAWN ");

}

void main()
{
    FILE*f1,*f2,*f3,*f4;

    f1=fopen("1st_innings_batsmen.txt","rb+");
    f2=fopen("1st_innings_bowler.txt","rb+");
    f3=fopen("2nd_innings_batsman.txt","rb+");
    f4=fopen("2nd_innings_bowler.txt","rb+");
    if(f1==NULL)
    {
	printf("can,t open f1\n");
	exit(1);
    }
    if(f2==NULL)
    {
	printf("can,t open f2\n");
	exit(1);
    }
    display_score(f1,f2);
    if(f3==NULL)
    {
	printf("can,t open f3\n");
	exit(1);
    }
    if(f4==NULL)
    {
	printf("can,t open f4\n");
	exit(1);
    }

    display_score(f3,f4);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}
