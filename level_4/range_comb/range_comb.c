/*
RANGE_COMB
Assignment name  : range_comb
Expected files   : range_comb.c
Allowed functions: malloc free memcpy
--------------------------------------------------------------------------------
Implement a function which computes, for a given integer n, all
the possible permutations of the numbers in the range from 0 to
(n - 1) inclusive.
The function returns a null-terminated array.
Your function must be declared as follows:
int    **range_comb(int n);
If n <= 0, the function returns -1;
Examples:
input  = 2
output = {{0, 1}, {1, 0}}
input  = 3
output = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}
*/