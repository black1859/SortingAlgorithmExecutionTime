#include "selection.h"
#include "swap.h"
void sort_selection(int* p_array, int array_length)
{
	for (int last_pos = array_length - 1; last_pos > 0; last_pos--) {
		int index = 0, big = p_array[index];
		for (int i = 0; i <= last_pos; i++) { //search biggest from index [0] to index [last_pos]
			if (p_array[i] > big) {
				big = p_array[i];
				index = i;
			}
		}
		swap(&p_array[index], &p_array[last_pos]);
	}
}
