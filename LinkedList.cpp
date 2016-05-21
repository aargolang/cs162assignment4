#include "LinkedList.h"

// constructors and destructors
LinkedList::LinkedList() {
	first_ = 0;
	last_ = 0;
	listLen_ = 0;
}
LinkedList::~LinkedList() {
	first_ = 0;
	last_ = 0;
	listLen_ = 0;
}

// getters 
void* LinkedList::GetFirstNode() {
	return	first_;
}
long LinkedList::GetListLength() {
	return listLen_;
}

// Utility functions
void LinkedList::AddLinkToBack(void *ptr) {
	// Add Links To the end/back/last-link
	Node *newNode = new Node;
	newNode->data_ = ptr;
	newNode->next_ = 0;
	if (listLen_ < 1) {
		first_ = newNode;
		last_ = newNode;
	}
	else {
		last_->next_ = newNode;
		last_->next_->prev_ = last_;
		last_ = newNode;
	}
	listLen_++;
}
void* LinkedList::RemoveThisLink(Node* node){
	void* deleteMe;
	if ((node->prev_ == 0) && (node->next_ == 0)) {
		deleteMe = first_;
		first_ = 0;
		last_ = 0;
	}
	else if (node->prev_ == 0) {
		deleteMe = first_;
		first_->next_->prev_ = 0;
		first_ = first_->next_;
	}
	else if (node->next_ == 0) {
		deleteMe = last_;
		last_->prev_->next_ = 0;
		last_ = last_->prev_;
	}
	else {
		deleteMe = node;
		node->next_->prev_ = node->prev_;
		node->prev_->next_ = node->next_;
		node->next_ = 0;
		node->prev_= 0;
	}
	listLen_--;
	return deleteMe;
}
void* LinkedList::RemoveLinkFromFront() {
	// Remove Links and nodes from the front/head/first-link
	if (listLen_ < 1) {
		return 0;
	}
	else if (listLen_ < 2) {
		void* deleteMe = first_->data_;
		first_->next_ = 0;
		listLen_--;
		return deleteMe;
	}
	else {
		void* deleteMe = first_->data_;
		first_ = first_->next_;
		listLen_--;
		return deleteMe;
	}
}
