		// PURPOSE:    MAIN FUNCTION
		// WRITTEN BY: RAMU.V
		// REGD.NO:    173230


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
void main()
{
    int s[11];
    int c,i=0,chk=0,d,balls=0,innings,inn=0,jam=0;
    static int temp;
    FILE*f1,*f2;			//programme uses these same file pointers to open the files required for both the innings
    batsman p;
    while(inn<2)				// The loop checks whether both the innings are finished or not
    {
	printf("innings (1/2): ");
	scanf("%d",&innings);
	if(innings==1)			// opens the files for 1st innings
	{
	    f1=fopen("1st_innings_batsmen.txt","rb+");
	    f2=fopen("1st_innings_bowler.txt","rb+");
	    if(f1==NULL)
	    {
		f1=fopen("1st_innings_batsmen.txt","wb+");
		if(f1==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }
	    if(f2==NULL)
	    {
		f2=fopen("1st_innings_bowler.txt","wb+");
		if(f2==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }

	}
	else					// opens the files for 2nd innings
	{
	    f1=fopen("2nd_innings_batsman.txt","rb+");
	    f2=fopen("2nd_innings_bowler.txt","rb+");
	    if(f1==NULL)
	    {
		f1=fopen("2nd_innings_batsman.txt","wb+");
		if(f1==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }
	    if(f2==NULL)
	    {
		f2=fopen("2nd_innings_bowler.txt","wb+");
		if(f2==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }

	}
	if(!chk)			// batsmaen input
	{
	    printf("Enter the players list:");
	    while(i<11)
	    {
		scanf("%s",team1[i].name);
		team1[i].flag='n';
		fwrite(&team1[i],sizeof(batsman),1,f1);
		i++;
	    }
	    rewind(f1);
	    if(jam==0)
	    {
		printf("\nENTER 7 FOR EXTRAS && 8 FOR WICKETS\n");
		printf("ENTER N FOR NOBALL\n      W FOR WIDES \n      b FOR BYES\n      L FOR LEG BYES\n");
		jam=1;
	    }
	}      
	d=isover(balls);
	i=0;
	if(temp==0)
	{
	    bowler_name(f2);
	    temp=1;
	}

	while(isover(0)!=2)		// loop to enter the runs
	{
	    Enter(f1,f2);
	}
	fclose(f1);			// closes the files after every innings 
	fclose(f2);

	printf("INNINGS OVER..\n ");
	temp=0;
	inn++;
    }
    printf("For seeing the scorecard of this match......\n");
    printf(" Type cc -o display display.c ENTER\n Then type ./display ENTER\n");
}
