// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // WEEK 1 : Lama Population 

    int start_size;
    int end_size;
    int born=0,dead=0,years=0;

    do{
    printf("Enter starting population \n");
    scanf("%d", &start_size);
    printf("Enter target population \n");                                 // Opting out invalid entries
    scanf("%d", &end_size);                                               // Repeatedly asking for valid entries
    }while(start_size<=3 || (start_size>end_size));
    
    while(start_size<end_size)
    {   
        born = start_size/3;
        dead  = start_size/4;
        start_size = start_size + born - dead;                           // Logic for the popuation expansion
        ++years;
    }
    printf("Years needed to reach target population = %d", years);       // Displays result
    return 0;                                                        
}