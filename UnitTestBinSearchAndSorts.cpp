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
			int mas[3];
			mas[0] = 1; mas[1] = 3; mas[2] = 5;
			Assert::AreEqual(BinarySearch(mas, 3, 1), 0);
		}
		TEST_METHOD(BinarySearchTestLastElement)
		{
			int mas[3];
			mas[0] = 1; mas[1] = 3; mas[2] = 5;
			Assert::AreEqual(BinarySearch(mas, 3, 5), 2);
		}
		TEST_METHOD(BinarySearchTestMiddleElement)
		{
			int mas[3];
			mas[0] = 1; mas[1] = 3; mas[2] = 5;
			Assert::AreEqual(BinarySearch(mas, 3, 3), 1);
		}
		TEST_METHOD(BinarySearchTestNotExistingElement)
		{
			int mas[3];
			mas[0] = 1; mas[1] = 3; mas[2] = 5;
			Assert::AreEqual(BinarySearch(mas, 3, 6), 3);
		}
		TEST_METHOD(BinarySearchTestOneElement)
		{
			int mas[1];
			mas[0] = 1;
			Assert::AreEqual(BinarySearch(mas, 1, 1), 0);
		}
		TEST_METHOD(InsertionSortTestOneElements)
		{
			int mas[1];
			mas[0] = 1;
			InsertionSort(mas, 1);
			Assert::AreEqual(IsSorted(mas, 1), true);
		}
		TEST_METHOD(InsertionSortTestTenElement)
		{
			int* mas = RandomMas(10);
			InsertionSort(mas, 10);
			Assert::AreEqual(IsSorted(mas, 10), true);
		}
		TEST_METHOD(InsertionSortTestOneHundredElement)
		{
			int* mas = RandomMas(100);
			Timer sort_time;
			InsertionSort(mas, 100);
			double time_InsertionSort = sort_time.elapsed();
			Assert::AreEqual(IsSorted(mas, 100), true);
		}
		TEST_METHOD(InsertionSortTestOneThousandElement)
		{
			int* mas = RandomMas(1000);
			InsertionSort(mas, 1000);
			Assert::AreEqual(IsSorted(mas, 1000), true);
		}
		TEST_METHOD(InsertionSortTestTenThousandsElement)
		{
			int* mas = RandomMas(10000);
			InsertionSort(mas, 10000);
			Assert::AreEqual(IsSorted(mas, 10000), true);
		}
		TEST_METHOD(InsertionSortTestHundredThousandsElement)
		{
			int* mas = RandomMas(100000);
			InsertionSort(mas, 100000);
			Assert::AreEqual(IsSorted(mas, 100000), true);
		}
		TEST_METHOD(BogoSortTestElements)
		{
			int* mas = RandomMas(10);
			BogoSort(mas, 10);
			Assert::AreEqual(IsSorted(mas, 10), true);
		}
		TEST_METHOD(BogoSortTestOneElements)
		{
			int* mas = RandomMas(1);
			BogoSort(mas, 1);
			Assert::AreEqual(IsSorted(mas, 1), true);
		}
		TEST_METHOD(CountingSortTestOneElement)
		{
			unsigned char* mas = RandomCharMas(1);
			CountingSort(mas, 1);
			Assert::AreEqual(IsSorted(mas, 1), true);
		}
		TEST_METHOD(CountingSortTestElements)
		{
			unsigned char* mas = RandomCharMas(10);
			CountingSort(mas, 10);
			Assert::AreEqual(IsSorted(mas, 10), true);
		}
		TEST_METHOD(CountingSortTestManyElements)
		{
			unsigned char* mas = RandomCharMas(100000);
			CountingSort(mas, 100000);
			Assert::AreEqual(IsSorted(mas, 100000), true);
		}
		TEST_METHOD(QuickSortTestOneElement)
		{
			int* mas = RandomMas(1);
			QuickSort(mas, 1);
			Assert::AreEqual(IsSorted(mas, 1), true);
		}
		TEST_METHOD(QuickSortTestElements)
		{
			int* mas = RandomMas(1000);
			QuickSort(mas, 1000);
			Assert::AreEqual(IsSorted(mas, 1000), true);
		}
		TEST_METHOD(QuickSortTestManyElements)
		{
			int* mas = RandomMas(100000);
			QuickSort(mas, 100000);
			Assert::AreEqual(IsSorted(mas, 100000), true);
		}
	};
}
