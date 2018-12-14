#include "pch.h"
#include "Sorting.h"
#include <random>
#include <ctime>
#include "../../alg_lab3/alg_lab3/TreeClass.h"



size_t binarySearch(size_t arraySize, int * array, int elem) //�������� �����
{

	size_t first = 0;//������ ������� �������

	size_t size = arraySize; //������ �������


	if (array == nullptr || arraySize == 0) //���� ������ ����
		throw "TheArrayIsEmpty";

	else if (array[0] > elem || array[arraySize - 1] < elem) //���� ������� ������� ������ ��� ������ ���� ��������� ������� 
		throw "ElemNotFound";






	while (first < size) //����� � ����������� ���������
	{

		size_t mid = first + (size - first) / 2; //�������� ���������

		if (elem <= array[mid])
			size = mid;
		else
			first = mid + 1;
	}

	if (array[size] == elem)
		return size;
	else
		throw "ElemNotFound";
}




void quickSort(int * array, size_t left, size_t right) //������� ����������
{

	if (array == nullptr || left > right) //���� ������ ����
		throw "TheArrayIsEmpty";

	int pivot; // ����������� �������
	size_t l_hold = left; // ����� �������
	size_t r_hold = right; // ������ �������
	pivot = array[left];

	while (left < right) // ���� ������� �� ���������
	{
		while ((array[right] >= pivot) && (left < right))
			--right; // �������� ������ ������� ���� ������� [right] ������ [pivot]

		if (left != right) // ���� ������� �� ����������
		{
			array[left] = array[right]; // ���������� ������� [right] �� ����� ������������
			++left; // �������� ����� ������� ������ 
		}

		while ((array[left] <= pivot) && (left < right))
			++left; // �������� ����� ������� ���� ������� [left] ������ [pivot]

		if (left != right) // ���� ������� �� ����������
		{
			array[right] = array[left]; // ���������� ������� [left] �� ����� [right]
			--right; // �������� ������ ������� ������ 
		}
	}

	array[left] = pivot; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		quickSort(array, left, pivot - 1);
	if (right > pivot)
		quickSort(array, pivot + 1, right);
}



void quickSort(int * array, size_t right) //������� ����������
{
	quickSort(array, 0, right);
}

bool is_sorted(int * array, size_t size)
{
	bool is_sorted = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			is_sorted = 0;
	}
	return is_sorted;
}

void bogoSort(int* array, size_t size) {
	if (array == nullptr || size == 0)
		throw "Array is empty";

	while (!is_sorted(array, size)) {
		for (int i = 0; i < size; i++) {
			srand(time(0));
			int index1 = rand() % size;
			int index2 = rand() % size;
			int temp = array[index1];
			array[index1] = array[index2];
			array[index2] = temp;
		}
	}
}



void countingSort(char * array, size_t arraySize) { //���������� ���������


	if (array == nullptr || arraySize == 0)	//���� ������ ����
		throw "TheArrayIsEmpty";

	int min, max;
	min = max = array[0];
	for (size_t index = 1; index < arraySize; index++) {
		if (array[index] > max) max = array[index];
		if (array[index] < min) min = array[index];
	}

	int * counter = new int[max - min + 1];

	for (int i = min; i <= max; ++i)
		counter[i - min] = 0;

	for (int i = 0; i < arraySize; ++i)
		++counter[array[i] - min];

	for (int i = min; i <= max; ++i)
		for (int j = counter[i - min]; j--;)
			*array++ = i;

	delete[] counter;
}


void insertionSort(int array[], size_t size) // c��������� ��������� 
{
	if (array == nullptr || size == 0)	//���� ������ ����
		throw "TheArrayIsEmpty";

	for (int i = size - 1; i > 0; i--) // ���������� ������������ �������� � ��������� ��� � ������ 
		if (array[i] < array[i - 1])
		{
			int temp = array[i - 1];
			array[i - 1] = array[i];
			array[i] = temp;
		}

	// ���������� ��������
	for (int i = 2; i < size; i++)
	{
		int j = i;
		int cur = array[j];
		while (array[j - 1] > cur) //���� ����� ���� �������� �������
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = cur; // ������� ��������
	}
}		

void treeSort(int* arr, size_t arr_size)
{
	if (arr == nullptr || arr_size == 0)	//���� ������ ����
		throw "TheArrayIsEmpty";

	TreeClass * tree = new TreeClass;
	tree->Tree_Sort(arr, arr_size);
}