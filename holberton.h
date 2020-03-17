#ifndef HOLBERTON
#define HOLBERTON
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE 2048
#define FR_SIZE 5
/**
 *struct fmt - struct to use the format
 *@c: char pointer
 *@func: function pointer
 *Description: Struc for fmt
 */
typedef struct fmt
{
	char *c;
	int (*func)(va_list, char*, int);
} fm;
int p_char(va_list, char *, int);
int p_str(va_list, char *, int);
int p_perc(va_list, char *, int);
int p_dec(va_list, char *, int);
int p_int(va_list, char *, int);
int num_len(int num, int base);
void _itoa(char *str, int num, int base);
void rev_string(char *s, int size);
int _printf(const char *format, ...);
#endif
