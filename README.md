# simpleCricketScorecard
A novice implementation of simple cricket scorecard

/***********************************/


PROJECT:SIMPLE CRICKET SCORECARD
WRITTEN BY: RAMU.V
REGD.NO: 173230

The purpose of the project is to make scorecard for a required match.

INPUT:  Input will be taken from the user
	Names of batting team players will be taken at the start of every innings.
     	Name of the bowler will be taken at the start of the match and after every Over.
	Number of Overs in an innings will be taken at the start of the match.
	For Extras User need To Enter 7.
	Then he Can select the type of Extras. 
	For Wickets You need to Enter 8.
	Then Input can be Entered on Request.

OUTPUT: It Displays the scorecard of the Batsmen before asking the Runs.
	Bowler card will be displayed after Every over.
	
1st innings batsmen.txt: Text File using for Storing 1st team's scorecard.
1st innings bowler.txt : Text File using for storing 1st innings Bowler's data.
2nd innings batsmen.txt: Text File using for Storing 2nd team's scorecard.
2nd innings bowler.txt : Text File using for storing 2nd innings Bowler's data.
Functions.c: 
		This File Contains all the various Functions Required in the Programme.
Header.h:
		Header File

SAMPLE INPUT & OUTPUT:
./score
  innings (1/2): 1
  Enter the players list
		 sai
	       	 ram
		 satya
      	         arun
		 akhil
                 viky
		 viswa
		 kamal
		 heam
		 kasam	
	  	 sandeep	
 ENTER 7 FOR EXTRAS && 8 FOR WICKETS
		ENTER N FOR NOBALL
		      W FOR WIDES
		      b FOR BYES
	              L FOR LEG BYES
  Enter the no.of overs in an innings: 2
  Enter bowler's name: sai

  sai     0 0 0 0 n
  ram     0 0 0 0 n
  satya   0 0 0 0 n
  arun    0 0 0 0 n
  akhil   0 0 0 0 n
  viky    0 0 0 0 n
  viswa   0 0 0 0 n
  kamal   0 0 0 0 n
  heam    0 0 0 0 n
  kasam   0 0 0 0 n
  sandeep 0 0 0 0 n
  score: 0-0 Enter the Runs: 1
  
  sai     1 1 0 0 n
  ram     0 0 0 0 n
  satya   0 0 0 0 n
  arun    0 0 0 0 n
  akhil   0 0 0 0 n
  viky    0 0 0 0 n
  viswa   0 0 0 0 n
  kamal   0 0 0 0 n
  heam    0 0 0 0 n
  kasam   0 0 0 0 n
  sandeep 0 0 0 0 n
  score: 1-0 Enter the Runs: 7
  ram
  Enter the type of Extras:b
  !!!!!!!!!!!!!!!!Runs:1

  Enter the Same Data 
  Enter the type of Extras:b
  !!!!!!!!!!!!!!!!Runs:1
 
  sai     1 1 0 0 n
  ram     0 1 0 0 n
  satya   0 0 0 0 n
  arun    0 0 0 0 n
  akhil   0 0 0 0 n
  viky    0 0 0 0 n
  viswa   0 0 0 0 n
  kamal   0 0 0 0 n
  heam    0 0 0 0 n
  kasam   0 0 0 0 n
  sandeep 0 0 0 0 n
  score: 2-0 Enter the Runs: 8
  sai
  who is the next batsman: viky
   ram
   viky
  Who is on strike: ram

  sai     1 2 0 0 O
  ram     0 1 0 0 n
  satya   0 0 0 0 n
  arun    0 0 0 0 n
  akhil   0 0 0 0 n
  viky    0 0 0 0 n
  viswa   0 0 0 0 n
  kamal   0 0 0 0 n
  heam    0 0 0 0 n
  kasam   0 0 0 0 n
  sandeep 0 0 0 0 n
  score: 2-1 Enter the Runs: 1
  
  sai     1 2 0 0 O
  ram     1 2 0 0 n
  satya   0 0 0 0 n
  arun    0 0 0 0 n
  akhil   0 0 0 0 n
  viky    0 0 0 0 n
  viswa   0 0 0 0 n
  kamal   0 0 0 0 n
  heam    0 0 0 0 n
  kasam   0 0 0 0 n
  sandeep 0 0 0 0 n
  score: 3-1 Enter the Runs: 

  after a over

   BOWLER  RUNS  OVERS  BALLS  WICKETS
      sai    5       1      6        1

  balls=6
  Enter bowler's name:

  Continues like this,till the end of the innings.

   INNINGS OVER.
   
  innings(1/2): 2

	continues in the same way till the end of second innings

   INNINGS OVER.	



//////////////////////////////



