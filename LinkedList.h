#define _CRT_SECURE_NO_WARNINGS
#ifndef LinkedList_H
#define LinkedList_H

// Nodes used for linking objects together
struct Node
{
	void* data_;

	Node* next_;
	Node* prev_;

	Node()
	{
		data_ = 0;
		next_ = 0;
		prev_ = 0;
	}
};

// Class for managing the linked list
class LinkedList
{
private:
	Node* first_;
	Node* last_;
	long listLen_;
public:
	LinkedList();
	~LinkedList();
	void* GetFirstNode();
	long GetListLength();
	void AddLinkToBack(void *ptr);
	void* RemoveThisLink(Node* node);
	void* RemoveLinkFromFront();
};
#endif