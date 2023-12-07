#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Key Generation
char* key_check(char *);

// Conversion of PlainText into Ciphertext
char* process_cipher(char *, char *);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Invalid arguments, try again\n");                              //Pass the key in the coomand line. Else program will exit
        return 1;
    }
    else
    {
        char *key = key_check(argv[1]);                                        //Calls function key_check to generate the user defined KEY
        char input[100];                                       
        printf("Enter plaintext:\n");                                          // Enter your message that you want to be encrypted
        scanf("%s", input);
        process_cipher(input, key);                                            //Calls process_cipher to convert user message to ciphertext

        return 0;
    }
    
}

char* key_check(char *key)
{
    int length = strlen(key);                                  
    if (length != 26)                                                          //Key must be contain all letters of the English alphabet
    {
        printf("Please pass the full key\n");
        exit(1);
    }

    char charset[256] = {0};

    for (int i = 0; i < length; i++)
    {
        int charvalue = (int)key[i];
        if(!isalpha(charvalue))                                                // Only English alphabets are allowed
        {
            printf("Enter characters only",key[i]);  
            free(key);
            exit(1);
        }
        if (charset[charvalue] == 1)                                           // All characters entered in the key must be unique
        {
            printf("Invalid argument, please try again\n");
            exit(1);
        }
        charset[charvalue] = 1;                                                // If unique alphabet found, pass it to the key
    }

    printf("Key: %s\n", key);
    return key;
}

char* process_cipher(char *input, char *key)
{
    int text_length = strlen(input); 
    char *ciphertext = (char*)malloc(text_length + 1);                         //Encrypted text declaration
    int index = 0;                                                             //This variable (index) will be used to map Plaintext to the Key

    for (int i = 0; i < text_length; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')                           
        {
            index = (input[i] - 'A');
            ciphertext[i] = key[index];                                        // Maps and substitutes user message with the key for capital letters
            ciphertext[i] = toupper(ciphertext[i]);
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            index = input[i] - 'a';
            ciphertext[i] = key[index];                                        // Maps and substitutes user message with the key for small letters
            ciphertext[i]= tolower(ciphertext[i]);
        }
        else
        {
            ciphertext[i] = input[i];                                          // Other symbols in plaintext will not be affected
        }
    }

    ciphertext[text_length] = '\0';
    printf("Ciphered text: %s\n", ciphertext);                                 // Displays Ciphertext
    return NULL;
}