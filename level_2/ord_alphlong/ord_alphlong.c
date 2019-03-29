/*
ORD_ALPHLONG
Assignment name  : ord_alphlong
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string as a parameter and prints its words sorted
in order of their length first and then in alphabetical order on each line:
when we say alphabetical order we ignore the case of letters.
For example aA and Aa are the same but the  original order must remain
(lower and upper case are the same in alphabetical order). If there are
duplicates, they must remain.
If number of parameters is different from 1, the program prints 
\n.
There will be only spaces, tabs and alphanumeric caracters in strings.
You'll print only one space between each word. Nothing before the first and 
after the last word of each line.
Examples:
$>./ord_alphlong
$
$>./ord_alphlong "De son baton il frappa la pierre et l eau jaillit" | cat -e
l$
De et il la$
eau son$
baton$
frappa pierre$
jaillit$
$>./ord_alphlong "A a b B cc ca cd" | cat -e
A a b B$
ca cc cd$
$>./ord_alphlong "Pour l Imperium de l humanite" | cat -e
l l$
de$
Pour$
humanite Imperium$
$>
*/