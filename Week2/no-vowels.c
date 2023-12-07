#include <stdio.h>
#include<string.h>
#include<stdlib.h>

// Replaces vowels with given symbols
char* replace(char* input);

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        printf("Invalid arguments, try again\n");                                          // Checks for invalid Command Line Arguments
        return 1;
    }
    else
    {
        char* output = replace(argv[1]);                                                   // Calls replace() to replace the vowels
        printf("%s\n", output);
        free(output);

    }
    return 0;
}
    

char* replace(char* input)
{   
    
    int length = strlen(input);
    char* result = malloc(length+1);                                         
    for(int i=0;i<length;i++)
    {
        if(input[i]=='a' || input[i]== 'A')
        result[i] = '6';
        else if(input[i]=='e' || input[i]== 'E')
        result[i] = '3';                                                                    // Approach to the problem Logic
        else if(input[i]=='i' || input[i]== 'I')
        result[i] = '1';
        else if(input[i]=='o' || input[i]== 'O')
        result[i] = '0';
        else 
        result[i] = input[i]; 
    }
    result[length]='\0';                                                                    // Display result
    return result;
}
    