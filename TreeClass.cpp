#include "pch.h"
#include "TreeClass.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TreeClass::TreeClass()
{
	head = nullptr;
}

TreeClass::~TreeClass()
{
	if (!is_empty())
	{
		Iterator * iterator = create_dft_iterator();
		TreeNode * before;
	while (iterator->has_next())
	{
		before = iterator->current;
		iterator->next();
		delete before;
	}
	delete iterator;
	}
	
}

void TreeClass::insert(int key) {
	if (head == nullptr) //���� ������ ������, ������ ������ �������
	{
		head = new TreeNode(key);

	}
	else
	{
		TreeNode * current = head;
		bool end = 0; //�������� �� �� ����� ������

		while (!end) { //��������� ���� �� �����, ��������� ���� ������ �������� � ������� � ������
			if (key < current->key)// ���� ��� ���� ������ ���������� ����� ������, �� ���������� �����
			{

				if (current->left != nullptr) //���� �� �������� �������, �� ���������� ����
					current = current->left;
				else // ���� ��������, ������ ����� �� ���� ������� � ����� ������ 
				{
					current->left = new TreeNode(key);
					current->left->up = current;
					end = 1;
				}

			}
			else // ���� ��� ���� ������ ��� ����� ���������� ����� ������, �� ���������� ������
			{

				if (current->right != nullptr) //���� �� �������� �������, �� ���������� ����
					current = current->right;
				else // ���� ��������, ������ ������ �� ���� ������� � ����� ������
				{
					current->right = new TreeNode(key);
					current->right->up = current;
					end = 1;
				}


			}
		}

	}
}

TreeNode::TreeNode(int key)
{
	this->key = key;
}

TreeNode::~TreeNode()
{
	left = nullptr;
	right = nullptr;
	up = nullptr;
}


void TreeClass::print_Tree(TreeNode * p, int level)
{
	if (p)
	{
		print_Tree(p->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "     ";
		cout << p->key << "<" << endl;
		print_Tree(p->left, level + 1);
	}
}



Iterator::Iterator()
{
}
Iterator::~Iterator()
{	
}

TreeClass::Dft_iterator::Dft_iterator(TreeClass* tree)
{
	if (tree->head == nullptr)
	{
		throw "Tree is empty";
	}
	else
	{
	current = tree->head; // ������ � ������ ������ �������� ������ ��� ������ ��������� ������ � �������
	while ((current->left != nullptr) || (current->right != nullptr))
	{
		if (current->left == nullptr)
		{
			current = current->right;
		}
		else
			current = current->left;
	}
	// ��������������� �������, ����� ������ ����� has_next() ��������� ������ ������� ���������
	
	/*
	TreeNode * temp = new TreeNode(0);
	temp->up = current;
	current = temp;
	*/
	}
}

TreeClass::Dft_iterator::~Dft_iterator()
{
	
}

bool TreeClass::Dft_iterator::has_next() 
{
	return (current != nullptr);
}
int TreeClass::Dft_iterator::next()
{
	int key = current->key;
	if (current->up) // ���� ���� ���� ����
	{

		if ((current->up->right != nullptr) && (current->up->right != current)) //���� ����� ������ �� ������ �����, �� ��������
		{
			current = current->up->right;
			while ((current->left != nullptr) || (current->right != nullptr)) // ��� � ����� ������ ������� ����� (�� ����������� �����)
			{
				if (current->left == nullptr)
				{
					current = current->right;
				}
				else
					current = current->left;
			}
		}
		else // ���� ������ ����� ���, ����������� �����
			current = current->up;
	}
	else // ���� ������ �� ������
		//throw "Tree is over";
		current = nullptr;

	return key; //���������� ���� ��������
}


Iterator * TreeClass::create_dft_iterator()
{
	Dft_iterator * dft_iterator = new Dft_iterator(this);
	return dft_iterator;
}


bool TreeClass::contains(int key)
{
	Iterator * iterator = create_dft_iterator(); // �������� ��������� � ������� (��������)
	//bool contains = 0; // �������� �� ������ ���� �������
	while (iterator->has_next()) // ���� �� ����� ��� �� ����������� ������
	{

		if (iterator->next() == key) // ���������� �������� � ���������� � ��������� ������
		{
			return true; // ���� ����� ������ ����
		}
	}
	return false;
	delete iterator;
}
/*
��� �� �������� � ������� � �� ������ ������ ������ ������� � �� ������������� ������
*/

void TreeClass::remove(int key)
{
	
	while (!is_empty()&&contains(key)) // ���� ����� ������� ���� � ������
	{
		bool found = 0; 
		Iterator * iterator = create_dft_iterator();
		while (iterator->has_next()) // ���� �� ����� ��� �� ����������� ������
		{
			
			if (iterator->current->key == key) // ���������� �������� � ���������� � ��������� ������
			{
				break; // ���� ����� ������ ����
			}
			iterator->next();
		}

		TreeNode* deleting_node = iterator->current;
		if ((deleting_node->left != nullptr) && (deleting_node->right != nullptr)) // ���� � ���������� ���� ��� ��������
		{
			TreeNode* left_stick = deleting_node->left;
			TreeNode* right_stick = deleting_node->right;
			//������������� ������ �������� 
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				right_stick->up = deleting_node->up; //��������� ���� ������ �������� ����� ����� � ������� ��������� ���������� ��������
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
				{
					deleting_node->up->right = right_stick; //������ ���������� ������ ����				
				}
				else // ���� ��� ����� ������� �������� ��������
					deleting_node->up->left = right_stick; //������ ���������� ������ ����
			}
			else // ���� ��������� ������� - ������
			{
				right_stick->up = nullptr;
				head = right_stick; // �������� ������ �������� ���������� �������
				

			}

				while (right_stick->left != nullptr) // ������� ����� ����� ������� ������ ��������
				{
					right_stick = right_stick->left;
				}
				right_stick->left = left_stick; //������������ ����� �������� � ����� ����� ������ ��������
				left_stick->up = right_stick;
			

			
		}
		else if (deleting_node->left != nullptr) // ���� ���� ������ ����� ��������
		{
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				TreeNode* left_stick = deleting_node->left;
				left_stick->up = deleting_node->up; //����������� ����� ����� ����� ����� � �������� �������� ���������� 
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
					deleting_node->up->right = left_stick; //����������� ����� ����� ������ ���� � �������� �������� ����������
				else
					deleting_node->up->left = left_stick; //����������� ����� ����� ������ ���� � �������� �������� ����������
			}
			else // ���� ��������� ������� - ������
			{ 
				head = deleting_node->left; //������ ������� �������� ���� ��������
				deleting_node->left->up = nullptr;
			}

		}
		else if (deleting_node->right != nullptr) // ���� ���� ������ ������ ��������
		{
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				TreeNode* right_stick = deleting_node->right;
				right_stick->up = deleting_node->up; //����������� ������ ����� ����� ����� � �������� �������� ���������� 
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
					deleting_node->up->right = right_stick; //����������� ������ ����� ������ ���� � �������� �������� ����������
				else
					deleting_node->up->left = right_stick; //����������� ������ ����� ������ ���� � �������� �������� ����������
			}
			else // ���� ��������� ������� - ������
			{
				head = deleting_node->right;  //������ ������� �������� ���� ��������
				deleting_node->right->up = nullptr;
			}
				
			
		}
		else // ���� ��� ��������
		{
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
					deleting_node->up->right = nullptr; //������� � ���� ����
				else
					deleting_node->up->left = nullptr;
			}
			else // ���� ��������� ������� - ������
				head = nullptr; //�������� ��������� �� ������
		}
					
		delete deleting_node;
		delete iterator;
		/*if (contains(key))
			remove(key);*/
	}
	/*else
		throw "No equal key";*/
	
}


//����������� �������� �������
Queue::QueueNode::QueueNode(TreeNode *node) {
	tree_node = node;
	next = nullptr;
}
//���������� �������� �������
Queue::QueueNode::~QueueNode() {
	tree_node = nullptr;
	next = nullptr;
}
//����������� �������
//Queue::Queue(TreeNode *node) {
//	tail = head = new QueueNode(node);
//	size = 1;
//}
//����������� ������ �������
Queue::Queue() {
	tail = head = nullptr;
}
//���������� �������
Queue::~Queue() {
	while (tail) {
		this->pop_front();
	}
}
//���������� �������� � ����� �������
void Queue::push_back(TreeNode *node) {
	if (head == nullptr)
		head = tail = new QueueNode(node);
	else {
		tail->next = new QueueNode(node);
		tail = tail->next;
	}
}
//�������� �������� � ������ �������
TreeNode* Queue::pop_front() {
	TreeNode* temp = head->tree_node;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	return temp;
}
//�������� ��������� ��� ������ � ������
Iterator* TreeClass::create_bft_iterator() {
	Bft_iterator * bft_iterator = new Bft_iterator(this);
	return bft_iterator;
}
//����������� ��������� ������ � ������
TreeClass::Bft_iterator::Bft_iterator(TreeClass *tree) {
	current = tree->head;
	tree_Queue->push_back(current);
}
//���������� ��������� ������ � ������
TreeClass::Bft_iterator::~Bft_iterator() {
	current = nullptr;
	delete tree_Queue;
	tree_Queue = nullptr;
}
//���������������� ������� �������� � ���������� ��������
int TreeClass::Bft_iterator::next() {
	if (!has_next()) { //
		throw out_of_range("The next element does not exist!");
	}
	int key = current->key; //��������� ����� �������� ����
	if (current->left)
		tree_Queue->push_back(current->left); //���������� � ������� ������ ������� �������� ����
	if (current->right)
		tree_Queue->push_back(current->right); //���������� � ������� ������� ������� �������� ����
	if (tree_Queue->head->next)
		current = tree_Queue->head->next->tree_node; //������� � ���������� �������� � �������
	else
		current = nullptr;
	tree_Queue->pop_front(); //�������� �������� �� �������
	return key;
}

bool TreeClass::Bft_iterator::has_next() {
	return current != nullptr;
}

bool TreeClass::is_empty()
{
	return head == nullptr;
}

int TreeNode::get_key()
{
	return key;
}





void TreeClass::tree_sort_rec(TreeNode* head, Queue* tree_node_queue)
{
	if (head) { //���� �� ���������� ������ ����
		tree_sort_rec(head->left, tree_node_queue);  //����������� ������� ������ ������ ���������
		tree_node_queue->push_back(head); //������ �������� � ������
		tree_sort_rec(head->right, tree_node_queue); //����������� ������� ������ ������� ���������
	}
}
//���������� ������� � ������� ��������� ������ ������
void TreeClass::Tree_Sort(int* arr, size_t arr_size) {
	TreeClass* Tree = arr_to_tree(arr, arr_size); //�������� ������
	Queue* tree_node_queue = new Queue(); //�������� �������
	tree_sort_rec(Tree->head, tree_node_queue); //����� ����������� ������� ���������� � �������
	//tree_node_queue->pop_front(); //�������� �� ������� ������� �������� 
	//(����� ������, ������� ��������� ������, �� - �� �������� ������� � ������������ ������ ����������� ������� � ����� � ��� �� ���������)
	for (int i = 0; i < arr_size; i++) //�������� ������ �� ������� � ������
	{
		TreeNode * temp = tree_node_queue->pop_front();
		arr[i] = temp->get_key();
	}


	delete Tree;
	delete tree_node_queue;
}
//������� �������� ������ �� �������
TreeClass* TreeClass::arr_to_tree(int* arr, size_t arr_size) {
	TreeClass* Tree = new TreeClass;
	for (int i = 0; i < arr_size; i++) {
		Tree->insert(arr[i]);
	}
	return Tree;
}