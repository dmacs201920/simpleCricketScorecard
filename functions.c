#include<stdio.h>
#include"header.h"
#include<string.h>
#include<stdlib.h>

void Enter(FILE*f1,FILE*f2)
{
    int r,chk;
    static int i;
    char s[25];
    display_scorecard(f1);
    printf("Enter the Runs: ");
    scanf("%d",&r);
    score(r,f1);
    bowling(r,f2);
}
///////////////////////////////////////////////////
int isover(int balls)
{
    static int i,max,x=4;
    static int overs;
    if(i==0)
    {
	printf("Enter the no.of overs in an innings: ");
	scanf("%d",&max);
	i=1;
	return 1;
    }
    if(overs!=max)
    {    
	if(balls==6)
	{
	    overs+=1;
	    return 1;
	}
	else
	    return 0;
    }
    else 
    {
	if(x==0)
	{
	    overs=0;
	    x=4;
	    return 0;
	}
	x--;
	return 2;
    }
}
/////////////////////////////////////////////////// 
void display_scorecard(FILE*f1)
{
    system("clear");
    batsman p;
    int i,b;
    int score=0;
    rewind(f1);
    printf("     PLAYER    RUNS    BALLS     FOURS      SIXES     STATUS\n");
    while(!feof(f1))
	while(fread(&p,sizeof(batsman),1,f1)==1)
	{ 
	    printf(" %10s   %4d     %4d     %5d     %5d     %5c\n",p.name,p.score,p.balls,p.fours,p.sixes,p.flag);
	    score+=p.score;
	}
    i=ex_score(0);
    score+=i;
    b=wicket(0);
    printf("score: %d-%d",score,b);
    rewind(f1);
}
/////////////////////////////////////////////////////

void score(int runs,FILE*f1)
{
    batsman p,temp1,temp2,temp3;
    static int y;
    static int j=1;
    static int balls;
    static long int b;
    static int wickets;
    char s[20];
    int t=0,r;
    char ex;
    int arty;

    if(isover(balls)!=2&&wickets!=10)
    {
	fseek(f1,b,0);
	fread(&p,sizeof(batsman),1,f1);
	printf(" %s \n",p.name);
	if(runs==0)
	{
	    p.balls+=1;
	    balls+=1;
	    fseek(f1,-(sizeof(batsman)),1);
	    fwrite(&p,sizeof(batsman),1,f1);
	    if(!isover(balls))
	    {
		fseek(f1,-(sizeof(batsman)),1);
		b=ftell(f1);
	    }
	    else
	    {
		if(strcmp(p.name,team1[y].name)==0)
		{
		    fseek(f1,(j-y)*(sizeof(batsman)),1);
		    b=ftell(f1);
		}
		else
		{
		    fseek(f1,((j-y)+1)*(-sizeof(batsman)),1);
		    b=ftell(f1);
		}
		balls=0;
	    }
	}

	else if(runs==1)
	{
	    p.score+=1;
	    p.balls+=1;
	    balls+=1;
	    fseek(f1,-(sizeof(batsman)),1);
	    fwrite(&p,sizeof(batsman),1,f1);
	    if(!isover(balls))
	    {
		if(strcmp(team1[y].name,p.name)==0)
		{
		    fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
		    b=ftell(f1);
		}
		else
		{
		    fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
		    b=ftell(f1);
		}
	    }
	    else
	    {
		fseek(f1,-sizeof(batsman),1);
		b=ftell(f1);
		balls=0;
	    }

	}

	else if(runs==2)
	{
	    p.score+=2;
	    p.balls+=1;
	    balls+=1;
	    fseek(f1,-(sizeof(batsman)),1);
	    fwrite(&p,(sizeof(batsman)),1,f1);
	    if(!isover(balls))
	    {
		fseek(f1,-(sizeof(batsman)),1);
		b=ftell(f1);
	    }
	    else
	    {
		if(strcmp(team1[y].name,p.name)==0)
		{
		    fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
		    b=ftell(f1);
		}
		else
		{
		    fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
		    b=ftell(f1);
		}
		balls=0;
	    }
	}

	else if(runs==3)
	{
	    p.score+=3;
	    p.balls+=1;
	    balls+=1;
	    fseek(f1,-(sizeof(batsman)),1);
	    fwrite(&p,(sizeof(batsman)),1,f1);
	    if(!isover(balls))
	    {
		if(strcmp(team1[y].name,p.name)==0)
		{
		    fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
		    b=ftell(f1);
		}
		else
		{
		    fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
		    b=ftell(f1);
		}
	    }
	    else
	    {
		fseek(f1,-sizeof(batsman),1);
		b=ftell(f1);
		balls=0;
	    }

	}



	else if(runs==4)
	{
	    p.score+=4;
	    p.balls+=1;
	    p.fours+=1;
	    balls+=1;
	    fseek(f1,-(sizeof(batsman)),1);
	    fwrite(&p,sizeof(batsman),1,f1);
	    if(!isover(balls))
	    {
		fseek(f1,-(sizeof(batsman)),1);
		b=ftell(f1);
	    }
	    else
	    {
		if(strcmp(team1[y].name,p.name)==0)
		{
		    fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
		    b=ftell(f1);
		}
		else
		{
		    fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
		    b=ftell(f1);
		}
		balls=0;
	    }
	}

	else if(runs==6)
	{
	    p.score+=6;
	    p.balls+=1;
	    p.sixes+=1;
	    balls+=1;
	    fseek(f1,-(sizeof(batsman)),1);
	    fwrite(&p,sizeof(batsman),1,f1);
	    if(!isover(balls))
	    {
		fseek(f1,-(sizeof(batsman)),1);
		b=ftell(f1);
	    }
	    else
	    {
		if(strcmp(team1[y].name,p.name)==0)
		{
		    fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
		    b=ftell(f1);
		}
		else
		{
		    fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
		    b=ftell(f1);
		}
		balls=0;
	    }
	}

	else if(runs==7)
	{
	    printf("Enter the type of Extras: ");
	    getchar();
	    scanf("%c",&ex);
	    if(ex=='n'||ex=='b'||ex=='l')
	    { 
		printf("!!!!!!!!!!!!!!!!Runs: ");
		scanf("%d",&r);
		switch(r)
		{
		    case 0:
			if(ex!='n')
			{
			    p.balls+=1;
			    balls+=1;
			}
			fseek(f1,-(sizeof(batsman)),1);
			fwrite(&p,sizeof(batsman),1,f1);
			if(!isover(balls))
			{
			    fseek(f1,-(sizeof(batsman)),1);
			    b=ftell(f1);
			}
			else
			{
			    if(strcmp(p.name,team1[y].name)==0)
			    {
				fseek(f1,(j-y)*(sizeof(batsman)),1);
				b=ftell(f1);
			    }
			    else
			    {
				fseek(f1,((j-y)+1)*(-sizeof(batsman)),1);
				b=ftell(f1);
			    }
			    balls=0;
			}
			break;

		    case 1:
			if(ex!='n')
			{
			    balls+=1;
			    p.balls+=1;
			}
			fseek(f1,-(sizeof(batsman)),1);
			fwrite(&p,sizeof(batsman),1,f1);
			if(!isover(balls))
			{
			    if(strcmp(team1[y].name,p.name)==0)
			    {
				fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
				b=ftell(f1);
			    }
			    else
			    {
				fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
				b=ftell(f1);
			    }
			}
			else
			{
			    fseek(f1,-sizeof(batsman),1);
			    b=ftell(f1);
			    balls=0;
			}
			break;

		    case 2:
			if(ex!='n')
			{
			    balls+=1;
			    p.balls+=1;
			}
			fseek(f1,-(sizeof(batsman)),1);
			fwrite(&p,(sizeof(batsman)),1,f1);
			if(!isover(balls))
			{
			    fseek(f1,-(sizeof(batsman)),1);
			    b=ftell(f1);
			}
			else
			{
			    if(strcmp(team1[y].name,p.name)==0)
			    {
				fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
				b=ftell(f1);
			    }
			    else
			    {
				fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
				b=ftell(f1);
			    }
			    balls=0;
			}
			break;

		    case 3:
			if(ex!='n')
			{
			    balls+=1;
			    p.balls+=1;
			}
			fseek(f1,-(sizeof(batsman)),1);
			fwrite(&p,(sizeof(batsman)),1,f1);
			if(!isover(balls))
			{
			    if(strcmp(team1[y].name,p.name)==0)
			    {
				fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
				b=ftell(f1);
			    }
			    else
			    {
				fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
				b=ftell(f1);
			    }
			}
			else
			{
			    fseek(f1,-sizeof(batsman),1);
			    b=ftell(f1);
			    balls=0;
			}
			break;

		    case 4:
			if(ex!='n')
			{
			    balls+=1;
			    p.balls+=1;
			}
			fseek(f1,-(sizeof(batsman)),1);
			fwrite(&p,(sizeof(batsman)),1,f1);
			if(!isover(balls))
			{
			    fseek(f1,-(sizeof(batsman)),1);
			    b=ftell(f1);
			}
			else
			{
			    if(strcmp(team1[y].name,p.name)==0)
			    {
				fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
				b=ftell(f1);
			    }
			    else
			    {
				fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
				b=ftell(f1);
			    }
			    balls=0;
			}
			break;

		    case 6:
			if(ex!='n')
			{
			    p.balls+=1;
			    balls+=1;
			}
			fseek(f1,-(sizeof(batsman)),1);
			fwrite(&p,(sizeof(batsman)),1,f1);
			if(!isover(balls))
			{
			    fseek(f1,-(sizeof(batsman)),1);
			    b=ftell(f1);
			}
			else
			{
			    if(strcmp(team1[y].name,p.name)==0)
			    {
				fseek(f1,(((j-y)-1)*sizeof(batsman)),1);
				b=ftell(f1);
			    }
			    else
			    {
				fseek(f1,(((j-y)+1)*(-sizeof(batsman))),1);
				b=ftell(f1);
			    }
			    balls=0;
			}
			break;
		}
	    }
	}
	else if(runs==8)
	{	 
	    wickets+=1;
	    p.balls+=1;
	    balls+=1;
	    p.flag='O';
	    fseek(f1,-(sizeof(batsman)),1);
	    fwrite(&p,sizeof(batsman),1,f1);
	    printf("who is the next batsman: ");
	    scanf("%s",s);
	    rewind(f1);
	    while(t<11)
	    {
		if (strcmp(team1[t].name,s)==0)
		    break;
		else t++;
	    }
	    if(strcmp(team1[y].name,p.name)==0)
	    {
		fseek(f1,((wickets)*sizeof(batsman)),1);
		fread(&temp1,sizeof(batsman),1,f1);
		fseek(f1,-sizeof(batsman),1);
		temp2=temp1;
		while(strcmp(temp2.name,team1[t].name)!=0)
		    fread(&temp2,sizeof(batsman),1,f1);
		fseek(f1,-sizeof(batsman),1);
		y=j;
		j=t;
		printf(" %s,%d\n ",team1[y].name,y);
		printf("  %s,%d\n ",team1[j].name,j);	
	    }
	    else
	    {
		fread(&temp1,sizeof(batsman),1,f1);
		fseek(f1,-2*sizeof(batsman),1);
		temp2=temp1;
		while(strcmp(temp2.name,team1[t].name)!=0)
		    fread(&temp2,sizeof(batsman),1,f1);
		fseek(f1,-sizeof(batsman),1);
		temp3=temp1;
		temp1=temp2;
		temp2=temp1;
		j=t;
		printf(" %s,%d\n ",team1[y].name,y);
		printf("  %s,%d\n ",team1[j].name,j);	
	    }
	    rewind(f1);
	    printf("%d",wickets);
	    printf("who is on strike: ");
	    scanf("%s",s);
	    wicket(1);
	    rewind(f1); 
	    fread(&temp1,sizeof(batsman),1,f1);
	    while(strcmp(s,temp1.name)!=0)
		fread(&temp1,sizeof(batsman),1,f1);
	    fseek(f1,-sizeof(batsman),1);
	    b=ftell(f1);
	    if(isover(0)==2)
	    {
		wickets=0;
	    }
	}
	

    }
}
////////////////////////////////////////
void display_bowlercard(FILE*f1)
{
    system("clear");
    bowler p;
    rewind(f1);
    printf(" BOWLER     RUNS     OVERS     BALLS     WICKETS\n");
    while(!feof(f1))
    {
	fread(&p,sizeof(bowler),1,f1);

	printf(" %6s %4d  %5d  %5d  %7d \n",p.name,p.runs,p.overs,p.balls,p.wickets);
    }
    rewind(f1);
}
///////////////////////////////////////////
void bowling(int runs,FILE*f1)
{
    bowler temp,p;
    static int balls,a;
    int r,ary,y,arr;
    char extra;
    if(!a)
    {
	fseek(f1,-sizeof(bowler),1);
	fread(&p,sizeof(bowler),1,f1);

	switch(runs)
	{
	    case 1:
		p.runs+=1;
		p.balls+=1;
		balls+=1;
		if(balls==6)
		    p.overs+=1;
		fseek(f1,-sizeof(bowler),1);
		fwrite(&p,sizeof(bowler),1,f1);
		break;

	    case 2:
		p.runs+=2;
		p.balls+=1;
		balls+=1;
		if(balls==6)
		    p.overs+=1;
		fseek(f1,-sizeof(bowler),1);
		fwrite(&p,sizeof(bowler),1,f1);
		break;

	    case 3:
		p.runs+=3;
		p.balls+=1;
		balls+=1;
		if(balls==6)
		    p.overs+=1;
		fseek(f1,-sizeof(bowler),1);
		fwrite(&p,sizeof(bowler),1,f1);
		break;

	    case 4:
		p.runs+=4;
		p.balls+=1;
		balls+=1;
		if(balls==6)
		    p.overs+=1;
		fseek(f1,-sizeof(bowler),1);
		fwrite(&p,sizeof(bowler),1,f1);
		break;

	    case 6:
		p.runs+=6;
		p.balls+=1;
		balls+=1;
		if(balls==6)
		    p.overs+=1;
		fseek(f1,-sizeof(bowler),1);
		fwrite(&p,sizeof(bowler),1,f1);
		break;

	    case 7:
		printf("ENTER THE SAME DATA........\n");
		printf("Enter the type of Extras: ");
		getchar();
		scanf("%c",&extra);
		switch(extra)
		{
		    case'w':
			p.extras.wide+=1;
			p.runs+=1;
			fseek(f1,-sizeof(bowler),1);
			fwrite(&p,sizeof(bowler),1,f1);
			ary=ex_score(1);
			break;
		    case'n':
			p.extras.nb+=1;
			printf("\n!!!!!!!!!Runs:");
			scanf("%d",&r);
			p.runs+=(r+1);
			fseek(f1,-sizeof(bowler),1);
			fwrite(&p,sizeof(bowler),1,f1);
			ary=ex_score(r+1);
			break;
		    case'b':
			p.balls+=1;
			printf("\n!!!!!!!!!!Runs:");
			scanf("%d",&r);
			p.runs+=r;
			balls+=1;
			fseek(f1,-sizeof(bowler),1);
			fwrite(&p,sizeof(bowler),1,f1);
			ary=ex_score(r);
			break;
		    case'l':
			p.balls+=1;
			printf("\n!!!!!!!!!!Runs:");
			scanf("%d",&r);
			p.runs+=r;
			balls+=1;
			fseek(f1,-sizeof(bowler),1);
			fwrite(&p,sizeof(bowler),1,f1);
			ary=ex_score(r);
			break;
		}

		break;
	    case 8:
		p.wickets+=1;
		p.balls+=1;
		balls+=1;
		fseek(f1,-sizeof(bowler),1);
		fwrite(&p,sizeof(bowler),1,f1);
		break;

	}
	if((balls==6)&&(isover(0)!=2))
	{
	    display_bowlercard(f1);
	    printf("balls=%d\n",balls);
	    bowler_name(f1);
	    balls=0;
	}
	if(isover(0)==2)
	{
	    display_bowlercard(f1);
	    balls=0;
	    a=0;
	}
    }
}
/////////////////////////////////////////////////////////
void bowler_name(FILE*f1)
{ 
    bowler p,temp;
    static int chk;
    rewind(f1);
    printf("Enter bowler's name:");
    scanf("%s",temp.name);

    while((fread(&p,sizeof(bowler),1,f1))==1)
    {
	if(strcmp(p.name,temp.name)==0)
	{
	    chk=1;
	    printf("..............\n");
	    break;
	}
    }
    if(chk!=1)
    {
	printf("............++.....\n");
	fseek(f1,0,2);
	temp.runs=0;
	temp.balls=0;
	temp.overs=0;
	temp.wickets=0;
	temp.extras.wide=0;
	temp.extras.lb=0;
	temp.extras.byes=0;
	temp.extras.nb=0;
	fwrite(&temp,sizeof(bowler),1,f1);
    }
    chk=0;

}
///////////////////////////////////////////////////////////////
int ex_score(int extra)
{
    static int score;
    int s;
    score+=extra;
    s=score;
    if(isover(0)==2)
    {
	score==0;
	return s;
    }
    return score;
}
/************************************************************/
int wicket(int x)
{
    static int wickets;
    int w;
    wickets+=x;
    return wickets;
}

