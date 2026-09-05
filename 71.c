#include <stdio.h>
#include <string.h>

#define MAX 1000

int table[MAX];
int m;

int hashFunction(int key) {
    return key % m;
}

void insert(int key) {
    int h = hashFunction(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }
}

int search(int key) {
    int h = hashFunction(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            return 0;
        }

        if (table[index] == key) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &m);
    scanf("%d", &n);

    // Initialize hash table
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }

    char operation[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(key);
        }
        else if (strcmp(operation, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}