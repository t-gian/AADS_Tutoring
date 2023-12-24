#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int key;
    struct node** children;
    int numChildren;
}node_t;


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void displayRec(node_t* root, int depth) {
    if (root == NULL)
        return;
    printf("%d ", root->key);
    qsort(root->children, root->numChildren, sizeof(node_t*), compare);

    for (int i = 0; i < root->numChildren; i++) {
        if (root->children[i] != NULL)
            printf("%d ", root->children[i]->key);
    }

    for (int i = 0; i < root->numChildren; i++) {
        displayRec(root->children[i], depth + 1);
    }
}

void display(node_t* root) {
    if (root == NULL)
        return;
    printf("%d ", root->key);
    qsort(root->children, root->numChildren, sizeof(node_t*), compare);

    for (int i = 0; i < root->numChildren; i++) {
        if (root->children[i] != NULL)
            printf("%d ", root->children[i]->key);
    }
    for (int i = 0; i < root->numChildren; i++) {
        displayRec(root->children[i], 2);
    }
}
