#pragma once
#include"Node.h"
template < typename T>
class Priority_queue
{
	Node<T> * front;
	int size;
public:
	Priority_queue();
	bool isEmpty() const;
	int getSize() const;
	Node<T>* top();
	void push(T elemnt);
	void pop();
	const T* toArray(int& count);
};


