/*
G_DIAM
Assignment name  : g_diam
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a programe that takes a string. This string represents a graph and is
composed of series of links between this graph's nodes. Links are separated by
a single space. Nodes are represented by numbers, and links by two nodes
separated by a '-'. For exemple, if there is a link between nodes 2
and 3, it could be written as "2-3" or "3-2".
The program will display the number of nodes comprised in the longest chain,
followed by a '\n', given it's impossible to pass through a node more than once.
If the number of parameters is different from 1, the program displays a '\n'.
Examples:
$>./g_diam "17-5 5-8 8-2 2-8 2-8 17-21 21-2 5-2 2-6 6-14 6-12 12-19 19-14 14-42" | cat -e
10$
$>./g_diam "1-2 2-3 4-5 5-6 6-7 7-8 9-13 13-10 10-2 10-11 11-12 12-8 16-4 16-11 21-8 21-12 18-10 18-13 21-18" | cat -e
15$
*/