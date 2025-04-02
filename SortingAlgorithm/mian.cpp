#include <iostream>
#include "array_class.h"
#include <chrono>
#include <fstream>
#include "bubble.h"
#include "insertion.h"
#include "selection.h"

#define MIN_SIZE 1000000
#define MAX_SIZE 1000000
#define SIZE_GROTH 100000
#define FOR_LOOP 1

void print_array(int* p_array, int array_length) {
	for (int i = 0; i < array_length; i++) {
		std::cout << p_array[i] << " ";
	}
	std::cout << "\n";
}

int main(void) {
	
	//정열할데이터크기는100,000에서1,000,000의범위에서 선택

	//Array bubble_sort(100000);
	//Array insertion_sort(100000);
	//Array selection_sort(100000);

	std::ofstream bubble("bubble_sort.txt");
	std::ofstream insertion("insertion_sort.txt");
	std::ofstream selection("selection_sort.txt");

	if (bubble.is_open() && insertion.is_open() && selection.is_open()) std::cout << "pass\n";
	else std::cout << "fail\n";

	std::chrono::high_resolution_clock::time_point start, finish;
	std::chrono::duration<double> duration;
	
	for (int array_size = MIN_SIZE; array_size < MAX_SIZE+1; array_size += SIZE_GROTH) {
		Array bubble_sort(array_size);
		Array insertion_sort(array_size);
		Array selection_sort(array_size);

		for (int i = 0; i < FOR_LOOP; i++) 
		{
			bubble_sort.putRandom();
			start = std::chrono::high_resolution_clock::now();
			bubble_sort.sortByBubble();
			finish = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);

			bubble <<array_size << " " << duration.count() << "\n";
		}
		
		for (int i = 0; i < FOR_LOOP; i++)
		{
			insertion_sort.putRandom();
			start = std::chrono::high_resolution_clock::now();
			insertion_sort.sortByInsertion();
			finish = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);

			insertion << array_size << " " << duration.count() << "\n";
		}
		
		for (int i = 0; i < FOR_LOOP; i++)
		{
			selection_sort.putRandom();
			start = std::chrono::high_resolution_clock::now();
			selection_sort.sortBySelection();
			finish = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);

			selection << array_size << " " << duration.count() << "\n";
		}

	}

	/*
	int test[5] = { 5,4,3,2,1 };
	sort_bubble(test, 5);
	print_array(test, 5);
	int test1[5] = { 5,4,3,2,1 };
	sort_insertion(test1, 5);
	print_array(test1, 5);
	int test2[5] = { 5,4,3,2,1 };
	sort_selection(test2, 5);
	print_array(test2, 5);
	*/

}