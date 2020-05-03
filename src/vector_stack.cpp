/*
	Templated class to repersent a stack, using a vector.
*/

#include "vector_stack.h"

using namespace std;

//Push an item to the top of the stack
template<class T> void vector_stack<T>::push(T data){
    stack -> push_back(data);
}

//Pop and return an item from the top of the stack
template<class T> T vector_stack<T>::pop(){
    T temp = (*stack)[stack->size()-1];
    stack -> pop_back();
    return temp;
}

//Destructor
template<class T> vector_stack<T>::~vector_stack(){
    delete stack;
}

//Assignment operator
template<class T> vector_stack<T> &vector_stack<T>::operator=(vector_stack<T> &other){
    stack -> resize(other.stack->size());
    for(int i=0; i < other.stack->size(); i++){
        stack->at(i) = other.stack->at(i);
    }
    return other;
}

//Copy constructor
template<class T> vector_stack<T>::vector_stack(const vector_stack<T> &other) : stack(new vector<T>(*other.stack)) {}

//Function to determine if stack has atleast one element
template<class T> bool vector_stack<T>::has_next(){
	return stack->size();
}
