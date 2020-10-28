#include "/Users/varka/source/repos/BinSearchAndSorts/Sorts.h"


Timer::Timer() {m_beg = clock_time::now();}
void Timer::reset() {m_beg = clock_time::now();}
double Timer::elapsed() const
	{return std::chrono::duration_cast<second_time>(clock_time::now() - m_beg).count();}
Timer::~Timer() {}

int* RandomMas(int size)
{
	int* randomMas = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		randomMas[i] = rand() % (size*2+1) - size; // -20 ... 20
	return randomMas;
}

unsigned char* RandomCharMas(int size)
{// use unsigned char to be sure in operation char(int)
	unsigned char* randomMas = new unsigned char[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		randomMas[i] = char(rand() % 256); // char type from -128 to 127
		cout << (randomMas[i]) << endl;
	}
	return randomMas;
}

int BinarySearch(int* mas, int size, int element)
{
	int left_index = 0, right_index = size - 1, middle_index = (left_index + right_index) / 2;
	if (element > mas[right_index])
		return (right_index + 1); // returns an index of a new element that doesn't exist now
	while (mas[middle_index] != element)
	{
		if (left_index == right_index)
			// returns a right-index place for a new not-existing element
			break;
		if (element < mas[middle_index])
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

void CountingSort(unsigned char* mas, int size)
{
	unsigned char max = mas[0];
	for (int i = 1; i < size; i++) // find max char
	{
		if (mas[i] > max)
			max = mas[i];
	}
	int* countMas = new int[int(max) + 1]{0}; // mas to count times we meet char = it's index
	for (int i = 0; i < size; i++)
		countMas[int(mas[i])]++;
	int now_index = 0; // to fill the data mas
	for (int i = 0; i < int(max) + 1; i++) // on elements of count mas
	{
		for (int j = 0; j < countMas[i]; j++) // how many times for one char
		{
			mas[now_index] = unsigned char(i);
			now_index++;
		}
	}
}

void InsertionSort(int* mas, int size)
{
	if (size <= 1)
		return;
	for (int i = 1; i < size; i++)
	{
		int key = mas[i], key_index = BinarySearch(mas, i, key);
		// move elements to the right to insert a new element
		for (int j = i; j > key_index; j--)
			mas[j] = mas[j - 1];
		mas[key_index] = key; // insert new element
	}
}

void BogoSort(int* mas, int size)
{
	bool sorted = IsSorted(mas, size);
	while (!sorted)
	{
		srand(time(NULL));
		for (int i = 0; i < size - 1; i++)
		{
			int random_index = rand() % (size-i);
			if (mas[i] > mas[random_index + i])
			{
				swap(mas[i], mas[random_index + i]);
				i = 0;
			}
			if (IsSorted(mas, size))
			{
				sorted = true;
				break;
			}
		}
	}
}

void QuickSort(int* mas, int size)
{
	if (size <= 1)
		return;
	int pivot = mas[size - 1];
	int bigger_index = 0, pivot_index = size - 1; // bigger_index is the index of the last met bigger than pivot element
	for (int i = 0; i < size - 1; i++)
	{
		if (mas[i] > pivot)
		{
			bigger_index = pivot_index = i; // if we won't find element less than pivot, it'll be true
			for (++i; i < size; i++) // go forward on elements 
			{
				if (mas[i] <= pivot)
				{
					swap(mas[bigger_index], mas[i]);
					if (i != size - 1) // than we already shared the massive on two parts with pivot on it's place
						pivot_index = ++bigger_index; // because all less elements went to the left regarding to pivot_index
				}
			}
		}
	}
	QuickSort(mas, pivot_index); // sort left part
	if (size > pivot_index + 1)
		QuickSort(&mas[pivot_index + 1], size - pivot_index - 1); // sort right part
}

int main()
{
	for (int i = 10; i <= 100000; i *= 10)
	{
		int size = i;
		int* mas = RandomMas(size);
		int* mas_cpy = mas;
		Timer sort_time;
		QuickSort(mas, size);
		cout << "Time for QuickSort for " << size << " elements = " << sort_time.elapsed() << endl;
		sort_time.reset();
		InsertionSort(mas_cpy, size);
		cout << "Time for InsertionSort for " << size << " elements = " << sort_time.elapsed() << endl;
		cout << endl;
	}
	return 0;
}