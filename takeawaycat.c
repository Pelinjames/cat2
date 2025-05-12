#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void compareBinaryTree(struct Node* root1, struct Node* root2, struct Node* root3) {
    int count1 = countNodes(root1);
    int count2 = countNodes(root2);
    int count3 = countNodes(root3);

    printf("Tree 1 has %d nodes.\n", count1);
    printf("Tree 2 has %d nodes.\n", count2);
    printf("Tree 3 has %d nodes.\n", count3);

    if (count1 >= count2 && count1 >= count3)
        printf("Tree 1 has the highest number of nodes.\n");
    else if (count2 >= count1 && count2 >= count3)
        printf("Tree 2 has the highest number of nodes.\n");
    else
        printf("Tree 3 has the highest number of nodes.\n");
}

int main() {
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    struct Node* root2 = createNode(10);
    root2->left = createNode(20);
    root2->right = createNode(30);
    root2->left->left = createNode(40);

    struct Node* root3 = createNode(5);
    root3->left = createNode(6);

    compareBinaryTree(root1, root2, root3);

    return 0;
}
//output
//Tree 1 has 3 nodes.
//Tree 2 has 4 nodes.
//Tree 3 has 2 nodes.
//Tree 2 has the highest number of nodes.
