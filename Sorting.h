#pragma once
#include "../../alg_lab3/alg_lab3/TreeClass.h"


using namespace std;

void quickSort(int *, size_t, size_t); //������� ����������
void quickSort(int * array, size_t right);
void insertionSort(int[], size_t); // c��������� ��������� 
//void TreeSort(int[],size_t); 
size_t binarySearch(size_t, int *, int); //�������� �����
void countingSort(char *, size_t); //���������� ���������
void bogoSort(int *, size_t); //������ ����������
void treeSort(int* arr, size_t arr_size);

//void Tree_Sort(int* arr, int arr_size); // c��������� � ������� ��������� ������
//TreeClass* arr_to_tree(int* arr, int arr_size);
//void tree_sort_rec(TreeNode* head, Queue* tree_node_queue);


//int treeSort(TreeNode * head, int * array1, int number = 0); 
//void treeSortHelper(int * array1, size_t size);
