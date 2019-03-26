/*
COUNT_APLHA
Assignment name  : count_alpha
Expected files   : count_alpha.c
Allowed functions: write, printf
--------------------------------------------------------------------------------
Write a program called count_alpha that takes a string and displays the number
of occurences of its alphabetical characters. Other characters are not counted.
The order is the order of occurence in the string. The display must be ended by
a newline.
The format is in the examples.
If the number of arguments is not 1, display only a newline.
Examples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$
*/
// #include <stdio.h>

// void countAlpha(char **str){
//     int i=0;
//     int count =0;
//     while(str[i] != '\0'){
//         int j = i+1;
//         while(str[j] !='\0'){
//             if ()
//         }
//         i++;
//     }
// }
// int main(int argc, char **argv){
//     if(argc==2){
//         countAlpha(argv[1]);
//     } else {
//         printf("\n");
//     }
//     return 0;
// }

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int abc[26] = {0};
        char *str = av[1];
        int i = 0;
        int flag = 0;

        while (str[i])
        {
            if ('a' <= str[i] && str[i] <= 'z')
                abc[str[i] - 'a'] += 1;
            else if ('A' <= str[i] && str[i] <= 'Z')
                abc[str[i] - 'A'] += 1;
            i++;
        }
        i = 0;
        while (str[i])
        {
            if ('a' <= str[i] && str[i] <= 'z' && abc[str[i] - 'a'])
            {
                printf("%s%d%c", flag ? ", " : "", abc[str[i] - 'a'], str[i]);
                flag = 1;
                abc[str[i] - 'a'] = 0;
            }
            else if ('A' <= str[i] && str[i] <= 'Z' && abc[str[i] - 'A'])
            {
                printf("%s%d%c", flag ? ", " : "", abc[str[i] - 'A'], str[i] - 'A' + 'a');
                flag = 1;
                abc[str[i] - 'A'] = 0;
            }
            i++;
        }
    }
    printf("\n");
    return (0);
}