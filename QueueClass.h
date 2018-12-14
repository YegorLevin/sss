#pragma once
#include "TreeClass.h"
class TreeClass;

class Queue {


public:
	//friend void tree_sort_rec(TreeNode* head, Queue* tree_node_queue);
	friend TreeClass;
	Queue();
	~Queue(); //���������� �� ������, ����� �� ��
	/*Queue(TreeNode *node);*/
	void push_back(TreeNode *node); //
	TreeNode* pop_front(); //


private:
	class QueueNode {
	public:
		friend Queue;
		friend TreeClass;
		
		QueueNode(TreeNode *node);
		~QueueNode(); //���������� �� ������, ����� �� ��
	private:
		TreeNode *tree_node;
		QueueNode *next;
	};
	QueueNode *head; 
	QueueNode *tail; 

};

