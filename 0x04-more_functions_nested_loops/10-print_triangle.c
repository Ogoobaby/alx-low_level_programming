#include "main.h"

/**
 * print_triangle - Program that print triangle
 * @size: The size of the triangle
 *
 * Return : 0
 */

void print_triangle(int size)
{
	int count, space, hash;

	for (count = 1; count <= size; count++)
	{
		for (space = size - count; space > 0; space--)
		{
			_putchar(' ');
		}
		for (hash = 0; hash < count; hash++)
		{
			_putchar(35);
		}
		if (count == size)
			continue;
		_putchar('\n');
	}
	_putchar('\n');
}
