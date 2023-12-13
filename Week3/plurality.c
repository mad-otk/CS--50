#include <stdio.h>
#include <string.h>
#include<stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char name[20];
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char *name);
void print_winner(const candidate candidates[], int);

int main(int argc, char **argv)
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i \n", MAX);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        strncpy(candidates[i].name,argv[i+1], sizeof(candidates[i].name)-1);
        candidates[i].name[sizeof(candidates[i].name)] = '\0';
        candidates[i].votes = 0;
    }

    int voter_count = printf("Number of voters : \n");
    
    if ((scanf("%d", &voter_count) != 1) ||  voter_count <= 0)
    {
        printf("Invalid input for the number of voters.\n");
        return 3;
    }
    printf("Vote: \n");
    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char* name;
        scanf("%49s", name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner(candidates, voter_count);
}

// Update vote totals given a new vote
bool vote(char *name)
{
for(int i=0;i<candidate_count;i++)
{
    if(strcmp(name,candidates[i].name)==0)
    {
        candidates[i].votes += 1;
        return true;
    }
}
    
    return false;
}

// Print the winner (or winners) of the election
void print_winner(const candidate candidates[], int votercount)
{
    int winner = 0,max_now=0;
    for(int i=0; i<votercount;i++)
    {
        if((candidates[i].votes) > max_now)
        {
            max_now = candidates[i].votes;
        }
    }

    printf("Winners :\n");

    for(int j =0; j<votercount;j++)
    {
        if(candidates[j].votes==max_now)
        printf("%s \n", candidates[j].name);

    }

    return;
}
// max_now = candidates[i].votes;