#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
const int m=3;/*tic tac toe*///game 2
const int n=3;/*tic tac toe*///game 2
int ques_no; //game 3
void game1();
void game2();
void game3();
void game4();
void ques(int, int );//game 3
int qualifiers(int num)//game 4
{
     srand(time(NULL));
   
    return 1+rand()%num;
}

int compare(char arr[], char result[])//game 3
{
    int a;
     a=strlen(result);
   for (int i=0; i<a;i++)
   {
       if (arr[i]==result[i] && i!=a-1)
       continue;
       else if (arr[i]==result[i] && i==a-1)
       return 1;
       else
       {return 0;
       break;}
   }
   
}
int rand_ques()//game 3
{
     srand(time(NULL));
    ques_no=1+rand()%20;
    return ques_no;

}
int roll_dice()//game 1
{
    srand(time(NULL));
    return 1+rand()%6;
}
int rand_value()//game 2
{
    srand(time(NULL));
    return rand()%3;
}
void print_arr(char arr[m][n])//game 2
{
    
      for (int i=0; i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (j!=2)
            printf(" %c |", arr[i][j]);
            else
            printf(" %c ", arr[i][j]);
        }
        
        if (i!=2)printf("\n------------");
        else printf("\n");
        printf("\n");
    }
}

int check_result(char arr[m][n])//game 2
{
    for(int i=0;i<3;i++)
    {
        if (arr[i][0]!=' ')
        {if (arr[i][0]==arr[i][1]&& arr[i][1]==arr[i][2])
        {if (arr[i][0]=='X')
        return 1;
        else return 2;}}
    }
     for(int j=0;j<3;++j)
    {
        if (arr[0][j]!=' ')
        {if (arr[0][j]==arr[1][j]&& arr[1][j]==arr[2][j])
        {if (arr[0][j]=='X')
        return 1;
        else
        return 2;}}
    }
    if (arr[1][1]!=' ')
    {if (arr[0][0]==arr[1][1]&& arr[1][1]==arr[2][2])
    return 1;
    else if (arr[0][2]==arr[1][1]&& arr[1][1]==arr[2][0])
    return 1;
    else return 0;}
   
}
int main()
{
    int choice;
   
    while(1)
    {
         printf("HELLO!!! WELCOME TO GAME CENTRAL!!\n Please chose the game you want to play:\n1.ROLL THE DICE\n2.TIC TAC TOE\n3.GUESS THE RIDDLES\n4.MULTIPLAYER HORSE RACING\n5.EXIT\nYour choice: ");
    scanf("%d", &choice);
       switch (choice)
       {
       case 1:
           game1();
           break;
       case 2:
           game2();
           break;
       case 3:
           game3();
       case 4:
           game4();    
       case 5:
            printf("Exiting.....");
            exit(1);
       default:
          printf("INVALID INPUT!!");
          continue;
       }
    }
    return 0;
}
void game1()
{
     int choice, choice2, num1, num2, score1=0, score2=0;
    printf("\nYou selected : ROLL THE DICE\nRULES: \nRoll the dice to get a random number. Five times the number will be added to the SCORE.\nThe player whose score reaches 100 wins.\nEverytime one player gets a 6, 6 points gets reduced from another players score.\n");
    while(1)
    {
    printf("\n Enter 1 to roll dice for player 1\n Enter 2 to roll dice for player 2\n Enter 3 to Exit\nEnter your choice: ");
            scanf("%d",&choice2);    
            switch (choice2)
            {
        case 1:
            num1=roll_dice();
            printf("Number for player 1= %d\n\n", num1);
            score1+=num1*5;
            if(num1==6&&score2>6)
            score2-=6;
            printf("Score of player 1= %d\n", score1);
            printf("Score of player 2= %d\n", score2);
            break;
        case 2:
            num2=roll_dice();
            printf("Number for player 2= %d\n\n", num2);
            score2+=num2*5;
            if(num2==6&&score1>6)
            score1-=6;
            printf("Score of player 1= %d\n", score1);
            printf("Score of player 2= %d\n", score2);
            break;
        case 3:
             printf("Exiting...\n");
             exit(1);    
        default:
            printf("INVALID.\n");
            continue;
            }
            if (score1>=100)
            {
                printf("\nPlayer 1 Wins!!!");
                exit(1);
            }
            else if (score2>=100)
            {
                printf("\nPlayer 2 Wins!!!");
                exit(1);
            }
            else continue;
    }
}
void game2()
{
    int choice, row2, col1, row1, col2, result=0, count=0, comp, i, j;
    char arr[3][3];
    for (int i=0; i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
         arr[i][j]=' ';
        }
    }
    printf("\n\n\tTIC TAC TOE\nRules:\n\aEnter the position where you want to place the circle/cross. The positions are entered in the form of rows and columns.\nfor ex- row=1 column=2 gives the second position in FIRST row.\n");
    print_arr(arr);
  
    printf("Enter 1 for player 1\nEnter 2 for player 2\nEnter 3 for exit\nEnter 4 to play with computer\n");
    scanf("%d", &choice);
    if (choice==4)
    comp=choice;
    choice=1;
    while(1)
    {
    switch(choice)
    {
        case 1:
        while (2)
        {
            printf("\nNow enter the position.\n");
        printf("\nPlayer 1:\nRow- ");
        scanf("%d", &row1);
        printf("column- ");
        scanf("%d", &col1);
        if (arr[row1-1][col1-1]==' '&& col1<4)
        {arr[row1-1][col1-1]='X';
         if (comp==4)
         choice=4;
         else
        choice=2;}
        else 
        {printf("\nINVALID!!\n");
        continue;}
        count++;
        print_arr(arr);
        break;
        }
        break;
        case 2:
        while (3)
        {
        printf("\nPlayer 2:\nRow- ");
        scanf("%d", &row2);
        printf("column- ");
        scanf("%d", &col2);
        if (arr[row2-1][col2-1]==' ' && col2<4)
        {arr[row2-1][col2-1]='O';
         choice=1;}
        else 
        {printf("\nINVALID!!\n");
        continue;}
        count++;
        print_arr(arr);
        break;
        }
        break;
        case 3:
        printf("Exiting...\n");
        exit(1);
        case 4:
        printf("Computer's Turn\n");
        while(4)
        {
            i=rand_value();
            j=rand_value();
           if (arr[i][j]==' ' && j<4)
            {
                arr[i][j]='O';
                choice=1;
            }
        else 
        continue;
        count++;
        print_arr(arr);
        break;
        }
        break;
        default:
        printf("\nINVALID!!!\n");
        continue;
    }       

        result=check_result(arr);
        if (result==1)
        {
        printf("\n\nPLAYER 1 WINS !!!\n\n");
         printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\n");
        exit(1);
        }
        else if (result==2&& comp!=4)
       {
         printf("\n\nPLAYER 2 WINS !!!\n\n");
        printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\n");
        exit(1);
        } 
        else if (result==2&& comp==4)
       {
         printf("\n\nCOMPUTER WINS !!!\n\n");
        printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\n");
        exit(1);
        } 
        else if (result==0&&count>8)
       { printf("\nMATCH DRAW\n\n");
       printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\n");
         exit(1);}
        else 
        continue;
    }
}

void game3()
{
    int count, a, arr[5];
    printf("\n\n\tWELCOME!!!!\n\tTHIS IS A PUZZLE GAME TO PLAY WITH YOUR FRIENDS\n\nRules:\nYou will get 5 different questions/puzzles to solve. Try to get as many correct answers and a PERFECT score.\n\tGOOD LUCK!!\n\n");
    for (count=0;count<5;count++)
    {
       
        a=rand_ques();
        for (int j=0;j<=count;j++)
        {
            if (arr[j]!=a&& j!=count)
            continue;
            else if (arr[j]!=a&& j==count)
            {arr[count]=a;
            printf("Question %d: ", count+1);
            ques(a, count);}
            else  {count--; break;}
        }
    }
}
void ques(int ques_no, int count)//game 3
{
    char result[20];
    int a;
    static int score=0;
    switch (ques_no)
    {
          
    case 1:  printf("What has to be broken before you can use it?\nHint: _ _ g\nYour Answer: ");
             scanf("%s", result);
             char answer[]="egg";
             printf("\nThe correct answer is: ");
             puts(answer);
             a=compare(result, answer);
             break;
    case 2:  printf("I'm tall when I'm young, and I'm short when I'm old. What am I?\nHint: c _ n d _ _\nYour Answer: ");
             scanf("%s", result);
             char answer2[]="candle";
             printf("\nThe correct answer is: ");
             puts(answer2);
             a=compare(result, answer2);
             break;
    case 3:  printf("What is full of holes but still holds water?\nHint: In your kitchen!!\nYour Answer: ");
             scanf("%s", result);
             char answer3[]="sponge";
             printf("\nThe correct answer is: ");
             puts(answer3);
             a=compare(result, answer3);
             break;
    case 4:  printf("What is always in front of you but can't be seen?\nHint: f _ t _ r _\nYour Answer: ");
             scanf("%s", result);
             char answer4[]="future";
             printf("\nThe correct answer is: ");
             puts(answer4);
             a=compare(result, answer4);
             break;
    case 5:  printf("I shave every day, but my beard stays the same. What am I?\nHint: b _ _ b e _\nYour Answer: ");
             scanf("%s", result);
             char answer5[]="barber";
             printf("\nThe correct answer is: ");
             puts(answer5);
             a=compare(result, answer5);
             break;
    case 6:  printf("I have branches, but no fruit, trunk or leaves. What am I?\nHint: b _ _ k\nYour Answer: ");
             scanf("%s", result);
             char answer6[]="bank";
             printf("\nThe correct answer is: ");
             puts(answer6);
             a=compare(result, answer6);
             break;
    case 7:  printf("The more of this there is, the less you see. What is it?\nHint: light\nYour Answer: ");
             scanf("%s", result);
             char answer7[]="darkness";
             printf("\nThe correct answer is: ");
             puts(answer7);
             a=compare(result, answer7);
             break;
    case 8:  printf("What has many keys but can't open a single lock?\nHint: Musical Instrument\nYour Answer: ");
             scanf("%s", result);
             char answer8[]="piano";
             printf("\nThe correct answer is: ");
             puts(answer8);
             a=compare(result, answer8);
             break;
    case 9:  printf("Where does today come before yesterday?\nHint: d _ _ t _ _ n a _ y\nYour Answer: ");
             scanf("%s", result);
             char answer9[]="dictionary";
             printf("\nThe correct answer is: ");
             puts(answer9);
             a=compare(result, answer9);
             break;
    case 10: printf("What invention lets you look right through a wall?\nHint: w _ n _ _ w\nYour Answer: ");
             scanf("%s", result);
             char answer10[]="window";
             printf("\nThe correct answer is: ");
             puts(answer10);
             a=compare(result, answer10);
             break;
    case 11: printf("What goes up and down but doesn't move?\nHint: s _ _ i r c _ _ e\nYour Answer: ");
             scanf("%s", result);
             char answer11[]="staircase";
             printf("\nThe correct answer is: ");
             puts(answer11);
             a=compare(result, answer11);
             break;
    case 12: printf("If you're running in a race and you pass the person in second place, what place are you in?\nHint: READ AGAIN IT'S EASY!!\nYour Answer: ");
             scanf("%s", result);
             char answer12[]="second";
             printf("\nThe correct answer is: ");
             puts(answer12);
             a=compare(result, answer12);
             break;
    case 13: printf("What has one eye, but can't see?\nHint: n _ _ d l _\nYour Answer: ");
             scanf("%s", result);
             char answer13[]="needle";
             printf("\nThe correct answer is: ");
             puts(answer13);
             a=compare(result, answer13);
             break;
    case 14: printf("What has hands, but can't clap?\nHint: time\nYour Answer: ");
             scanf("%s", result);
             char answer14[]="clock";
             printf("\nThe correct answer is: ");
             puts(answer14);
             a=compare(result, answer14);
             break;
    case 15: printf("What has legs, but doesn't walk?\nHint: t _ _ _ _\nYour Answer: ");
             scanf("%s", result);
             char answer15[]="table";
             printf("\nThe correct answer is: ");
             puts(answer15);
             a=compare(result, answer15);
             break;
    case 16: printf("What kind of band never plays music?\nHint: r u _ _ e _ _ a n d\nYour Answer: ");
             scanf("%s", result);
             char answer16[]="rubberband";
             printf("\nThe correct answer is: ");
             puts(answer16);
             a=compare(result, answer16);
             break;
    case 17: printf("What has a head and a tail but no body?\nHint: heads or tails\nYour Answer: ");
             scanf("%s", result);
             char answer17[]="coin";
             printf("\nThe correct answer is: ");
             puts(answer17);
             a=compare(result, answer17);
             break;
    case 18: printf("What has four wheels and flies?\nHint: d _ m _   t _ _ c _ \nYour Answer: ");
             char result2[10], answer18[]="dumptruck", a2[]="dump truck";
             scanf("%s %s", result, result2);
             strcat(result,result2);
             printf("\nThe correct answer is: ");
             puts(a2);
             a=compare(result, answer18);
             break;
    case 19: printf("What five-letter word becomes shorter when you add two letters to it?\nHint: short-er\nYour Answer: ");
             scanf("%s", result);
             char answer19[]="short";
             printf("\nThe correct answer is: ");
             puts(answer19);
             a=compare(result, answer19);
             break;
    case 20: printf("Two in a corner, one in a room, zero in a house, but one in a shelter. What is it?\nHint: a letter\nYour Answer: ");
             scanf("%s", result);
             char answer20[]="r";
             printf("\nThe correct answer is: ");
             puts(answer20);
             a=compare(result, answer20);
             break;
    default:
            break;
    }
    if (a==1)
    {score+=100;
    printf("\nYOUR ANSWER IS CORRECT.\n\n");
    printf("CURRENT SCORE = %d\n", score);}
    else printf("\nWRONG ANSWER\n\tCURRENT SCORE = %d\n", score); 
    if (count==4&& score==500)
    printf("\n\tCONGRATULATIONS!!\n\tYOU WIN\n ");
    else if (count==4&& score!=500)
    printf("\n\tWE HOPE YOU GET BETTER SCORE NEXT TIME\n");
}    
void game4()
{
    int num, a, horse_no[20],b;
    static int  player1[20];
    int *p;
    printf("\n\n\tWELCOME TO OUR HORSE RACING EVENT!!!\n");
   
    printf("\nRULES: The game is very simple. Each player chose one horse and enters the race. After first round, half of the players are selected for round 2 which select the horses again and this goes on until only winner is left.\n\tHAVE FUN!!\n");
    printf("Please enter the number of players who would like to play : ");
    scanf("%d", &num);
    b=num;
    p=(int*)calloc(num, sizeof(int));
    for (int i=0; i<num;i++)
    {
        printf("Chose your horse player %d (from 1-%d)= ", i+1, num);
        scanf("%d", p+i);
        if (*(p+i)>num)
               {printf("\nINVALID!!\nENTER AGAIN\n");
               i--;}
               else continue;
    }
    while (num!=1)
    {
     if (num!=b)
     {
           for (int i=0; i<num;i++)
           {
               printf("\nChose your horse player %d (from 1 - %d)=  ",player1[i], num);
               scanf("%d", p+i);
               if (*(p+i)>num)
               {printf("\nINVALID!!\nENTER AGAIN\n");
               i--;}
               else continue;
           }
     }
     else goto after;
    after:
    if (num<=3)
    {
        printf("\n\t\aTHE WINNER IS : ");
    }
    else
    printf("The qualifiers are : ");
    again:
    for (int i=0; i<(num/2);i++)
    {
        a=qualifiers(num);
        for (int j=0;j<=i;j++)
        {
            if (horse_no[j]!=a&& j!=i)
            continue;
            else if (horse_no[j]!=a&& j==i)
            horse_no[i]=a;
            else 
            i--;
        }
    }
    for (int i=0;i<num/2;i++)
    {
        for (int j=0; j<num;j++)
        {
            if (*(p+j)==horse_no[i])
            {
                if (num==b)
                {
                    player1[i]=j+1;
                    if (player1[0]==player1[1])
                    goto again;
                    else
                    printf("PLAYER %d ", j+1);
                    
                }
                else if (num!=b)
                {
                    printf("PLAYER %d ", player1[j]);
                    player1[i]=player1[j];
                }
            }    
        }
    }
    
    num/=2;
    }
    free(p);
}