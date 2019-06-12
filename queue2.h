#include <iostream>
#include "node.h"

using namespace std;

#ifndef DS_QUEUE_H
#define DS_QUEUE_H


struct QueueException : public exception {
	const char* what() const throw() {
		return "Empty Queue Exception";
	}
};

template <typename T>
class Queue2
{

	Node<T>* head = NULL;
	Node<T>* tail = NULL;

public:
	void enqueue( T data );

	void dequeue();

	T front() const;

	T back() const;

	bool empty() const;
};

#endif
