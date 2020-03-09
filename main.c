#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
void main()
{
    int s[11];
    int c,i=0,chk=0,d,balls=0,innings,inn=0;
    FILE*f1,*f2;
    batsman p;
    while(inn<2)
    {
    printf("innings (1/2): ");
    scanf("%d",&innings);
    f1=fopen("players.txt","rb+");
    f2=fopen("bowlers.txt","rb+");
    if(!chk)
    {
	printf("Enter the players list");
	while(i<11)
	{
	    scanf("%s",team1[i].name);
	    fwrite(&team1[i],sizeof(batsman),1,f1);
	    i++;
	}
	rewind(f1);
	i=0;
	while(i<11)
	{
	    printf("%s %d %d ",team1[i].name,team1[i].score,team1[i].balls);
	    i++;
	}
    }
    d=isover(balls);

    while(isover(0)!=2)
    {
		Enter(f1,f2);
    }
    printf("INNINGS OVER ");
    inn++;
    }


}
