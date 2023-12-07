#include<stdbool.h>
#include <stdio.h>
#include<math.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        printf("Minimum: \n");
        scanf("%d", &min);
    }
    while (min <= 1);

    int max;
    do
    {
        printf("Maximum: \n");
        scanf("%d", &max);
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    if(number==2)
    return true;
    for(int j=2;j<(sqrt(number)+1);j++)
    {   
        if(number%j==0){
            return false;
        }
    }
    return true;
}
