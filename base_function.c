#include "holberton.h"
#include <stdio.h>
/**
 *p_char - function that search for a character value
 *@list: a va_list argument
 *Return: a string
 */
char *p_char(va_list list)
{
	char *s = NULL;
	int i = 0;

	i = va_arg(list, int);
	s = malloc(2 * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[0] = i;
	s[1] = '\0';
	return (s);
}
/**
 *p_str - function that search for a char pointer value
 *@list: a va_list argument
 *Return: a string
 */
char *p_str(va_list list)
{
	int size = 0, aux = 0;
	char *str = NULL, *s = NULL;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		str = "(null)";
		s = malloc(7);
		for (aux = 0; str[aux] != '\0'; aux++)
			s[aux] = str[aux];
		s[aux] = '\0';
		return (s);
	}
	size = str_size(str);
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (aux = 0; str[aux] != '\0'; aux++)
		s[aux] = str[aux];
	return (s);
}
/**
 *p_perc - function that search for a % character
 *@list: a va_list argument
 *Return: a string
 */
char *p_perc(va_list list)
{
	char *s = NULL;

	(void) list;
	s = malloc(2 * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[0] = '%';
	s[1] = '\0';
	return (s);
}
/**
 *p_dec - function that search for a decimal value
 *@list: a va_list argument
 *Return: a string
 */
char *p_dec(va_list list)
{
	int num = 0, size = 0;
	char *s = NULL;

	num = va_arg(list, int);
	size = num_len(num, 10);
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	_itoa(s, num, 10);
	return (s);
}
/**
 *p_int - function that search for an integer value
 *@list: a va_list argument
 *Return: a string
 */
char *p_int(va_list list)
{
	int num = 0, size = 0;
	char *s = NULL;

	num = va_arg(list, int);
	size = num_len(num, 10);
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	_itoa(s, num, 10);
	return (s);
}
