/*
COUNT_OF_2
Assignment name  : count_of_2
Expected files   : count_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------
Implement a function which counts, for a given integer n, the number of 2s
that appear in all the numbers between 0 and n (inclusive).
Your function must be declared as follows:
int    count_of_2(int n);
If n <= 1, the function returns 0;
Examples:
input  = 25
output =  9
because there are 9 2s in (2, 12, 20, 21, 22, 23, 24 and 25)
Note:
the number 22 counts as 2 because it has two 2s, number 202 count as 2, number 22022 count as 4 etc…
*/

#include <stdio.h>
#include <stdlib.h>

int count_of_2(int n)
{
    int count = 0;
    int i = 2;
    while (i <= n)
    {
        int k = i;
        while (k > 0)
        {
            if (k % 10 == 2)
            {
                count++;
            }
            k = k / 10;
        }
        i++;
    }
    return count;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        printf("%d", count_of_2(atoi(argv[1])));
    }
    return 0;
}

// To compile: gcc count_of_2.c
// To run: ./a.out 25