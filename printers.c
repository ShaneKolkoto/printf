#include "main.h"
/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
    int count = 0;

    while (start <= stop)
    {
        if (start != except)
            count += _putchar(*start);
        start++;
    }
    return (count);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
    int len, count = 0;
    char *str = va_arg(ap, char *);
    (void)params;

    if (str)
    {
        for (len = 0; *str; str++)
            len++;
        str--;
        for (; len > 0; len--, str--)
            count += _putchar(*str);
    }
    return (count);
}

/**
 * print_rot13 - Prints a string in rot13 format
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number of printed characters
 */
int print_rot13(va_list ap, params_t *params)
{
    int i, index;
    int count = 0;
    char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";
    char *a = va_arg(ap, char *);
    (void)params;

    i = 0;
    index = 0;
    while (a[i])
    {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            index = a[i] - 65;
            count += _putchar(arr[index]);
        }
        else
            count += _putchar(a[i]);
        i++;
    }
    return (count);
}
