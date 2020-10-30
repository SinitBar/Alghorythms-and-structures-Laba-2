#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/varka/source/repos/BinSearchAndSorts/Sorts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBinSearchAndSorts
{
	TEST_CLASS(UnitTestBinSearchAndSorts)
	{
	public:
		
		TEST_METHOD(BinarySearchTestFirstElement)
		{
			int array[3];
			array[0] = 1; array[1] = 3; array[2] = 5;
			Assert::AreEqual(BinarySearch(array, 3, 1), 0);
		}
		TEST_METHOD(BinarySearchTestLastElement)
		{
			int array[3];
			array[0] = 1; array[1] = 3; array[2] = 5;
			Assert::AreEqual(BinarySearch(array, 3, 5), 2);
		}
		TEST_METHOD(BinarySearchTestMiddleElement)
		{
			int array[3];
			array[0] = 1; array[1] = 3; array[2] = 5;
			Assert::AreEqual(BinarySearch(array, 3, 3), 1);
		}
		TEST_METHOD(BinarySearchTestNotExistingElement)
		{
			int array[3];
			array[0] = 1; array[1] = 3; array[2] = 5;
			Assert::AreEqual(BinarySearch(array, 3, 6), 3);
		}
		TEST_METHOD(BinarySearchTestOneElement)
		{
			int array[1];
			array[0] = 1;
			Assert::AreEqual(BinarySearch(array, 1, 1), 0);
		}
		TEST_METHOD(InsertionSortTestOneElements)
		{
			int array[1];
			array[0] = 1;
			InsertionSort(array, 1);
			Assert::AreEqual(IsSorted(array, 1), true);
		}
		TEST_METHOD(InsertionSortTestTenElement)
		{
			int* array = RandomArray(10);
			InsertionSort(array, 10);
			Assert::AreEqual(IsSorted(array, 10), true);
		}
		TEST_METHOD(InsertionSortTestOneHundredElement)
		{
			int* array = RandomArray(100);
			Timer sort_time;
			InsertionSort(array, 100);
			double time_InsertionSort = sort_time.elapsed();
			Assert::AreEqual(IsSorted(array, 100), true);
		}
		TEST_METHOD(InsertionSortTestOneThousandElement)
		{
			int* array = RandomArray(1000);
			InsertionSort(array, 1000);
			Assert::AreEqual(IsSorted(array, 1000), true);
		}
		TEST_METHOD(InsertionSortTestTenThousandsElement)
		{
			int* array = RandomArray(10000);
			InsertionSort(array, 10000);
			Assert::AreEqual(IsSorted(array, 10000), true);
		}
		TEST_METHOD(InsertionSortTestHundredThousandsElement)
		{
			int* array = RandomArray(100000);
			InsertionSort(array, 100000);
			Assert::AreEqual(IsSorted(array, 100000), true);
		}
		TEST_METHOD(BogoSortTestElements)
		{
			int* array = RandomArray(10);
			BogoSort(array, 10);
			Assert::AreEqual(IsSorted(array, 10), true);
		}
		TEST_METHOD(BogoSortTestOneElements)
		{
			int* array = RandomArray(1);
			BogoSort(array, 1);
			Assert::AreEqual(IsSorted(array, 1), true);
		}
		TEST_METHOD(CountingSortTestOneElement)
		{
			unsigned char* char_array = RandomCharArray(1);
			CountingSort(char_array, 1);
			Assert::AreEqual(IsSorted(char_array, 1), true);
		}
		TEST_METHOD(CountingSortTestElements)
		{
			unsigned char* char_array = RandomCharArray(10);
			CountingSort(char_array, 10);
			Assert::AreEqual(IsSorted(char_array, 10), true);
		}
		TEST_METHOD(CountingSortTestManyElements)
		{
			unsigned char* char_array = RandomCharArray(100000);
			CountingSort(char_array, 100000);
			Assert::AreEqual(IsSorted(char_array, 100000), true);
		}
		TEST_METHOD(QuickSortTestOneElement)
		{
			int* array = RandomArray(1);
			QuickSort(array, 1);
			Assert::AreEqual(IsSorted(array, 1), true);
		}
		TEST_METHOD(QuickSortTestElements)
		{
			int* array = RandomArray(1000);
			QuickSort(array, 1000);
			Assert::AreEqual(IsSorted(array, 1000), true);
		}
		TEST_METHOD(QuickSortTestManyElements)
		{
			int* array = RandomArray(100000);
			QuickSort(array, 100000);
			Assert::AreEqual(IsSorted(array, 100000), true);
		}
	};
}
