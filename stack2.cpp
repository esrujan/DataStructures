#include "stack2.h"

template <typename T>
void Stack2<T>::push( T data ) {
	Node<T>* newNode = new Node<T>{ data, NULL };
	Node<T>* curr = head;
	
	if ( head == NULL ) {
		head = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
	count += 1;
}
	
template <typename T>	
void Stack2<T>::pop() {
	if ( this->empty() )
		throw stackException();
	Node<T>* curr = head;
	T data = curr->data;
	head = curr->next;
	delete curr;
	count -= 1;
}

template <typename T>	
T Stack2<T>::top() {
	if ( this->empty() )
		throw stackException();
	return ( head->data );
}

template <typename T>
bool Stack2<T>::empty() {
	return ( head == NULL );
}

template <typename T>
int Stack2<T>::size() {
	return count;
}

template class Stack2<int>;
template class Stack2<char>;
template class Stack2<double>;
