#include "queue2.h"

template <typename T>
void Queue2<T>::enqueue( T data )
{
	cout << "Enqueuing data " << data << endl;
	Node<T> *newNode = new Node<T>{ data, NULL };
	if ( head == NULL ) {
		head = tail = newNode;
	} else {
		tail->next = newNode;
		tail = tail->next;
	}
}

template <typename T>
void Queue2<T>::dequeue()
{
	cout << "Dequeing from queue " << endl;
	if ( head == NULL )
		throw QueueException();
	Node<T>* curr = head;
	head = head->next;
	if ( head == NULL )
		tail = NULL;
	delete curr;
}

template <typename T>
T Queue2<T>::front() const
{
	if ( head == NULL )
		throw QueueException();
	return ( head->data );
}

template <typename T>
T Queue2<T>::back() const
{
	if ( tail == NULL )
		throw QueueException();
	return ( tail->data );
}

template <typename T>
bool Queue2<T>::empty() const
{
	return ( head == NULL && tail == NULL );
}

template class Queue2<int>;
template class Queue2<char>;
template class Queue2<double>;
