#include "bubble.h"
#include "swap.h"
void sort_bubble(int* pArray, int array_length)
{
	for (int i = 1; i < array_length; i++) {
		for (int k = 0; k < i; k++) {
			if (pArray[k] > pArray[i]) {
				swap(&pArray[k], &pArray[i]);
			}
		}
	}
}
