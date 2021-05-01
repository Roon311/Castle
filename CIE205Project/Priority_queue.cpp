#include "Priority_queue.h"






template < typename T>
Priority_queue<T>::Priority_queue() {
	size = 0;
	front = nullptr;
}




template < typename T>
bool Priority_queue<T>::isEmpty() const {
	if (size == 0)
		return true;
	else
		return false;
}
template < typename T>
int Priority_queue<T>::getSize() const {
	return size;
}
template < typename T>
Node<T>* Priority_queue<T>::top() {
	return front;
}
template < typename T>
void Priority_queue<T>::push(T elemnt) {
	Node<T>* newNode = new Node<T>(elemnt);
	if (front == nullptr) {

		front = newNode;
		newNode->setNext(nullptr);
	}
	else {
		if (elemnt > front->getItem()) {
			Node<T>* save = front;
			front = newNode;
			newNode->setNext(save);
		}
		else {
			Node<T>* current = front->getNext();
			while (current != nullptr && current->getNext() != nullptr && elemnt < current->getItem()) {
				current = current->getNext();
			}
			Node<T>* saveNext = current->getNext();
			current->setNext(newNode);
			newNode->setNext(saveNext);
		}
	}
	++size;
}

template < typename T>
void Priority_queue<T>::pop() {
	if (isEmpty() != true) {
		Node<T>* savefront = front;
		Node<T>* ptr = front->getNext();
		front = ptr;
		delete savefront;
		--size;
	}
}