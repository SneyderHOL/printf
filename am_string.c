#include "holberton.h"
/**
 *am_string - function that add a string to another
 *@buffer: char pointer argument
 *@res: char pointer argument
 *@bpos: int argument
 *Return: integer
 */
int am_string(char *buffer, char *res, int bpos)
{
	int i = 0;

	if (res != NULL)
		for (i = 0; res[i] != '\0'; i++)
		{
			buffer[bpos] = res[i];
			bpos++;
		}
	free(res);
	return (i);
}
