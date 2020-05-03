/*
	Templated class to repersent a stack, using a linked list.
*/

#include "list_stack.h"

using namespace std;

//#################### node ####################

//Recursive node deconstructor
template<class T> node<T>::~node(){
	delete next;
}

//Node copy constructor
template<class T> node<T>::node(const node<T> &other)
		: data(other.data),
		  next(other.next ? new node(*(other.next)) : nullptr) {}

//Assignment Operator
template<class T> node<T> &node<T>::operator=(node<T> &other){
	data = other.data;
	delete next;
	next = new node<T>(*(other.next));
	return other;
}

//#################### list_stack ####################

//Push a new item on to the stack
template<class T> void list_stack<T>::push(T data){
	head = new node<T>(data, head);
}

//Pop and return the top item from the stack
template<class T> T list_stack<T>::pop(){
	node<T> *tempNode = head;
	T tempData = tempNode -> data;
	head = head->next;
	tempNode -> next = nullptr;
	delete tempNode;
	return tempData;
}

//Destructor to begin recursive process
template<class T> list_stack<T>::~list_stack(){
	delete head;
}

//Assignment operator
template<class T> list_stack<T> &list_stack<T>::operator=(list_stack<T> &other){
	head = new node<T>(*(other.head));
	return other;
}

//Copy constructor
template<class T> list_stack<T>::list_stack(const list_stack<T> &other) : head(new node<T>(*other.head)) {}

//Boolean function to calculate if the stack has a valid head
template<class T> bool list_stack<T>::has_next(){
	return head;
}
