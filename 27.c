#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* getIntersectionNode(struct Node *head1, struct Node *head2) {
    int len1 = 0, len2 = 0;

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    while (p1) {
        len1++;
        p1 = p1->next;
    }

    while (p2) {
        len2++;
        p2 = p2->next;
    }

    p1 = head1;
    p2 = head2;

    int diff;

    if (len1 > len2) {
        diff = len1 - len2;
        while (diff--)
            p1 = p1->next;
    } else {
        diff = len2 - len1;
        while (diff--)
            p2 = p2->next;
    }

    while (p1 && p2) {
        if (p1 == p2)
            return p1;

        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    int b[m];

    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int i = n - 1;
    int j = m - 1;
    int common = 0;

    while (i >= 0 && j >= 0 && a[i] == b[j]) {
        common++;
        i--;
        j--;
    }

    struct Node *sharedHead = NULL;

    for (i = n - common; i < n; i++) {
        struct Node *temp = newNode(a[i]);

        if (sharedHead == NULL) {
            sharedHead = temp;
        } else {
            struct Node *p = sharedHead;
            while (p->next)
                p = p->next;
            p->next = temp;
        }
    }

    struct Node *head1 = NULL, *tail1 = NULL;

    for (i = 0; i < n - common; i++) {
        struct Node *temp = newNode(a[i]);

        if (head1 == NULL)
            head1 = tail1 = temp;
        else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    if (tail1)
        tail1->next = sharedHead;
    else
        head1 = sharedHead;

    struct Node *head2 = NULL, *tail2 = NULL;

    for (i = 0; i < m - common; i++) {
        struct Node *temp = newNode(b[i]);

        if (head2 == NULL)
            head2 = tail2 = temp;
        else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    if (tail2)
        tail2->next = sharedHead;
    else
        head2 = sharedHead;

    struct Node *result = getIntersectionNode(head1, head2);

    if (result)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}