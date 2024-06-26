#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Print(int n1,int n2,int n3){
    int count=111;
    if(n3!=0) printf("\n\t\t\t\t\tDICE = %d\n\n",n3);
    for(int i=0;i<10;i++){
        if(i%2==0){
            count=count-11;
            for(int j=0;j<10;j++){
                if(count==n1) printf("$P1$   ");
                else if(count==n2) printf("$P2$   ");
                else if(count==25||count==65||count==99) printf("*S*    ");
                else if(count==13||count==60||count==70) printf("*L*    ");
                else printf("%-7d",count);
                if(j==9) printf("\n");
                count--;
            }
        }
        else{
            count=count-9;
            for(int j=0;j<10;j++){
                if(count==n1) printf("$P1$   ");
                else if(count==n2) printf("$P2$   ");
                else if(count==25||count==65||count==99) printf("*S*    ");
                else if(count==13||count==60||count==70) printf("*L*    ");
                else printf("%-7d",count);
                if(j==9) printf("\n");
                count++;
            }
        }
    }
    printf("\n");
    for(int i=0;i<65;i++) printf("-");
    printf("\nSnakes:- 25 to 9\t65 to 40\t99 to 1.\nLadder:- 13 to 42\t60 to 83\t70 to 93.\n\n\n");
}

int Check(int n){
    if(n==25){
        printf("\n\t\t\t*Oh no! a Snake*\n");
        return 9;
    }
    if(n==65){
        printf("\n\t\t\t*Oh no! a Snake*\n");
        return 40;
    } 
    if(n==99){
        printf("\n\t\t\t*Oh no! a Snake*\n");
        return 1;
    }
    if(n==13){
        printf("\n\t\t\t*Oh Yes! a Ladder*\n");
        return 42;
    }
    if(n==60){
        printf("\n\t\t\t*Oh Yes! a Ladder*\n");
        return 83;
    }
    if(n==70){
        printf("\n\t\t\t*Oh Yes! a Ladder*\n");
        return 93;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int choice,r1,r2,p1=0,p2=0;
    char ch;
    printf("\t\t\t**SNAKES AND LADDER GAME**\n\n");
    Print(0,0,0);
    while(1){
        printf("\nPress 1 to start the Game\nPress 2 to exit.\n");
        scanf("%d",&choice);
        if(choice==2) break;
        if(choice==1){
            while(1){
                printf("Player 1 press any character roll the dice. ");
                scanf(" %c",&ch);
                while(1){
                    r1=rand()%7;
                    if(r1==0) continue;
                    else break;
                }
                p1+=r1;
                p1=Check(p1);
                Print(p1,p2,r1);
                if(p1==100){
                    printf("\n\t\t'PLAYER1 WON!!!'\n");
                    break;
                }
                if(r1==6){
                    printf("Player 1 press any character roll the dice. ");
                    scanf(" %c",&ch);
                    while(1){
                        r1=rand()%7;
                        if(r1==0) continue;
                        else break;
                    }
                    p1+=r1;
                    p1=Check(p1);
                    Print(p1,p2,r1);
                    if(p1==100){
                        printf("\n\t\t'PLAYER1 WON!!!'\n");
                        break;
                    }
                }
                printf("Player 2 press any character roll the dice. ");
                scanf(" %c",&ch);
                while(1){
                    r2=rand()%7;
                    if(r2==0) continue;
                    else break;
                }
                p2+=r2;
                p2=Check(p2);
                Print(p1,p2,r2);
                if(p2==100){
                    printf("\n\t\t'PLAYER2 WON!!!'\n");
                    break;
                }
                if(r2==6){
                    printf("Player 2 press any character roll the dice. ");
                    scanf(" %c",&ch);
                    while(1){
                        r2=rand()%7;
                        if(r2==0) continue;
                        else break;
                    }
                    p2+=r2;
                    p2=Check(p2);
                    Print(p1,p2,r2);
                    if(p2==100){
                        printf("\n\t\t'PLAYER2 WON!!!'\n");
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
