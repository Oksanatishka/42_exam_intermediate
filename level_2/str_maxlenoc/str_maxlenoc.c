/*
STR_MAXLENOC
Assignment name  : str_maxlenoc
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes one or more strings and displays, followed by a
newline, the longest string that appears in every parameter. If more that one
string qualifies, it will display the one that appears first in the first
parameter. Note that the empty string technically appears in any string.
If there are no parameters, the program displays \n.
Examples:
$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$
*/

#include <unistd.h>

int len(char *str) 
{
	int len = 0;
	while(str[len] != '\0')
		len++;
	return (len);
}

int     ft_strstr(char *str1, char *str2, int start, int end) 
{
    for (int i = 0, beg = start; str1[i]; i++, start = beg)
    {
        for (;str1[i] == str2[start] && start < end; i++, start++) 
            ;
        if (start == end)
            return (1);
        else
            i -= start - beg;
    }
    return (0);
}
int		main(int ac, char **av)
{
	if (ac >= 2)
	{
		int	min_len = 2147483647;
		int min_i = 1; 
		for (int i = 1; i < ac; i++)
		{
			int clen = len(av[i]);
			if (clen < min_len)
			{	
				min_len = clen;
				min_i = i; 
			}
		}
		for(int i = 0, match, offset = min_len; i < min_len ; i++, offset--)
			for(int j = 0; j <= i; j++) 
			{
				match = 0;
				for (int avi = 1; avi < ac; avi++)
					if (avi != min_i && ft_strstr(av[avi], av[min_i], j, j + offset))
						match++;
				if(match == ac - 2)
				{
					for (int i = j; i < j + offset; i++)
						write(1, &(av[min_i][i]), 1);
					write(1, "\n", 1);
					return (0);
				}
			}
	}
	write(1, "\n", 1);
	return (0);
}
