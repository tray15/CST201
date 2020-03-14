//Lydia K Fritz
//2/14/2019
//Provided C++ DLinkedList

#pragma once

#ifndef DLINKLIST_H
#define DLINKLIST_H

#include <iostream>

using namespace std;

template <class T>
class DLinkedList {

	//PROVIDED
	friend ostream& operator<<(ostream& out, const DLinkedList<T>& rhs) {
		DNode* curr = rhs.header->next;
		while (curr != rhs.header) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:

	//inner class DNode PROVIDED
	class DNode {
	public:
		DNode* next;
		DNode* prev;
		T data;

		DNode(T val = T()) {
			data = val;
			next = prev = this;
		}

	};

	//create an empty list:  PROVIDED
	DLinkedList() {
		//create the header
		header = new DNode();
	}

	//add method  PROVIDED
	DNode* add(T item) {
		//add a new node and return a 
		//pointer to this node
		DNode* newNode = new DNode(item);
		newNode->prev = header;
		newNode->next = header->next;
		header->next->prev = newNode;
		header->next = newNode;
		return newNode;
	};

	/**
	* ASSIGNED
	* remove val from the list
	*
	* @param val
	* @return true if successful, false otherwise
	*/
	bool remove(T value)
	{
		auto curr = this->header;
		auto prev = this->tail;

		while (curr != nullptr)
		{
			if (curr->data == value)
			{
				// this is the node we want to remove
				// get the next node so we can set it's prev
				auto next = curr->next;
				next->prev = prev;

				// set prev next to the next node
				prev->next = next;

				//free curr from memory
				free(curr->prev);
				free(curr->next);

				return true;
			}

			// set prev to curr
			prev = curr;
			// advance one
			curr = curr->next;
		}
	}


	/**
	* ASSIGNED
	*
	* @param item
	*/
	void insertOrder(T item) {
		auto temp = new DNode();
		temp->data = item;
		auto curr = this->header;

		if (this->header == nullptr || this->header->data >= temp->data) {
			temp->next = this->header;
			this->header = temp;
		}
		else {
			while (curr->next != nullptr && curr->next->data < temp->data) {
				curr = curr->next;
			}
			temp->next = curr->next;
			curr->next = temp;
		}
	}

	/**
	* ASSIGNED
	*
	* @param item
	*/
	bool insertOrderUnique(T item)
	{
		// handle if nothing has been added to the list
		if (this->header == nullptr)
		{
			this->header = new DNode();
			this->header->data = item;
			this->header->next = nullptr;

			this->tail = this->header;

			return true;
		}

		auto curr = this->header;
		auto prev = this->tail;

		// check each item
		while (curr != nullptr && curr->data < item)
		{
			prev = curr;
			curr = curr->next;
		}

		// if we made it to the end of the list, we can just insert it there
		if (curr == nullptr)
		{
			curr = new DNode();
			curr->data = item;
			curr->prev = prev;
			curr->next = nullptr;

			return true;
		}

		// we got to here, so curr is not at the end, we need to check to see if curr is equal 
		if (curr->data == item)
			return false;

		// ok so now the last use case is, we need to insert the item between prev and current since current is not < item
		auto temp = new DNode();
		temp->data = item;
		temp->prev = prev;
		temp->next = curr;

		// creeated node, update the list
		curr->prev = temp;
		prev->next = temp;
	}

	/**
	* ASSIGNED
	* PRE:  this and rhs are sorted lists
	* @param rhs
	* @return list that contains this and rhs merged into a sorted list
	* POST:  returned list will not contain duplicates, both rhs and this
	* will have no elements
	*/
	DLinkedList merge(DLinkedList rhs) {
		DLinkedList result;
		return result;
	}


private:
	//DLinkedList fields:  PROVIDED
	DNode* header;
	DNode* tail;
};


#endif