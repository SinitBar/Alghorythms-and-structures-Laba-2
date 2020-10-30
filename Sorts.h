#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib> // is it needed?
#include <ctime>
#include <chrono>
using namespace std;
class Timer
{
private:
	using clock_time = std::chrono::high_resolution_clock;
	using second_time = std::chrono::duration<double, std::ratio<1>>;
	std::chrono::time_point<clock_time> begining;
public:
	Timer();
	void reset();
	double elapsed() const;
	~Timer();
};

int* RandomArray(int size);

template <typename array_elements_type >
bool IsSorted(const array_elements_type* array, int size)
{
	if (size <= 1)
		return true;
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			return false;
	}
	return true;
}

int BinarySearch(int*, int, int);
void InsertionSort(int*, int);
void BogoSort(int*, int);
unsigned char* RandomCharArray(int);
void CountingSort(unsigned char*, int);
void QuickSort(int*, int);
