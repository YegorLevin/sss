#pragma once
#include "TreeNode.h"
#include"Iterator.h"
#include "QueueClass.h"	


	
	class TreeClass
	{
	private:
		

		class Dft_iterator : public Iterator // ����� ��������� ��������� ������ � �������
		{
		public:
			Dft_iterator(TreeClass* tree);
			~Dft_iterator();
			int next() override;
			bool has_next() override;
			
			
		private:
			

		};

		//����� ��������� ��� ������ � ������
		class Bft_iterator : public Iterator //��������� �� ������ ��������
		{
		public:
			Bft_iterator(TreeClass* tree);
			~Bft_iterator(); //�� ����, ��������� �� ���������
			int next() override; //
			bool has_next() override; //
			Queue* tree_Queue = new Queue;

		};

		TreeNode * head;

	public:
		
		//friend void Tree_Sort(int* arr, int arr_size); //���������� ������� � ������� ��������� ������ ������

		TreeClass();
		~TreeClass();
		void print_Tree(TreeNode * p, int level = 0);


	void Tree_Sort(int* arr, size_t arr_size);
	TreeClass* arr_to_tree(int* arr, size_t arr_size);
	void tree_sort_rec(TreeNode* head, Queue* tree_node_queue);


	void insert(int); // ���������� �������� � ������ �� �����
	bool contains(int); // ����� �������� � ������ �� �����
	void remove(int); // �������� �������� ������ �� �����
	Iterator * create_dft_iterator(); // �������� ���������, ������������ ������ ������ � ������� (depth-first traverse)
	Iterator * create_bft_iterator(); // �������� ���������, ������������ ������ ������ � ������
	bool is_empty();

};


	
