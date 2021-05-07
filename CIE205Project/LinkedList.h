#pragma once
#include <iostream>
#include "Generic_DS/Node.h"
using namespace std;
template <class T> class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list

public:

	LinkedList()//default constructor 
	{
		Head = nullptr;
	}
	void InsertStart(const T& value)
	{
		Node<T>* temp = new Node<T>(value);//pointer pointing to a new node
		temp->setNext(Head);//set the head to be the next element 
		Head = temp;//head points to temp "repositioning"
	}
	void InsertEnd(const T& value)
	{
		Node<T>* Noder = new Node<T>(value);//pointer pointing to a new node
		Node<T>* temp = Head;
		while (temp->getNext())
		{
			temp = temp->getNext();
		}
		temp->setNext(Noder);
	}
	bool Isempty()
	{
		if (Head == NULL)
			return true;
		else return false;
	}
	void DeleteAll()//delete all nodes
	{
		Node<T>* P = Head;//pointer pointing to head 
		while (Head)//as long as head is not pointing to NULL
		{
			P = Head->getNext();//move the pointer to next node
			delete Head;//delete the old head
			Head = P;//set the head pointer to the next node
		}
	}
	const T* toArray(int& count) {
		count = 0;
		if (Head == nullptr)
			return nullptr;

		Node<T>* p = Head;
		while (p != nullptr) {
			p = p->getNext();
			++count;
		}
		T* array = new T[count];
		p = Head;
		for (int i = 0; i < count; i++) {
			array[i] = p->getItem();
			p = p->getNext();
		}
		return array;
	}

	~LinkedList()//destructor 
	{
		DeleteAll();
	}
};
