#include "main.h"

/**
 * print_diagonal - Print diagonal with \ which is 92 in ASCII
 * @n: how many to be printed
 *
 * Return: Always return 0
 */

void print_diagonal(int n)
{
	int count;
	int space;

	if (n > 0)
	{
		for (count = 0; count < n; count++)
		{
			for (space = 0; space < count; space++)
			{
				_putchar(' ');
			}
			_putchar(92);
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
