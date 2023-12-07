#include <ctype.h>
#include <stdio.h>

float calc_hours(float time_given, int weeks, char output);            // Function to calculate total and average hours per week
                                                                     
int main(void)
{   
    int weeks;
    printf("Number of weeks taking CS50: ");                         // Takes the number of weeks the user has spent on CS50 course 
    do
    {
    scanf("%d", &weeks);

    } while (weeks<1);
    
    int hours[weeks];                                                
    int time_given=0.0;

    for (int i = 0; i < weeks; i++)
    {
        printf("Week %i HW Hours: ",i);
        scanf("%d", &hours[i]);                                       // Stores the amount of hours the user has given each week
       
        time_given += hours[i];
    }
  
    char output;
    do
    {
        printf("Enter T for total hours, A for average hours per week: ");
        scanf("%c", &output);                                                       // Converts lower string to upper string character for total and average hours spent   
        output = toupper(output);                                                   // Only 't','T' for toals hours and 'a',"a" for average hours are valid 
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(time_given, weeks, output));           // Calls "calc_hours" function
}

// TODO: complete the calc_hours function
float calc_hours(float time_given, int weeks, char output)                      // Function to find out total and average hours spent
{
  if(output == 'T')
  return time_given;                                                         // An input 't' or 'T' yields total hours spent
  else
  return time_given/weeks;                                                   // An input 'a' or 'A' yields average hours spent per week
}