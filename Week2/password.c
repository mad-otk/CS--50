#include <stdio.h>
#include<stdbool.h>
#include<string.h>
// User provides a password. It must contain atleast 1 Uppercase letter, 1 Lowercase letter, 1 number and 1 special symbol
bool valid(char* password);

int main(void)
{   
    char password[100];                                                           
    printf("Enter your password: \n");
    scanf("%s", password);                                                 // Take user input as passwprd
    if (valid(password))                                                   // Call function valid to verify the password
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(char* password)
{   
    int symbols=0,caps=0,numbers=0,smallcaps=0;                       // These variables will keep track of the requirements
    int length = strlen(password);

    // This for-loop contains the logic for the password requirement. Variables smallcaps, caps, numbers and symbols will increase by 1
    // each time the for loops finds the respective elements in the password while checking.
    // If all the above mentioned variables contain non-zero value, the password will seem to be valid. Otherwise not
    for(int j=0;j<length;j++)
    {
        if((password[j]>=33 && password[j]<=47) || (password[j]>=58 && password[j]<=64) || (password[j]>=91 && password[j]<=96) || (password[j]>=58 && password[j]<=64) ||(password[j]>=123 && password[j]<=127))
        symbols++;
        else if(password[j]>=48 && password[j]<=57)
        numbers++;
        else if(password[j]>=65 && password[j]<=90)                                            
        caps++;
        else if(password[j]>=97 && password[j]<=122)
        smallcaps++;
    }
    printf("%d, %d, %d, %d", symbols,numbers, caps, smallcaps);
    if(smallcaps > 0 && caps > 0 && numbers > 0 && symbols > 0)
    return true;
    return false;
    // if(smallcaps > 0 || caps > 0 || numbers > 0 || symbols > 0)
    // return false;

    
}