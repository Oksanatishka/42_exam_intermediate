/*
LONGEST_SEQUENCE
Assignment name  : longest_sequence
Expected files   : longest_sequence.c
Allowed functions: 
--------------------------------------------------------------------------------
Given the root node of a binary tree, create a function that return the length of the longest path which comprises of nodes with consecutive values in increasing order.
Every node is considered as a path of length 1.
The binary tree uses the following node structure :
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};
The function must be declared as follows:
int	longest_sequence(struct s_node *node);
Example 1:
       10
       /
      5
     / \
    /   \
   6    9
  / \
 /   \
7   13
In this case, it should return 3 (because the longest consecutive sequence is: 5 -> 6 -> 7).
Example 2:
   5
  / \
 /   \
6     4
    /  \
   9    3
 /  \    \
3    2    2
In this case, your function return 2 (because the longest consecutive sequence is: 5 -> 6 ).
Example 3: 
    30
    / \
   /   \
  15   41
 /     /
61    80
In this case, it should return 1.
Example 4:
NULL
In this case, as the root node is null, your function should return 0.
*/

typedef struct		s_node
{
	int value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

void	penetrate_deep(t_node *last, t_node *this, int seq, int *n)
{
	if (this)
	{
		seq = (this->value - last->value == 1) ? seq + 1 : 1;
		*n = ft_max(*n, seq);
		penetrate_deep(this, this->left, seq, n);
		penetrate_deep(this, this->right, seq, n);
	}
}

int	longest_sequence(struct s_node *node)
{
	int	n = 1;

	if (!node)
		return (0);
	penetrate_deep(node, node->left, 1, &n);
	penetrate_deep(node, node->right, 1, &n);
	return (n);
}


// TEST - remove before submitting

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

Node *newNode(int val){
    Node *node = malloc(sizeof(Node));

    node->value = val;
    node->left = 0;
    node->right = 0;

    return node;
}
int main(){
    Node *n = newNode(6);

    n->left = newNode(7);
    n->left->left = newNode(8);
    n->left->left->left = newNode(9);

    printf("%d", longest_sequence(n));

    return 0;
}
