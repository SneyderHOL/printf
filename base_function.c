#include "holberton.h"
#include <stdio.h>
/**
 *p_char - function that search for a character value
 *@list: a va_list argument
 *@buffer: a char pointer argument
 *@bpos: an int arguent
 *Return: an integer
 */
int p_char(va_list list, char *buffer, int bpos)
{
	int i = 0;

	i = va_arg(list, int);
	buffer[bpos] = i;
	return (1);
}
/**
 *p_str - function that search for a char pointer value
 *@list: a va_list argument
 *@buffer: a char pointer argument
 *@bpos: an int arguent
 *Return: an integer
 */
int p_str(va_list list, char *buffer, int bpos)
{
	int aux = 0;
	char *str = NULL;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (aux = 0; str[aux] != '\0'; aux++, bpos++)
		buffer[bpos] = str[aux];
	return (aux);
}
/**
 *p_perc - function that search for a % character
 *@list: a va_list argument
 *@buffer: a char pointer argument
 *@bpos: an int arguent
 *Return: an integer
 */
int p_perc(va_list list, char *buffer, int bpos)
{
	(void) list;
	buffer[bpos] = '%';
	return (1);
}
/**
 *p_dec - function that search for a decimal value
 *@list: a va_list argument
 *@buffer: a char pointer argument
 *@bpos: an int arguent
 *Return: an integer
 */
int p_dec(va_list list, char *buffer, int bpos)
{
	int num = 0, size = 0;

	num = va_arg(list, int);
	size = num_len(num, 10);
	_itoa(buffer + bpos, num, 10);
	return (size);
}
/**
 *p_int - function that search for an integer value
 *@list: a va_list argument
 *@buffer: a char pointer argument
 *@bpos: an int arguent
 *Return: an integer
 */
int p_int(va_list list, char *buffer, int bpos)
{
	int num = 0, size = 0;

	num = va_arg(list, int);
	size = num_len(num, 10);
	_itoa(buffer + bpos, num, 10);
	return (size);
}
