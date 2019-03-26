/*
IS_ANAGRAM
Assignment name  : is_anagram
Expected files   : is_anagram.c
Allowed functions: 
--------------------------------------------------------------------------------
ALERT: OPTIMIZED SOLUTION REQUIRED.
An anagram is a sequence of characters formed by rearranging the letters of
another sequence, such as 'cinema', formed from 'iceman'.
Given two strings as parameters, create a function able to tell whether or
not the first string is an anagram of the second.
The function must be declared as follows:
int is_anagram(char *a, char *b);
Considerations:
- Be careful: the naive solution won't work on our big input, you have to
find an optimized solution which will run in O(sa + sb) time (where sa is
the length of a and sb length of b).
- Our tested string will always be a sequence of ascii characters between 32
and 126 inclusive.
- The bigger test we will do is on 2 sequences of 1.000.000 characteres each.
It should run in less than 2 seconds.
Example 1:
a='abcdef'
b='fabcde'
In this case, these two strings are anagrams, your function should return 1.
Example 2: 
a='.123?.'
b='?321..'
In this case, these two strings are anagrams, your function should return 1.
Example 3:
a='abca'
b='bcab'
In this case, these two strings are not anagrams, your function should return 0.
*/
#include <stdio.h>

int is_anagram(char *a, char *b)
{
    int *checka[127 - 32] = {0};
    int *checkb[127 - 32] = {0};
    int i = -1;

    while (a && a[++i])
    {
        checka[a[i] - 32]++;
    }
    i = -1;
    while (b && b[++i])
        checkb[b[i] - 32]++;
    i = -1;
    while (++i < 127 - 32)
    {
        if (checka[i] != checkb[i])
            return (0);
    }
    return (1);
}

int main()
{
    char *a = ".123?.";
    char *b = "?321..";
    printf("%d\n", is_anagram(a, b)); // 1 true

    char *a1 = "abcdef";
    char *b1 = "fabcde";
    printf("%d\n", is_anagram(a1, b1)); // 1 true

    char *a2 = "abca";
    char *b2 = "bcab";
    printf("%d\n", is_anagram(a2, b2)); // 0 false

    return 0;
}