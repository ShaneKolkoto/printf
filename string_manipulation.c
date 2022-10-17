#include "main.h"

/**
 * print_reversed - Calls a function to reverse and print a string
 * @arg: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_write_char(ptr[len]);
	free(ptr);
	return (len);
}

/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */
// int rot13(va_list list)
// {
// 	int i;
// 	int x;
// 	char *str;
// 	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
// 	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

// 	str = va_arg(list, char *);
// 	if (str == NULL)
// 		return (-1);
// 	for (i = 0; str[i] != '\0'; i++)
// 	{
// 		for (x = 0; x <= 52; x++)
// 		{
// 			if (str[i] == s[x])
// 			{
// 				_write_char(u[x]);
// 				break;
// 			}
// 		}
// 		if (x == 53)
// 			_write_char(str[i]);
// 	}
// 	return (i);
// }
/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_bigS(va_list l, flags_t *f)
{
int i, count = 0;
char *res;
char *s = va_arg(l, char *);

(void)f;
if (!s)
return (_puts("(null)"));
for (i = 0; s[i]; i++)
{
if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
{
_puts("\\x");
count += 2;
res = convert(s[i], 16, 0);
if (!res[1])
count += _putchar('0');
count += _puts(res);
}
else
count += _putchar(s[i]);
}
return (count);
}
