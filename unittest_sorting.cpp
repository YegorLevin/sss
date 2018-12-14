#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab4/Sorting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Sorting
{		
	TEST_CLASS(TreeSortTests)
	{
	public:
		size_t size = 10;
		int * arr;
		int * right_arr;
		TEST_METHOD_INITIALIZE(SetUp)
		{
			arr = new int[size];
			right_arr = new int[size];
		}
		TEST_METHOD_CLEANUP(CleanUp)
		{
			delete arr;
			delete right_arr;
		}
		
		TEST_METHOD(TreeSortNormalTest)
		{
			for (size_t i = 0; i < size; ++i)
			{
				arr[i] = size-1-i;
				right_arr[i] = i;
	
			}
			
			treeSort(arr, size);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(arr[i] == right_arr[i]);
			
		
		}

		TEST_METHOD(TreeSortEqualElemsTest)
		{
			for (size_t i = 0; i < size; ++i)
			{
				arr[i] = size - 1 - i;
				right_arr[i] = i;

			}
			arr[size - 2] = 1;
			arr[size - 1] = 1;
			right_arr[0] = 1;
			right_arr[1] = 1;

			treeSort(arr, size);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(arr[i] == right_arr[i]);

		
		}

		TEST_METHOD(TreeSortOneElemTest)
		{
			int oneElemArr[1] = { 1 };
			int oneElemRightArr[1] = { 1 };
			size = 1;

			treeSort(oneElemArr, size);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(oneElemArr[i] == oneElemRightArr[i]);

			
		}

		TEST_METHOD(TreeSortEmptyTest)
		{
			int * emptyArr = new int[0];
			try
			{
				treeSort(emptyArr,size);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "TheArrayIsEmpty");
			}
		}



	};

	
	TEST_CLASS(QuickSortTests)
	{
	public:

		size_t size = 10;
		int * arr;
		int * right_arr;
		TEST_METHOD_INITIALIZE(SetUp)
		{
			arr = new int[size];
			right_arr = new int[size];
		}
		TEST_METHOD_CLEANUP(CleanUp)
		{
			delete arr;
			delete right_arr;
		}

		//Тест последовательности с одинаковыми элементами
		TEST_METHOD(QuickSortEqualElemsTest)
		{
			for (size_t i = 0; i < size; ++i)
			{
				arr[i] = size - 1 - i;
				right_arr[i] = i;

			}
			arr[size - 2] = 1;
			arr[size - 1] = 1;
			right_arr[0] = 1;
			right_arr[1] = 1;

			quickSort(arr, 0, size - 1);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(arr[i] == right_arr[i]);
			
		}
		
		//Обычный тест неупорядоченной последовательности
		TEST_METHOD(QuickSortNormalTest)
		{
			for (size_t i = 0; i < size; ++i)
			{
				arr[i] = size - 1 - i;
				right_arr[i] = i;

			}

			quickSort(arr, 0, size - 1);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(arr[i] == right_arr[i]);

		}

		
		//Сортировка массива с одним элементом
		TEST_METHOD(QuickSortOneElemTest)
		{
			int oneElemArr[1] = { 1 };
			int oneElemRightArr[1] = { 1 };
			size = 1;

			quickSort(oneElemArr,0, size-1);

			//for (int i = 0; i < size; i++)
				Assert::IsTrue(oneElemArr[0] == oneElemRightArr[0]);
		}

		//Тест пустой последовательности
		TEST_METHOD(QuickSortEmptyTest)
		{
			int * emptyArr = new int[0];
			try
			{
				quickSort(emptyArr, 0, size - 1);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "TheArrayIsEmpty");
			}
		}

		//Тест правая граница меньше левой
		
		TEST_METHOD(QuickSortLeftMoreRightTest)
		{
			try
			{
				quickSort(arr, size - 1, 0);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "TheArrayIsEmpty");
			}
		}
		
		
	};

	

	TEST_CLASS(CountingSortTests)
	{
	public:

		size_t size = 10;
		char * arr;
		char * right_arr;
		TEST_METHOD_INITIALIZE(SetUp)
		{
			arr = new char[size];
			right_arr = new char[size];
		}
		TEST_METHOD_CLEANUP(CleanUp)
		{
			delete arr;
			delete right_arr;
		}

		//Тест последовательности с одинаковыми элементами
		TEST_METHOD(CountingSortEqualElemsTest)
		{
			for (size_t i = 0; i < size; ++i)
			{
				arr[i] = size - 1 - i;
				right_arr[i] = i;

			}

			arr[size - 2] = 1;
			arr[size - 1] = 1;
			right_arr[0] = 1;
			right_arr[1] = 1;

			countingSort(arr, size);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(arr[i] == right_arr[i]);
		}

		//Обычный тест неупорядоченной последовательности
		TEST_METHOD(CountingSortNormalTest)
		{
			for (size_t i = 0; i < size; ++i)
			{
				arr[i] = size - 1 - i;
				right_arr[i] = i;

			}

			countingSort(arr, size);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(arr[i] == right_arr[i]);

		}

		//Сортировка массива с одним элементом
		TEST_METHOD(CountingSortOneElemTest)
		{
			char oneElemArr[1] = { 1 };
			char oneElemRightArr[1] = { 1 };
			size = 1;

			countingSort(oneElemArr, size);

			//for (int i = 0; i < size; i++)
			Assert::IsTrue(oneElemArr[0] == oneElemRightArr[0]);
		}

		//Тест пустой последовательности
		TEST_METHOD(CountingSortEmptyTest)
		{
			char * emptyArr = new char[0];
			try
			{
				countingSort(emptyArr, size);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "TheArrayIsEmpty");
			}
		}

	};


	TEST_CLASS(BinarySearchTests)
	{
	public:

		size_t size = 20;
		int * a = new int[size];

		//Поиск индексов входящих элементов
		TEST_METHOD(BinarySearchContainedTest)
		{
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			quickSort(a, 0, size - 1);

			for (size_t i = 1; i < size; ++i)
				Assert::IsTrue(binarySearch(size, a, i) == i);
		}

		//Поиск индексов не входящих элементов
		TEST_METHOD(BinarySearchNotContainedTest)
		{
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			quickSort(a, 0, size - 1);

			try
			{
				binarySearch(size, a, size + 1);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "ElemNotFound");
			}
		}

		//Поиск индекса в последовательности из одного элемента
		TEST_METHOD(BinarySearchOneElemTest)
		{
			size = 1;
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			quickSort(a, 0, size - 1);

			for (size_t i = 1; i < size; ++i)
				Assert::IsTrue(binarySearch(size, a, i) == i);
		}

		//Поиск индекса в пустой последовательности
		TEST_METHOD(BinarySearchEmptyTest)
		{
			try
			{
				delete[] a;
				binarySearch(size, a, size + 1);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "ElemNotFound");
			}
		}
	};
	TEST_CLASS(insertionSortTests)
	{
	public:
		size_t size = 20;
		int * a = new int[size];

		TEST_METHOD(insertionSortNormalTest)
		{
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			insertionSort(a, size);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(i == a[i]);
		}

		TEST_METHOD(insertionSortOneElemTest)
		{
			size = 1;
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			insertionSort(a, size);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(i == a[i]);
		}

		TEST_METHOD(insertionSortEqualElemsTest)
		{
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			a[size - 2] = 1;
			a[size - 1] = 1;

			insertionSort(a, size);

			for (size_t i = 2; i < size; ++i)
				Assert::IsTrue(i == a[i]);
			Assert::IsTrue(a[0] == 1 && a[1] == 1);
		}

		TEST_METHOD(insertionSortEmptyTest)
		{
			int * emptyArr = new int[0];
			try
			{
				insertionSort(emptyArr, size);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "TheArrayIsEmpty");
			}
		}
	};

	
	TEST_CLASS(BogoSortTests)
	{
	public:

		size_t size = 3;
		int * a = new int[size];

		//Тест последовательности с одинаковыми элементами

		TEST_METHOD(BogoSortEqualElemsTest)
		{
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			a[size - 2] = 1;
			a[size - 1] = 1;

			bogoSort(a, size);

			for (size_t i = 2; i < size; ++i)
				Assert::IsTrue(i == a[i]);
			Assert::IsTrue(a[0] == 1 && a[1] == 1);
		}

		//Обычный тест неупорядоченной последовательности
		TEST_METHOD(BogoSortNormalTest)
		{
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			bogoSort(a, size);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(i == a[i]);
		}

		//Сортировка массива с одним элементом
		TEST_METHOD(BogoSortOneElemTest)
		{
			size = 1;
			int k = size - 1;
			for (size_t i = 0; i < size; ++i)
			{
				a[i] = k;
				--k;
			}

			bogoSort(a, size);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(i == a[i]);
		}

		//Тест пустой последовательности
		TEST_METHOD(BogoSortEmptyTest)
		{
			int * emptyArr = new int[0];
			try
			{
				bogoSort(emptyArr, size);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "TheArrayIsEmpty");
			}
		}



	};
		
}