#include "holberton.h"
#include <stdio.h>
/**
 *num_len - converts an integer to a string
 *@num: integer argument
 *@base: integer argument
 *Return: integer
 */
int num_len(int num, int base)
{
	int negative = 0, pos = 0;

	if (num == 0)
	{
		pos++;
		return (pos);
	}
	if (num < 0 && base == 10)
	{
		negative = 1;
	}
	for (pos = 0; num != 0; pos++)
	{
		num = num / base;
	}
	if (negative == 1)
		pos++;
	return (pos);
}
/**
 *_itoa - converts an integer to a string
 *@num: integer argument
 *@base: integer argument
 *@str: char pointer argument
 *Return: void
 */
void _itoa(char *str, int num, int base)
{
	int negative = 0, pos = 0;
	unsigned int u_num = 0, aux = 0, u_base = 0;

	if (num == 0)
	{
		str[pos++] = '0';
		str[pos] = '\0';
		return;
	}
	if (num < 0 && base == 10)
	{
		if (num != -2147483648)
			num = num * -1;
		negative = 1;
	}
	u_num = num;
	u_base = base;
	for (pos = 0; u_num != 0; pos++)
	{
		aux = u_num % u_base;
		if (aux > 9)
			str[pos] = (aux - 10) + 97;
		else
			str[pos] = aux + '0';
		u_num = u_num / u_base;
	}
	if (negative == 1)
		str[pos++] = '-';
	rev_string(str, pos);
}
/**
 *rev_string - reverse a string
 *@s: char pointer argument
 *@size: integer argument
 *Return: void
 */
void rev_string(char *s, int size)
{
	int a = 0, b = 0, aux = 0;

	a = size - 1;
	for (b = 0; b < a; b++)
	{
		aux = *(s + b);
		*(s + b) = *(s + a);
		*(s + a) = aux;
		a--;
	}
	*(s + size) = '\0';
}
