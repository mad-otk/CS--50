#include <stdio.h>

float half(float bill, float tax, float tip);

int main(void)
{
    float bill=0.0,tax=0.0,tip=0.0;
    printf("Enter bill before tax and tip \n ");
    scanf("%f", &bill);
    printf("Sale Tax percent\n");
    scanf("%f", &tax);
    printf("Tax percentage : \n ");
    scanf("%f", &tip);
    printf("You will owe $%.2f each!\n", half(bill, tax, tip));
}

// TODO: Complete the function
float half(float bill, float tax, float tip)
{
    float sub_total = bill + 0.01*tax*bill;
    float total = sub_total + 0.01*sub_total*tip;
    return total/2;
}