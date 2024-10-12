#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Define fuctions insert and search
Node* insert(Node *root, int data) {
    Node *temp = (Node*) malloc(sizeof(Node)); // Use calloc instead to avoid A and B
    temp->data = data;
    temp->left = NULL; // {A}
    temp->right = NULL; // {B}
    if(root == NULL) {
        root = temp;
    } else {
        Node *current = root;
        Node *parent = NULL;
        while (1) {
            parent = current;
            if (data < parent->data) {
                current = current->left;
                
                if(current == NULL) {
                    parent->left = temp;
                    return root;
                }
            } else {
                current = current->right;
                if(current == NULL) {
                    parent->right = temp;
                    return root;
                }
            }
        }
    }
    return root;
}

int search(Node *root, int data) {
    Node *current = root;
    int i = 0;
    printf("\nVisiting nodes in the tree: ");
    while(current) {
        i++;
        printf("%d ", current->data);
        if(data < current->data) {
            current = current->left;
        } else if(data > current->data) {
            current = current->right;
        } else {
            return i;
        }
    }
    return 0;
}

int simpleSearch(int *array, int element) {
    int arrayComps = 0;
    int i = 0;
    printf("\nVisiting elements in array: ");
    for(i = 0; i < 15; i++) {
        arrayComps++;
        printf("%d ", array[i]);
        if(array[i] == element) {
            break;
        }
    }
    return arrayComps;
}

// Main
int main() {
    // Declare the necessary variables
    int i;
    int array[15] = { 34, 84, 15, 0, 2, 99, 79, 9, 88, 89, 18, 31, 39, 100, 101 };
    int numberToSearch;
    Node *root = NULL;

    // Insert function
    printf("\nThe elements are: ");
    for(i = 0; i < 15; i++) {
        root = insert(root, array[i]);
        printf("%d ", array[i]);
    }

    // Search fuction
    printf("\n\nWhich tree element do you want to search?\n");
    scanf("%d", &numberToSearch);

    // bTree search
    int comps = search(root, numberToSearch);
    if(comps) {
        printf("\n>>> [%d] found in %d comparisons <<<\n", numberToSearch, comps);
    } else {
        printf("\nXXX [%d] not found XXX\n", numberToSearch);
    }

    // Array search
    int arrayComps = simpleSearch(array, numberToSearch);
    if(comps) {
        printf("\n>>> [%d] found in %d comparisons <<<\n", numberToSearch, arrayComps);
    } else {
        printf("\nXXX [%d] not found XXX\n", numberToSearch);
    }

    if(comps) {
        printf("\nWith Binary Search Tree, you skipped [%d] comparisons\n", (arrayComps - comps));
    }

    return 0;
}
