#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[100];
    int votes;
};

int main() {
    int n;
    scanf("%d", &n);

    char names[n][100];
    struct Candidate candidates[n];
    int count = 0;

    // Read all votes
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Count votes for each unique candidate
    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < count; j++) {
            if (strcmp(names[i], candidates[j].name) == 0) {
                candidates[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(candidates[count].name, names[i]);
            candidates[count].votes = 1;
            count++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[100];

    for (int i = 0; i < count; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        }
        else if (candidates[i].votes == maxVotes &&
                 strcmp(candidates[i].name, winner) < 0) {
            strcpy(winner, candidates[i].name);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}