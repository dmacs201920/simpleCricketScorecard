typedef struct batsman{
    char name[10];
    int score;
    int balls;
    int fours;
    int sixes;
    char flag;
}batsman;
int max;

batsman team1[11],team2[11];

typedef struct extra{
    int wide;
    int lb;
    int byes;
    int nb;
}extra;
typedef struct bowler{
    char name[15];
    int overs;
    int runs;
    int balls;
    int wickets;
    extra extras;
}bowler;
void Enter(FILE*f1,FILE* );
int isover(int balls);
void display_scorecard(FILE*);
void score(int ,FILE*);
void bowling(int ,FILE*);
void display_bowlercard(FILE*);
void bowler_name(FILE*);
int ex_score(int );
int wicket(int );
