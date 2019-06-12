#include <iostream>
#include "node.h"

using namespace std;

#ifndef DS_STACK2
#define DS_STACK2

struct stackException : public exception {
	const char * what() const throw() {
		return "Empty stack exception";
	}
};

template <typename T>
class Stack2 {
	Node<T>* head = NULL;
	int count = 0;

   public:
	void push( T data );
	
	void pop(); 
	
	T top();

	bool empty();

	int size();

};

#endif
