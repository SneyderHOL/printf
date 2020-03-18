#include "holberton.h"
/**
 *_printf - function that prints values according to a format
 *@format: constant char pointer argument
 *Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int fpos = 0, bpos = 0, aux = 0, add = 0;
	char *buffer = malloc(2048);
	va_list main_list;
	fm frame[] = {
		{"c", p_char},
		{"s", p_str},
		{"%", p_perc},
		{"d", p_dec},
		{"i", p_int}
	};

	if (format == NULL || buffer == NULL ||
	    (format[fpos] == '%' && format[fpos + 1] == '\0'))
		return (-1);
	va_start(main_list, format);
	for (fpos = 0; format[fpos] != '\0'; fpos++, aux = 0)
	{
		if (format[fpos] != '%')
		{
			buffer[bpos] = format[fpos];
			bpos++;
		}
		else
			if (format[fpos + 1] != '\0')
			{
				for (aux = 0; aux < 5; aux++)
					if (format[fpos + 1] == frame[aux].c[0])
					{
						add = frame[aux].func(main_list, buffer, bpos), fpos++;
						break;
					}
				bpos += add;
			}
		if (aux > 4)
			buffer[bpos++] = '%';
	}
	buffer[bpos] = '\0', write(1, buffer, bpos);
	free(buffer), va_end(main_list);
	return (bpos);
}
