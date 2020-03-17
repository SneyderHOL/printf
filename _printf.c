#include "holberton.h"
#include <stdio.h>
/**
 *fill_buffer - function to fill the buffer with '0'
 *@buff: char pointer argument
 *Return: void
 */
void fill_buffer(char *buff)
{
	int aux = 0;

	for (aux = 0; aux < BUFF_SIZE; aux++)
	{
		buff[aux] = '\0';
	}
}
/**
 *_printf - function that prints values according to a format
 *@format: constant char pointer argument
 *Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int fpos = 0, bpos = 0, aux = 0;
	char *buffer = NULL, *res = NULL;
	va_list main_list;
	fm frame[] = {
		{"c", p_char},
		{"s", p_str},
		{"%", p_perc},
		{"d", p_dec},
		{"i", p_int}
	};

	if (format == NULL)
		return (-1);
	buffer = malloc(BUFF_SIZE);
	if (buffer == NULL)
		return (0);
	va_start(main_list, format);
	for (fpos = 0; format[fpos] != '\0'; fpos++)
	{
		if (format[fpos] != '%')
		{
			buffer[bpos] = format[fpos];
			bpos++;
		}
		else
		{
			if (format[fpos + 1] != '\0')
			{
				for (aux = 0; aux < FR_SIZE; aux++)
				{
					if (format[fpos + 1] == frame[aux].c[0])
					{
						res = frame[aux].func(main_list);
						fpos++;
						break;
					}
				}
				aux = am_string(buffer, res, bpos);
				bpos += aux;
			}
		}
	}
	write(1, buffer, bpos);
	free(buffer);
	va_end(main_list);
	return (bpos);
}
