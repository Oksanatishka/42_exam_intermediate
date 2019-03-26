/*
Assignment name  : is_looping
Expected files   : is_looping.c
Allowed functions: 
--------------------------------------------------------------------------------

ALERT: OPTIMIZED SOLUTION REQUIRED.

Given the first node of a linked list as parameter, create a function which
returns 1 if the linked list is looping, otherwise 0.

The linked list uses the following structure:

struct s_node {
    int value;
    struct s_node *next;
};

The function must be declared as follows:

int    is_looping(struct s_node *node);


Considerations:

- Be careful: the naive solution won't work on our big input, you have to
find a solution with better complexity than O(N^2) time (where N is the
number of nodes).
- The values of each node does not matter.
- The bigger test we will do is on a linked list of 500.000 nodes, with the
beginning of the loop at the middle. It should run in less than 2 seconds.


Example 1:

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |         v
          |         6
           \        |
            \______/

In this case, it should return 1 (at the node 3 begins the loop).

Example 2: 

12 -> 150 -> 30 -> 50 -> 345 -> 120
       ^                         |
       |                         v
       |                        200
        \                      /
         \____________________/

In this case, it should return 1 (the loop begins at node 150).

Example 3:

12 -> 150 -> 30 -> 50 -> 345 -> 120

In this case, it should return 0 (no loop begins).

Example 4:

12 -> 19 -> 14
            ^ \
            | |
            \/

In this case, it should return 1 (the loop begins at node 14).
*/

struct s_node
{
    int value;
    struct s_node *next;
};

int is_looping(struct s_node *node)
{
    if (!node)
        return (0);

    struct s_node *slow = node;
    struct s_node *fast = node->next;

    while (slow && fast && fast->next)
    {
        if (slow == fast)
            return (1);
        fast = fast->next->next;
        slow = slow->next;
    }
    return (0);
}

// Comment below part

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BBLACK "\x1b[40m"
#define BRED "\x1b[41m"
#define BGREEN "\x1b[42m"
#define BYELLOW "\x1b[43m"
#define BBLUE "\x1b[44m"
#define BMAGENTA "\x1b[45m"
#define BCYAN "\x1b[46m"
#define BWHITE "\x1b[47m"
#define RESET "\x1b[0m"
#define CLEAR "\033c"
#define BOLD "\033[1m"

// struct s_node
// {
//     int value;
//     struct s_node *next;
// };

// int is_looping(struct s_node *node);

struct s_node *create_node(int value)
{
    struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
    new->value = value;
    new->next = NULL;
    return (new);
}

int main()
{
    struct s_node *root;
    struct s_node *tmp;
    struct s_node *loop;
    int il;

    root = create_node(1);
    root->next = create_node(2);
    tmp = root->next;
    tmp->next = create_node(3);
    tmp = tmp->next;
    loop = tmp;
    tmp->next = create_node(4);
    tmp = tmp->next;
    tmp->next = create_node(5);
    tmp = tmp->next;
    tmp->next = create_node(6);
    tmp = tmp->next;
    tmp->next = loop;

    il = is_looping(root);
    printf(BOLD "EXAMPLE 1:\n" RESET);
    printf(YELLOW "Expected: " BOLD "1\n" RESET);
    printf("%sOutput: " BOLD "%d\n" RESET, il ? GREEN : RED, il);

    root->value = 12;
    loop = root->next;
    loop->value = 150;
    tmp = loop->next;
    tmp->value = 30;
    tmp = tmp->next;
    tmp->value = 50;
    tmp = tmp->next;
    tmp->value = 345;
    tmp = tmp->next;
    tmp->value = 120;
    tmp->next = create_node(200);
    tmp->next->next = loop;

    il = is_looping(root);
    printf(BOLD "EXAMPLE 2:\n" RESET);
    printf(YELLOW "Expected: " BOLD "1\n" RESET);
    printf("%sOutput: " BOLD "%d\n" RESET, il ? GREEN : RED, il);

    tmp->next = NULL;

    il = is_looping(root);
    printf(BOLD "EXAMPLE 3:\n" RESET);
    printf(YELLOW "Expected: " BOLD "0\n" RESET);
    printf("%sOutput: " BOLD "%d\n" RESET, il ? RED : GREEN, il);

    loop->next->value = 14;
    loop->next->next = loop->next;

    il = is_looping(root);
    printf(BOLD "EXAMPLE 4:\n" RESET);
    printf(YELLOW "Expected: " BOLD "1\n" RESET);
    printf("%sOutput: " BOLD "%d\n" RESET, il ? GREEN : RED, il);
}