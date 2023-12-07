#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);

int main(void)
{
    // Get input words from both players
    char word1[100];  
    char word2[100];
    printf("Player 1 enter your scrabble \n");
    scanf("%s", word1);
    printf("Player 2 enter your scrabble \n");

    scanf("%s", word2);

    for(int k=0;k<strlen(word1);k++){
    word1[k] = toupper(word1[k]);
    }
    for(int k=0;k<strlen(word2);k++){
    word2[k] = toupper(word2[k]);
    }

    // Score both words
    printf("\nLets scrabble 😜 \n \n");
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1>score2)
    printf("The winner is Player 1 : %s", word1);
    else if(score1<score2)
    printf("The winner is Playeer 2 : %s", word2);
    else
    printf("Draw");
}

int compute_score(char* word)
{
    int score =0;
    int length = strlen(word);
    for(int i=0;i<length;i++)
    {
        if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U' || word[i]=='L' || word[i]=='N' || word[i]=='R' || word[i]=='S' || word[i]=='T')
        score+=1;
        else if(word[i]=='B' || word[i]=='C' || word[i]=='M' || word[i]=='P')
        score+=3;
        else if(word[i]=='D' || word[i]=='G')
        score+=2;
        else if(word[i]=='F'|| word[i]=='H'|| word[i]=='V'|| word[i]=='W' || word[i]=='Y')
        score+=4;
        else if(word[i]=='K')
        score+=5;
        else if(word[i]=='J' || word[i]=='X')
        score+=8;
        else if(word[i]=='Q' || word[i]=='Z')
        score+=10;
        else return 0;
    }
        return score;
    }
