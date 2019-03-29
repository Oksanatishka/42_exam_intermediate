/*
CONVERT_BST
Assignment name  : convert_bst
Expected files   : convert_bst.c
Allowed functions: 
--------------------------------------------------------------------------------
A binary search tree (BST) is a binary tree in which every node fits
a specific ordering property :
all left descendants <= n < all right descendants
This must be true for each node n.
Implement a function to convert a binary search tree to a sorted, circular,
doubly-linked list.
This conversion must be in-place (using the tree nodes as the new list nodes).
The binary search tree uses the following node structure :
    struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };
The function must be declared as follows:
    struct s_node *convert_bst(struct s_node *bst);
The function must return a pointer to the smallest element of the sorted,
circular, doubly-linked list.
For each node of the linked list, the right pointer points to the next node
and the left pointer points to the previous node.
The sort is in increasing order.
*/


typedef struct s_node
{
    int value;
    struct s_node *right;
    struct s_node *left;
} Node;

Node *recurse(Node *root)
{
    if (!root)
        return 0;

    // Recursively convert left subtree
    if (root->left)
    {
        Node *left = recurse(root->left);
        while (left->right)
            left = left->right;
        left->right = root;
        root->left = left;
    }
    // Recursively convert right subtree
    if (root->right)
    {
        Node *right = recurse(root->right);
        while (right->left)
            right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
}

Node *convert_bst(Node *bst)
{
    if (!bst)
        return 0;
    recurse(bst);

    // A code that appends rightList at the end of leftList:
    Node *leftList = bst;
    Node *rightList = bst;
    // Store the last Node of left List
    while (leftList->left)
        leftList = leftList->left;
    // Store the last Node of right List
    while (rightList->right)
        rightList = rightList->right;
    // Left of first node points to the last node in the list
    leftList->left = rightList;
    // Right of last node refers to the first node of the List
    rightList->right = leftList;
    return leftList;
}

/************
  Test Main
************/

#include <stdlib.h>
#include <stdio.h>
Node *newNode(int v)
{
    Node *new = malloc(sizeof(Node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main()
{
    Node *r = newNode(8);
    r->left = newNode(4);
    r->left->left = newNode(2);
    r->left->left->left = newNode(1);
    r->left->left->right = newNode(3);

    r->left->right = newNode(6);
    r->left->right->left = newNode(5);
    r->left->right->right = newNode(7);

    r->right = newNode(12);
    r->right->left = newNode(10);
    r->right->left->left = newNode(9);
    r->right->left->right = newNode(11);

    r->right->right = newNode(14);
    r->right->right->left = newNode(13);
    r->right->right->right = newNode(15);

    r = convert_bst(r);
    for (int i = 0; i < 15; i++)
    {
        printf("%d\n", r->value);
        r = r->right;
    }
    for (int i = 0; i < 17; i++)
    {
        printf("%d\n", r->value);
        r = r->left;
    }
}
