/*
	Templated class to repersent a binary search tree.
*/

#include "tree.h"

using namespace std;

//#################### tree_node ####################

//Recursive tree_node deconstructor
template<class T> tree_node<T>::~tree_node(){
    delete left;
    delete right;
}

//tree_node copy constructor
template<class T> tree_node<T>::tree_node(const tree_node<T> &other) :
		data(other.data),
		left(other.left ? new tree_node(*(other.left)) : nullptr),
		right(other.right ? new tree_node(*(other.right)) : nullptr) {}

//Assignment Operator
template<class T> tree_node<T> &tree_node<T>::operator=(tree_node<T> &other){
	data = other.data;
	delete left;
	delete right;
	left = new tree_node<T>(*(other.left));
	right = new tree_node<T>(*(other.right));
	return other;
}

//Goes left once, then right until it finds the immediate_predecessor
template<class T> tree_node<T> *tree_node<T>::immediate_predecessor(bool md){
	return md ? left -> immediate_predecessor(false) : (right ? right -> immediate_predecessor(false) : this);
}

//insertion at this point
template<class T> tree_node<T> &tree_node<T>::operator+=(T other){

	//determine if we need to go left or right
	tree_node<T> **next = other < data ? &left : &right;

	//recurse or insert the new node
	return *next ? **next += other : *(*next = new tree_node<T>(other));
}

//deletion at this point
template<class T> tree_node<T> *tree_node<T>::operator-=(T other){

	//found a match
	if(data == other){

		//no children
		if(!right && !left){
			delete this;
			return nullptr;
		}

		//one child
		else if(!left ^ !right){
			tree_node<T> **child = left ? &left : &right;
			tree_node<T> *temp = *child;
			*child = nullptr;
			delete this;
			return temp;
		}

		//two children
		else{
			tree_node<T> *ip = immediate_predecessor();
			data = ip -> data;
			left = (*left -= ip -> data);
			return this;
		}
	}

	//determine if we need to go left or right
	tree_node<T> **next = other < data ? &left : &right;
	//recurse and update pointers
	if(*next){
		*next = **next -= other;
	}

	//else no op
	return this;
}

//Print out a tree_node
//This formatting is a lil wonky but thats ok
template <typename TT> ostream &operator<<(ostream &out, const tree_node<TT> &nd){
	if(nd.left){
		out << *nd.left << ' ';
	}
	out << ' ' << nd.data;
	if(nd.right){
		out << ' ' << *nd.right;
	}
	return out;
}

//#################### tree ####################

//Print out a tree
template <typename TT> ostream &operator<<(ostream &out, const tree<TT> &lst){
	if(lst.root){
		return out << *lst.root;
	}
	return out;
}

//Insertion for sorted linked tree
template<class T> tree<T> &tree<T>::operator+=(T other){
	if(root){
		*root += other;
	}
	else{
		root = new tree_node<T>(other);
	}
	return *this;
}

//Deletion for sorted linked tree
template<class T> tree<T> &tree<T>::operator-=(T other){
	if(root){
		root = (*root -= other);
	}
	return *this;
}

//Destructor to begin recursive process
template<class T> tree<T>::~tree(){
    delete root;
}

//Assignment operator
template<class T> tree<T> &tree<T>::operator=(tree<T> &other){
	delete root;
	root = new tree_node<T>(*(other.root));
	return other;
}

//Copy constructor
template<class T> tree<T>::tree(const tree<T> &other) : root(new tree_node<T>(*other.root)) {}

//Gets the biggest value
template<class T> T tree<T>::biggest(){
	return root ? root -> immediate_predecessor(false) -> data : nan("");
}

//instantiation for demo
template class tree<long long>;
