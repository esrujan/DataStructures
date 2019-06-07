#ifndef LINKEDLIST_H
#define LINKNEDLIST_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


template <typename T>
struct Node {
        int data;
        Node<T> *next;
};


template <typename T>
class LinkedList {
private:
     Node<T> *head;
public:
     LinkedList(): head(NULL) {}

     Node<T>* getHead();

     Node<T>* AddtoList( T data );

     void	AddtoList( vector<T> data );

     bool RemovefromList( T data );

     int RemoveAllfromList( T data );

     Node<T>* RemoveLast();

	void swap( Node<T> *n1, Node<T> *n2 );

	void swapMinMax();

	void reverse();
	
	void reverseRecursion();
	
	void reverseRecur( Node<T>* h );

	void makeCircular();

	Node<T>* detectCycle();
	
	void removeDuplicates();

	void mergeAlternate( Node<T>* head2 );

	void merge( Node<T>* head2 );

	Node<T>* merge( Node<T>* head1, Node<T>* head2 );

	void mergeSort();

	Node<T>* mergeSort( Node<T>* head );
	
     void printList();
	
	void printFibList();

};

#endif
