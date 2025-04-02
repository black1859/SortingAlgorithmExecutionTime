#include "array_class.h"
#include "swap.h"
#include <stdlib.h>
#include <iostream>

Array::Array(int length) : m_length(length)
{
	m_data = (int*)malloc(length * sizeof(int));
	putRandom();
}

Array::~Array()
{
	free(m_data);
}

void Array::sortByBubble()
{
	for (int i = 1; i < m_length; i++) {
		for (int k = 0; k < i; k++) {
			if (m_data[k] > m_data[i]) {
				swap(&m_data[k], &m_data[i]);
			}
		}
	}
}

void Array::sortByInsertion()
{
	int move = 0;
	for (int i = 1; i < m_length; i++) {
		int value = m_data[i], index = i;
		if (m_data[index - 1] > value) {
			move = 1;
		}
		else
		{
			move = 0;
		}
		while (move)
		{
			m_data[index] = m_data[index - 1];
			index--;
			if (index > 0 && m_data[index - 1] > value) move = 1;
			else move = 0;
		}
		m_data[index] = value;
	}
}

void Array::sortBySelection()
{
	for (int last_pos = m_length-1; last_pos > 0; last_pos--) {
		int index = 0, big = m_data[index];
		for (int i = 0; i <= last_pos; i++) { //search biggest from index [0] to index [last_pos]
			if (m_data[i] > big) {
				big = m_data[i];
				index = i;
			}
		}
		swap(&m_data[index], &m_data[last_pos]);
	}
}

void Array::putRandom()
{
	for (int i = 0; i < m_length; i++) {
		m_data[i] = rand() % 100;
	}
}

void Array::printAll()
{
	for (int i = 0; i < m_length; i++) {
		std::cout << m_data[i] << " ";
	}
	std::cout << "\n";
}

int Array::getLength()
{
	return m_length;
}

