#include "/Users/varka/source/repos/BinSearchAndSorts/Sorts.h"


Timer::Timer() {begining = clock_time::now();}
void Timer::reset() {begining = clock_time::now();}
double Timer::elapsed() const
	{return std::chrono::duration_cast<second_time>(clock_time::now() - begining).count();}
Timer::~Timer() {}

int* RandomArray(int size)
{
	int* random_array = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		random_array[i] = rand() % (size*2+1) - size; // -20 ... 20
	return random_array;
}

unsigned char* RandomCharArray(int size)
{// use unsigned char to be sure in operation char(int)
	unsigned char* random_char_array = new unsigned char[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		random_char_array[i] = char(rand() % 256); // char type from -128 to 127
		cout << (random_char_array[i]) << endl;
	}
	return random_char_array;
}

int BinarySearch(int* array, int size, int element)
{
	int left_index = 0, right_index = size - 1, middle_index = (left_index + right_index) / 2;
	if (element > array[right_index])
		return (right_index + 1); // returns an index of a new element that doesn't exist now
	while (array[middle_index] != element)
	{
		if (left_index == right_index)
			// returns a right-index place for a new not-existing element
			break;
		if (element < array[middle_index])
			right_index = middle_index;
		else
		{
			if (right_index - left_index == 1)
				left_index = right_index;
			else
				left_index = middle_index;
		}
		middle_index = (left_index + right_index) / 2;
	}
	return middle_index; // returns any index if exists several same numbers
}

void CountingSort(unsigned char* array, int size)
{
	unsigned char max = array[0];
	for (int i = 1; i < size; i++) // find max char
	{
		if (array[i] > max)
			max = array[i];
	}
	int* countMas = new int[int(max) + 1]{0}; // mas to count times we meet char = it's index
	for (int i = 0; i < size; i++)
		countMas[int(array[i])]++;
	int now_index = 0; // to fill the data mas
	for (int i = 0; i < int(max) + 1; i++) // on elements of count mas
	{
		for (int j = 0; j < countMas[i]; j++) // how many times for one char
		{
			array[now_index] = unsigned char(i);
			now_index++;
		}
	}
}

void InsertionSort(int* array, int size)
{
	if (size <= 1)
		return;
	for (int i = 1; i < size; i++)
	{
		int key = array[i], key_index = BinarySearch(array, i, key);
		// move elements to the right to insert a new element
		for (int j = i; j > key_index; j--)
			array[j] = array[j - 1];
		array[key_index] = key; // insert new element
	}
}

void BogoSort(int* array, int size)
{
	bool sorted = IsSorted(array, size);
	while (!sorted)
	{
		srand(time(NULL));
		for (int i = 0; i < size - 1; i++)
		{
			int random_index = rand() % (size-i);
			if (array[i] > array[random_index + i])
			{
				swap(array[i], array[random_index + i]);
				i = 0;
			}
			if (IsSorted(array, size))
			{
				sorted = true;
				break;
			}
		}
	}
}

void QuickSort(int* array, int size)
{
	if (size <= 1)
		return;
	int pivot = array[size - 1];
	int bigger_index = 0, pivot_index = size - 1; // bigger_index is the index of the last met bigger than pivot element
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] > pivot)
		{
			bigger_index = pivot_index = i; // if we won't find element less than pivot, it'll be true
			for (++i; i < size; i++) // go forward on elements 
			{
				if (array[i] <= pivot)
				{
					swap(array[bigger_index], array[i]);
					if (i != size - 1) // than we already shared the massive on two parts with pivot on it's place
						pivot_index = ++bigger_index; // because all less elements went to the left regarding to pivot_index
				}
			}
		}
	}
	QuickSort(array, pivot_index); // sort left part
	if (size > pivot_index + 1)
		QuickSort(&array[pivot_index + 1], size - pivot_index - 1); // sort right part
}

int main()
{
	for (int i = 10; i <= 100000; i *= 10)
	{
		int size = i;
		int* array = RandomArray(size);
		int* array_copy = array;
		Timer sort_time;
		QuickSort(array, size);
		cout << "Time for QuickSort for " << size << " elements = " << sort_time.elapsed() << endl;
		sort_time.reset();
		InsertionSort(array_copy, size);
		cout << "Time for InsertionSort for " << size << " elements = " << sort_time.elapsed() << endl;
		cout << endl;
	}
	return 0;
}
