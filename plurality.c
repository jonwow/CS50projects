// SAMPLE INPUT:
// ./plurality Alice Bob
// 3
// Alice
// Alice
// Bob
// EXPECTED OUTPUT:
// Alice


#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;


// Max number of candidates. any variable named MAX will be 9 no matter what after this line.
#define MAX 9

// Number of candidates
int candidate_count;

// Array of candidates
candidate candidates[MAX];


// Function prototypes
bool vote(string name);
void print_winner(void);




int main(int argc, string argv[])
{
    ////////////////////// TESTS (and populating array of candidates)
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
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    //////////////////////// END OF TESTS

    
    // Put the candidate names and set vote counts to 0 in the 'candidates' array.
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");


    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote. If 'vote' function detects no matches, it returns false and this 'if' block gets triggered.
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}


// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // if 'strcmp' is false (if both strings are IDENTICAL), add a vote to a candidate
        if (!strcmp(name, candidates[i].name))
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int largestAmount = -1,
        index[MAX] = {-1}, z = 0;

    bool tie = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == largestAmount)
        {
            tie = true;
            index[z] = i;

            z++;
        }


        if (candidates[i].votes > largestAmount)
        {
            tie = false;
            z = 0;

            largestAmount = candidates[i].votes;

            index[z] = i;
            z++;
        }
    }

    if (tie)
    {
        for (int i = 0; i < z; i++)
        {
            printf("%s\n", candidates[index[i]].name);
        }
    }
    else
    {
        printf("%s\n", candidates[index[0]].name);
    }

    return;
}
