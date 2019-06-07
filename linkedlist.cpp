#include "linkedlist.h"

template <typename T>        
Node<T>* LinkedList<T>::getHead() {
     return head;
}

template <typename T>
void LinkedList<T>::swap( Node<T>* n1, Node<T>* n2 ) {
	if ( n1 == NULL || n2 == NULL || ( n1 == n2 ) )
		return;
	Node<T> *prev1, *nxt1, *curr1, *prev2, *nxt2, *curr2;
	prev1 = prev2 = NULL;
	curr1 = curr2 = head;

	while ( curr1 != n1 ) {
		prev1 = (prev1 == NULL)? head : (prev1->next);
		curr1 = curr1->next;
	}
	nxt1 = curr1->next;
	while ( curr2 != n2 ) {
		prev2 = (prev2 == NULL)? head : (prev2->next);
		curr2 = curr2->next;
	}
	nxt2 = curr2->next;
	
	// swapping n1 and n2
	if ( prev1 == NULL ) {
		head = n2;
	} else {
		prev1->next = n2;
	}
	n2->next = nxt1;
	
	if ( prev2 == NULL ) {
		head = n1;
	} else {
		prev2->next = n1;
	}
	n1->next = nxt2;
}

template <typename T>
void LinkedList<T>::swapMinMax() {
	Node<T> *min = head, *max = head;
	T minVal = head->data;
	T maxVal = head->data;
	
	Node<T> *curr = head;
	while ( curr != NULL ) {
		T currData = curr->data;
		if ( currData < minVal ) {
			minVal = currData;
			min = curr;
		}
		if ( currData > maxVal ) {
			maxVal = currData;
			max = curr;
		}
		curr = curr->next;
	}
	this->swap( min, max );
}

template <typename T>
Node<T>* LinkedList<T>::AddtoList( T data ) {
     Node<T> *newNode = new Node<T>{ data, NULL };
     Node<T> *curr = this->head;
     if ( curr == NULL ) {
             curr = newNode;
             head = curr;
     } else {
             while ( curr->next != NULL )
                     curr = curr->next;
             curr->next = newNode;
     }
     return newNode;
}

template <typename T>
void LinkedList<T>::AddtoList( vector<T> data ) {

	for ( T t : data ) {
		this->AddtoList( t );
	}
}

// Removes the first Node occurence of data in the linked list
template <typename T>
bool LinkedList<T>::RemovefromList( T data ) {
                bool res = false;
                Node<T> *curr = head, *prev;
                if ( head->data == data ) {
                        head = head->next;
                        delete curr;
                        res = true;
                } else {
                        prev = curr;
                        curr = curr->next;
                        while ( curr != NULL ) {
                                if ( curr->data == data ) {
                                        prev->next = curr->next;
                                        delete curr;
                                        res = true;
                                        break;
                                }
                                curr = curr->next;
                                prev = prev->next;
                        }
                }
                return res;
        }

// Remove all the nodes with the given data in linked List
template <typename T>
int LinkedList<T>::RemoveAllfromList( T data ) {
	int res = 0;
	Node<T> *curr = head, *prev;
	if ( head == NULL )
		return res;
	while ( head->data == data ) {
		head = head->next;
		delete curr;
		curr = head;
	}

	if ( head == NULL )
		return res;
	prev = head;
	curr = head->next;
	while ( curr != NULL ) {
		if ( curr->data == data ) {
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		} else {
			prev = prev->next;
			curr = curr->next;
		}
	}
		
	return res;
}

// Removes the last node of linkedlist
// Frees the memory of the node and returns pointer to last node
template <typename T>
Node<T>* LinkedList<T>::RemoveLast() {
	Node<T> *curr = this->head, *prev = NULL;
	if ( head != NULL ) {
		while ( curr->next != NULL ) {
			if ( prev == NULL )
				prev = head;
			else {
				prev = prev->next;
			}
			curr = curr->next;
		}
		if ( prev == NULL ) {
			delete head;
			head = NULL;
		} else {
			delete curr;
			prev->next = NULL;
		}
	}
	return prev;
}

template <typename T>	
void LinkedList<T>::printList() {
     Node<T> *curr = this->head;
     cout << "The linkedlist is as follows:";
     while ( curr != NULL ) {
           cout << curr->data << " ";
           curr = curr->next;
     }
     cout << endl;
}

template <typename T>
void LinkedList<T>::printFibList() {
	Node<T> *curr = head;
	cout << "The linkedlist according to Fibonacci sequence is as follows:" << endl;
	
	if ( head != NULL )
		cout << head->data << " ";
	if ( head->next != NULL ) {
		cout << head->next->data << " ";
		curr = head->next;
	}
	int oldfib, fib, temp;
	oldfib = 0; fib = 1;
	while ( curr != NULL ) {
		cout << curr->data << " ";
		for ( int i = 0; i < fib; i++ ) {
			curr = curr->next;
			if ( curr == NULL )
				break;
		}
		// Saving the fib value in a temp variable
		temp = fib;
		// Calculating the next fib value
		fib = oldfib + fib;
		// Updating the oldfib using the temp variable
		oldfib = temp;
	}
	cout << endl;
}

template <typename T>
void LinkedList<T>::makeCircular() {
	Node<T>* curr = head;
	if ( curr == NULL )
		return ;
	while ( curr->next != NULL )
		curr = curr->next;
	curr->next = head->next;
}

template <typename T>
void LinkedList<T>::removeDuplicates() {
	cout << "Remove Duplicates\n";
	unordered_set<T> set;
	Node<T> *curr = head, *prev = NULL;
	while ( curr != NULL ) {
		if ( set.find(curr->data) == set.end() ) {
			set.insert( curr->data );
			if ( prev == NULL )
				prev = head;
                 	else
				prev = prev->next;
			curr = curr->next;
		} else {
			Node<T> *nxt = curr->next;
			prev->next = nxt;
			delete curr;
			curr = nxt;
		}
	}
	set.erase( set.begin(), set.end() );
}

template <typename T>
Node<T>* LinkedList<T>::detectCycle() {
	Node<T> *hare, *tort;
	hare = tort = this->head;
	if ( hare == NULL || hare->next == NULL )
		return NULL;
	
	tort = tort->next;
	hare = hare->next->next;
	
	while ( hare != NULL && hare->next != NULL ) {
		if ( hare == tort )
			break;
		tort = tort->next;
		hare = hare->next->next;
	}

	if ( hare != tort ) {
		return NULL;
	}

	tort = head;
	while ( tort != hare ) {
		hare = hare->next;
		tort = tort->next;
	}
	return tort;
}

template <typename T>
void LinkedList<T>::mergeAlternate( Node<T>* head2 ) {
	Node<T> *curr = head;
	Node<T> *curr2 = head2;
	Node<T> *nxt, *nxt2;
	while( ( curr != NULL ) && ( curr2 != NULL ) ) {
		nxt = curr->next;
		nxt2 = curr2->next;
		curr->next = curr2;
		if ( nxt == NULL ) {
			break;
		} else
			curr2->next = nxt;
		if ( nxt2 == NULL ) {
			break;
		} else
			curr2 = nxt2;
		curr = nxt;
	}
}

template <typename T>
void LinkedList<T>::merge( Node<T>* head2 ) {
	Node<T> *curr = head;
	Node<T> *curr2 = head2;
	Node<T> *nxt, *nxt2, *prev;
	prev = NULL;
	while( ( curr != NULL ) && ( curr2 != NULL ) ) {
		nxt = curr->next;
		nxt2 = curr2->next;
		if ( curr->data <= curr2->data ) {
			if ( prev == NULL ) {
				prev = curr;
			} else {
				prev->next = curr;
				prev = curr;
			}
			curr = nxt;
		} else {
			if ( prev == NULL ) {
				this->head = curr2;
				prev = curr2;
			} else {
				prev->next = curr2;
				prev = curr2;
			}
			curr2 = nxt2;
		}
	}
	if ( curr2 != NULL ) {
		prev->next = curr2;
	}
	if ( curr != NULL ) {
		prev->next = curr;
	}
}

template <typename T>
Node<T>* LinkedList<T>::merge( Node<T>* head1, Node<T>* head2 ) {
	Node<T> *curr = head1;
	Node<T> *curr2 = head2;
	Node<T> *prev, *head;
	prev = head = NULL;
	while( ( curr != NULL ) && ( curr2 != NULL ) ) {
		if ( curr->data <= curr2->data ) {
			if ( prev == NULL ) {
				head = curr;
				prev = curr;
			} else {
				prev->next = curr;
				prev = curr;
			}
			curr = curr->next;
		} else {
			if ( prev == NULL ) {
				head = curr2;
				prev = curr2;
			} else {
				prev->next = curr2;
				prev = curr2;
			}
			curr2 = curr2->next;
		}
	}
	if ( curr2 != NULL ) {
		prev->next = curr2;
	}
	if ( curr != NULL ) {
		prev->next = curr;
	}
	return head;
}

template <typename T>
void LinkedList<T>::mergeSort() {
	this->head = mergeSort( this->head );
}

template <typename T>
Node<T>* LinkedList<T>::mergeSort( Node<T>* h ) {
	if ( h == NULL || h->next == NULL )
		return h;
	Node<T>* curr = h, *prev = NULL;
	Node<T>* fast = h;
	while ( fast && fast->next ) {
		if ( prev == NULL )
			prev = curr;
		else
			prev = prev->next;
		curr = curr->next;
		fast = fast->next->next;
	}
	prev->next = NULL;
	
	h = this->mergeSort( h );
	curr = this->mergeSort( curr );
	return this->merge( h, curr );
}

template <typename T>
void reverse() {
	cout << "Reversing the list" << endl;
	Node<T> *prev, *next, *curr;
	if ( head == NULL )
		return;
	curr = head;
	next = curr->next;
	curr->next = NULL;
	prev = curr;
	curr = next;
	while ( curr != NULL ) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

template <typename T>
void reverseRecursion() {
	cout << "Reversing the list using Recursion" << endl;
	Node<T> *curr = this->head;
	while ( curr->next != NULL )
		curr = curr->next;
	reverseRecur( this->head );
	this->head = curr;
}

template <typename T>
void reverseRecur( Node<T>* h ) {
	if ( h->next != NULL )
	{
		Node<T> *nxt = h->next;
		reverseRecur( nxt );
		nxt->next = h;
		h->next = NULL;
	}
}

template class LinkedList<int>;
template class LinkedList<char>;
