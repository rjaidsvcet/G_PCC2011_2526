#include <stdio.h>
#include <stdlib.h>

// Structure of BST Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

// Create New Node
struct Node* createNode(int x) {
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

// Insert into BST
struct Node* insert(struct Node *p, int x) {
    if (p == NULL)
        return createNode(x);

    if (x < p->data)
        p->left = insert(p->left, x);
    else if (x > p->data)
        p->right = insert(p->right, x);

    return p;
}

// Preorder Traversal (Root Left Right)
void preorder(struct Node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

// Inorder Traversal (Left Root Right)
void inorder(struct Node *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

// Postorder Traversal (Left Right Root)
void postorder(struct Node *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

// Main Function
int main() {
    int n, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}