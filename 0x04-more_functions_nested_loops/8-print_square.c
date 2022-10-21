#include "main.h"

/**
 * print_square - Function to print square
 * @size: The size to be printed
 *
 * Return: Always 0
 */

void print_square(int size)
{
	int rows;
	int cols;

	if (size > 0)
	{
		for (cols = 0; cols < size; cols++)
		{
			for (rows = 0; rows < size; rows++)
			{
				_putchar(35);
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
