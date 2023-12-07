#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

char* para(char *);
void calculate_CL_index(char *, int);

int main() {

    printf("Enter a paragraph \n");
    char *paragraph = NULL;
    paragraph = para(paragraph);

    int length = strlen(paragraph);

    calculate_CL_index(paragraph, length);

    free(paragraph);
    return 0;
}

char* para(char* paragraph) {
    
    size_t buffer_size = 100;
    paragraph = (char *)malloc(buffer_size * sizeof(char));

    if (paragraph == NULL) {
        return NULL;
    }

    ssize_t bytesRead;
    bytesRead = getline(&paragraph, &buffer_size, stdin);

    if (bytesRead == -1) {
        free(paragraph);
        return NULL;
    }
    printf("%s \n", paragraph);
    return paragraph;
}


void calculate_CL_index(char *paragraph, int length)
{
    int letter_count = 0, word_count=0,sentence_count=0;
    for(int i=0;i<length;i++)
    {
        if ((paragraph[i]>=65 && paragraph[i]<=90) || (paragraph[i]>=97 && paragraph[i]<=122))
            letter_count+=1;
        if (paragraph[i] == ' ')
            word_count+=1;
        if (paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!' )
            sentence_count+=1;
    }
    word_count++;
    printf("Letter count = %d \n", letter_count);
    printf("Word count = %d \n", word_count);
    printf("Sentence count = %d \n", sentence_count);
    
    float L = (float)letter_count/word_count * 100;
    float S = (float)sentence_count/word_count * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int CLindex = round(index);

    if(CLindex<1)
    printf("Before Grade 1 \n");
    else if(CLindex>16)
    printf("Grade 16+ ");
    else
    printf("Grade %d \n", CLindex);
    return;
}