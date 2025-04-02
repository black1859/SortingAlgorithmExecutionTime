#pragma once

class Array
{
public:
	
	Array(int length);
	~Array();

	void sortByBubble();
	void sortByInsertion();
	void sortBySelection();

	void putRandom();

	void printAll();

	int getLength();

private:
	int m_length;
	int* m_data;
};