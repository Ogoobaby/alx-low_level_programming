#include "main.h"

/**
  * more_numbers - Function to print numbers from 0 - 9
  *
  * Return: Always 0
  */

void more_numbers(void)
{
	int count;
	int num;

	for (count = 0; count < 10; count++)
	{
		for (num = 0; num <= 14; num++)
		{
			if (num >= 10)
			{
				_putchar((num / 10) + '0');
			}
			_putchar((num % 10) + '0');
		}
		_putchar('\n');
	}
}
