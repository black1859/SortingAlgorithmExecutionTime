#include "insertion.h"

void sort_insertion(int* p_array, int array_length)
{
	int move = 0;
	for (int i = 1; i < array_length; i++) {
		int value = p_array[i], index = i;
		if (p_array[index - 1] > value) {
			move = 1;
		}
		else
		{
			move = 0;
		}
		while (move)
		{
			p_array[index] = p_array[index - 1];
			index--;
			if (index > 0 && p_array[index - 1] > value) move = 1;
			else move = 0;
		}
		p_array[index] = value;
	}
}