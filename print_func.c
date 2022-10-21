#include "main.h"
/**
 * print_char - Prints a single character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */

int print_char(va_list ap, params_t *params)
{
char pad_char = ' ';
unsigned int pad = 1, count = 0, ch = va_arg(ap, int);

if (params->minus_flag)
count += _putchar(ch);
while (pad++ < params->width)
count += _putchar(pad_char);
if (!params->minus_flag)
count += _putchar(ch);
return (count);
}

/**
 * print_int - Prints an integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: Number of digits to be printed
 */
int print_int(va_list ap, params_t *params)
{
long l;

if (params->l_modifier)
l = va_arg(ap, long);
else if (params->h_modifier)
l = (short int)va_arg(ap, int);
else
l = (int)va_arg(ap, int);
return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints collection of characters
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number characters printed
 */
int print_string(va_list ap, params_t *params)
{
char *str = va_arg(ap, char *), pad_char = ' ';
unsigned int pad = 0, count = 0, i = 0, j;

(void)params;
switch ((int)(!str))
case 1:
str = NULL_STRING;

j = pad = _strlen(str);
if (params->precision < pad)
j = pad = params->precision;

if (params->minus_flag)
{
if (params->precision != UINT_MAX)
for (i = 0; i < pad; i++)
count += _putchar(*str++);
else
count += _puts(str);
}
while (j++ < params->width)
count += _putchar(pad_char);
if (!params->minus_flag)
{
if (params->precision != UINT_MAX)
for (i = 0; i < pad; i++)
count += _putchar(*str++);
else
count += _puts(str);
}
return (count);
}

/**
 * print_percent - prints percentage
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: percetage char printed
 */
int print_percent(va_list ap, params_t *params)
{
(void)ap;
(void)params;
return (_putchar('%'));
}

/**
 * print_S - Prints a string and nonprintable
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of printed characters
 */
int print_S(va_list ap, params_t *params)
{
char *str = va_arg(ap, char *);
char *hex;
int count = 0;

if ((int)(!str))
return (_puts(NULL_STRING));
for (; *str; str++)
{
if ((*str > 0 && *str < 32) || *str >= 127)
{
count += _putchar('\\');
count += _putchar('x');
hex = convert(*str, 16, 0, params);
if (!hex[1])
count += _putchar('0');
count += _puts(hex);
}
else
{
count += _putchar(*str);
}
}
return (count);
}
