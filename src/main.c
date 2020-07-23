#define WASM_EXPORT __attribute__((visibility("default")))

#include "./cs50.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

bool can_reach_from_to(int from_node, int to_node);

WASM_EXPORT
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // look for candidate called "name"
    // if candidate found, update ranks and return true
    // ranks[i] is voters's i-th preference
    // e.g. rank[0] is voter's 1st preference = top choice
    // if no candidate found, don't update any ranks and return false

    bool vote_recorded = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            vote_recorded = true;
        }
    }

    return vote_recorded;

}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // update preferences array based on current voter's ranks
    // e.g. ranks = [3, 0, 4, 1, 2] = the order of candidates by id
    // record how many people prefered once candidate over another candidate
    // e.g. 3 is prefered over 0, 4, 1, 2
    // 0 is prefered over 4, 1, 2
    // etc.
    // preferences[i][j] is number of voters who prefer i over j
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
            // suppose ranks = [3, 0, 4, 1, 2]
            // iteration 1: takes candidate at ranks[0] and candidate at ranks[1] -> preferences[3][0]++
            // iteration 2: takes candidate at ranks[0] and candidate at ranks[2] -> preferences[3][4]++
            // iteration 3: takes candidate at ranks[0] and candidate at ranks[3] -> preferences[3][1]++
            // iteration 4: takes candidate at ranks[0] and candidate at ranks[4] -> preferences[3][2]++

            // iteration 4: takes candidate at ranks[1] and candidate at ranks[2] -> preferences[0][4]++
            // iteration 5: takes candidate at ranks[1] and candidate at ranks[3] -> preferences[0][1]++
            // iteration 6: takes candidate at ranks[1] and candidate at ranks[4] -> preferences[0][2]++

            // iteration 7: takes candidate at ranks[2] and candidate at ranks[3] -> preferences[4][1]++
            // iteration 8: takes candidate at ranks[2] and candidate at ranks[4] -> preferences[4][2]++

            // iteration 9: takes candidate at ranks[3] and candidate at ranks[4] -> preferences[1][2]++

        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // add each pair of candidates to pairs array if one candidate is prefered over the other
    // if tied, don't add to pairs array
    // update global variable pair_count to be the total number of pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int strength = preferences[i][j] - preferences[j][i];
            if (strength > 0)
            {
                pairs[pair_count] = (pair)
                {
                    .winner = i, .loser = j
                };
                pair_count++;
            }
            else
            {
                // tie => no pair recorded
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // selection sort should be fine for our purposes here
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int a = 0; a < MAX; a++)
    {
        for (int b = 0; b < MAX; b++)
        {
            locked[a][b] = false;
        }
    }


    for (int i = 0; i < pair_count; i++)
    {

        bool can_reach = can_reach_from_to(pairs[i].loser, pairs[i].winner);

        if (!can_reach)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
        else
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }

    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // printf("%s\n", candidates[pairs[0].winner]);
    bool has_incoming_nodes[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        has_incoming_nodes[i] = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            has_incoming_nodes[i] += locked[j][i];
        }
        if (has_incoming_nodes[i] == 0)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}



bool can_reach_from_to(int from_node, int to_node)
{
    bool can_reach = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[from_node][i])
        {
            if (i == to_node)
            {
                can_reach = true;
            }
            else
            {
                if (can_reach_from_to(i, to_node)) // recursion
                {
                    can_reach = true;
                }
            }
        }
    }
    return can_reach;
}