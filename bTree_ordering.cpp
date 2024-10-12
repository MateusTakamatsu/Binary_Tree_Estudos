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

// Define the order functions
void preorder_traversal(struct Node* root) {
    if(root) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(struct Node* root) {
    if(root) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(struct Node* root) {
    if(root) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

void reverseorder_traversal(struct Node* root) {
    if(root) {
        reverseorder_traversal(root->right);
        printf("%d ", root->data);
        reverseorder_traversal(root->left);
    }
}

// Main
int main() {
    // Declare the necessary variables
    int i;
    int array[15] = { 34, 84, 15, 0, 2, 99, 79, 9, 88, 89, 18, 31, 39, 100, 101 };
    int elementToSearch;
    Node *root = NULL;

    // Insert function
    for(i = 0; i < 15; i++) {
        root = insert(root, array[i]);
        printf("Inserted: %d\n", array[i]);
    }

    // The four order functions
    printf("\nPre-order traversal: ");
    preorder_traversal(root);
    printf("\nIn-order traversal: ");
    inorder_traversal(root);
    printf("\nPost-order traversal: ");
    postorder_traversal(root);
    printf("\nReverse-order traversal: ");
    reverseorder_traversal(root);
    printf("\n");

    return 0;
}
