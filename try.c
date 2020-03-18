#include<stdio.h>
void main()
{
    FILE*f1,*f2,*f3,*f4;
    f1=fopen("1st_innings_batsmen.txt","rb+");
    f2=fopen("1st_innings_bowlers.txt","rb+");
    display_scorecard(f1);
    display_bowlercard(f2);
    fclose(f1);
    fclose(f2);
    f3=fopen("2nd_innings_batsmen.txt","rb+");
    f4=fopen("2nd_innings_bowlers.txt","rb+");
    display_scorecard(f3);
   display_bowlercard(f4);
    fclose(f3);
    fclose(f4);

