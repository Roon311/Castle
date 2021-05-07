#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template <class T> class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	int size;
public:

	LinkedList()//default constructor 
	{
		Head = nullptr;
		size = 0;
	}
	void InsertStart(const T& value)
	{
		Node<T>* temp = new Node<T>(value);//pointer pointing to a new node
		temp->setNext(Head);//set the head to be the next element 
		Head = temp;//head points to temp "repositioning"
		++size;
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
		++size;
	}
	bool Isempty()
	{
		if (Head == NULL && size == 0)
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
			--size;
		}
		
	}
	
	int getSize() const
	{
		return size;
	}
	~LinkedList()//destructor 
	{
		DeleteAll();
	}
};