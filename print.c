#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_char - function that print character
 * @c: print char
 * return: void
 */
void print_char(char c)
{
	write(1, &c, 1);
}

/**
 * print_str - function that print string
 * @str: print str
 * Return: void
 */
void print_str(char *str)
{
	if (!*str)
		return;
	print_char(*str++);
	print_str(str);
}
int main()
{
	print_str("hello");
	return (0);
}
