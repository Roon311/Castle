#ifndef STACK_H
#define STACK_H

#include "Generic_DS\Node.h"
//..\CIE205Project_Code_S2021\*/
template <typename T>
class Stack
{
private:
	Node<T>* top;

public:
	Stack();
	~Stack();
	 bool Isempty() const;
	bool Push(const T& newItem);
	bool Pop(T& TopItem);
	bool Peek(T& TopItem) const;
};

template <typename T>
Stack<T>::Stack()
{
	top = nullptr;
}

template <typename T>
bool  Stack<T>::Isempty() const
{
	if (top == nullptr)
		return true;
	else
		return false;
}


template <typename T>
bool  Stack<T>::Push(const T& newItem)
{
	Node<T>* NewNodeptr = new Node<T>(newItem);

	if (Isempty())
		top = NewNodeptr; //case: this is the first node in the stack

	else
	top->setNext(NewNodeptr);
	top = NewNodeptr;
	return true;
}


template <typename T>
bool  Stack<T>::Pop(T& TopItem)
{
	if (Isempty())
		return false;

	Node<T>* DeletedNodeptr = top;
	TopItem = top->getItem();

	if (top->getNext() != nullptr)
		top = top->getNext();

	if (DeletedNodeptr)
		delete DeletedNodeptr;
	return true;
}

template <typename T>
bool  Stack<T>::Peek(T& TopItem) const
{
	if (Isempty())
		return false;

	else
     TopItem = top->getItem();
	 return true;
}

template <typename T>
Stack<T>::~Stack()
{

}


#endif // !STACK_H

