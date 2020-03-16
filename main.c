#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
void main()
{
    int s[11];
    int c,i=0,chk=0,d,balls=0,innings,inn=0,jam=0;
    static int temp;
    FILE*f1,*f2,*f3,*f4;
    batsman p;
    while(inn<2)
    {
	printf("innings (1/2): ");
	scanf("%d",&innings);
	if(innings==1)
	{
	    f1=fopen("1st_innings_batsmen.txt","rb+");
	    f2=fopen("1st_innings_bowler.txt","rb+");
	    if(f1==NULL)
	    {
		printf("EeEEEE");
		f1=fopen("1st_innings_batsmen.txt","wb+");
		if(f1==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }
	    if(f2==NULL)
	    {
		printf("1bbbbbb  ");
		f2=fopen("1st_innings_bowler.txt","wb+");
		if(f2==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }

	}
	else
	{
	    f1=fopen("2nd_innings_batsman.txt","rb+");
	    f2=fopen("2nd_innings_bowler.txt","rb+");
	    if(f1==NULL)
	    {
		printf("2EeEEEE");
		f1=fopen("2nd_innings_batsman.txt","wb+");
		if(f1==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }
	    if(f2==NULL)
	    {
		printf("2bbbbbb...");
		f2=fopen("2nd_innings_bowler.txt","wb+");
		if(f2==NULL)
		{
		    printf("cannot open the file");
		    exit(1);
		}
	    }

	}
	if(!chk)
	{
	    printf("Enter the players list");
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
	    printf("ENTER 7 FOR EXTRAS && 8 FOR WICKETS");
	    printf("ENTER N FOR NOBALL\n W FOR WIDES \n b FOR BYES\n L FOR LEG BYES\n");
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

	while(isover(0)!=2)
	{
	    Enter(f1,f2);
	}
	fclose(f1);
	fclose(f2);

	printf("INNINGS OVER ");
	temp=0;
	inn++;
    }
   /* f1=fopen("1st_innings_batsmen.txt","rb+");
    f2=fopen("1st_innings_bowlers.txt","rb+");
    display_scorecard(f1);
    display_bowlercard(f2);
    fclose(f1);
    fclose(f2);
   /xx* f3=fopen("1st_innings_batsmen.txt","rb+");
    f4=fopen("1st_innings_bowlers.txt","rb+");
    display_scorecard(f3);
    //display_bowlercard(f4);
    fclose(f3);
    fclose(f4);*/
}
