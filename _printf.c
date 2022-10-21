#include "main.h"
/**
 * _printf - contains the string and parameters needed to print a formated string
 * @format: points to the string with all the desired characters/arguments
 * @ap: variable that refers to each argument in turn, argument pointer
 * Return: A count of characters to be printed
 */

int _printf(const char *format, ...)
{
int count = 0;
va_list ap;
char *p, *start;
params_t params = PARAMS;

va_start(ap, format);

if (!format )
        return (-1);
for (p = (char *)format; *p; p++)
{
init_params(&params, ap);
if (*p != '%')
{
count = count + _putchar(*p);
continue;
}
start = p;
p++;
while (get_flag(p, &params))
{
p++;
}
p = get_width(p, &params, ap);
p = get_precision(p, &params, ap);
if (get_modifier(p, &params))
p++;
if (!get_specifier(p))
count += print_from_to(start, p,
params.l_modifier || params.h_modifier ? p - 1 : 0);
else
count += get_print_func(p, ap, &params);
}
_putchar(BUFFER_FLUSH);
va_end(ap);
return (count);
}
