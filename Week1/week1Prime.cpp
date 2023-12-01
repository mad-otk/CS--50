
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
    while (min < 1);

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
    for(int i=0;i<(sqrt(number)+2);i++)
    {
        if(number%i==0)
            return false;
    }
    return true;
}

