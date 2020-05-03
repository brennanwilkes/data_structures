/*
	Templated class to repersent a linked list.
*/

#include "list.h"
#include "hash_entry.h"

using namespace std;

//#################### list_node ####################

//Recursive list_node deconstructor
template<class T> list_node<T>::~list_node(){
    delete next;
}

//list_node copy constructor
template<class T> list_node<T>::list_node(const list_node<T> &other)
		: data(other.data),
		  next(other.next ? new list_node(*(other.next)) : nullptr) {}

//Assignment Operator
template<class T> list_node<T> &list_node<T>::operator=(list_node<T> &other){
	data = other.data;
	delete next;
	next = new list_node<T>(*(other.next));
	return other;
}

//Return the next node
template<class T> list_node<T> *list_node<T>::last(){
	return next ? next -> last() : this;
}

//insertion at this point
template<class T> list_node<T> &list_node<T>::operator+=(T other){
	if(other < data){
		next = new list_node<T>(data,next);
		data = other;
		return *this;
	}
	return next ? (*next += other) : *(next = new list_node<T>(other,next));
}

//deletion at this point
template<class T> list_node<T> *list_node<T>::operator-=(T other){

	//found data
	if(data == other){
		list_node* temp = next;
		next = nullptr;
		delete this;	//safe deletion
		return temp;
	}
	//no op
	else if(other < data || !next){
		return this;
	}

	//recurse and update next pointer
	next = (*next -= other);
	return this;
}

//Get element
template<class T> T *list_node<T>::operator[](int i){
	return i==0 ? &data : (next ? (*next)[i-1] : nullptr);
}

//Find element
template<class T> T *list_node<T>::operator[](T t){
	return data == t ? &data : (next ? (*next)[t] : nullptr);
}


/*
	Print out a list_node
	With these templated friend << functions I had some help from reading
	this stack overflow post. This applies to both the list_node and list << operator.

	https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class

*/
template <typename TT> ostream &operator<<(ostream &out, const list_node<TT> &nd){
	out << nd.data;
	if(nd.next){
		out << ' ' << *nd.next;
	}
	return out;
}

//#################### list ####################

//Print out a list
template <typename TT> ostream &operator<<(ostream &out, const list<TT> &lst){
	if(lst.head){
		return out << *lst.head;
	}
	return out;
}

//Insertion for sorted linked list
template<class T> list<T> &list<T>::operator+=(T other){
	if(head){
		*head += other;
	}
	else{
		head = new list_node<T>(other, nullptr);
	}
	return *this;
}

//Deletion for sorted linked list
template<class T> list<T> &list<T>::operator-=(T other){
	if(head){
		head = (*head -= other);
	}
	return *this;
}

//Destructor to begin recursive process
template<class T> list<T>::~list(){
    delete head;
}

//Assignment operator
template<class T> list<T> &list<T>::operator=(list<T> &other){
	head = new list_node<T>(*(other.head));
	return other;
}

//Copy constructor
template<class T> list<T>::list(const list<T> &other) : head(new list_node<T>(*other.head)) {}

//Boolean function to calculate if the stack has a valid head
template<class T> bool list<T>::has_next(){
	return head;
}

//Get element
template<class T> T *list<T>::operator[](int i){
	return head ? (*head)[i] : nullptr;
}

//Find element
template<class T> T *list<T>::operator[](T t){
	return head ? (*head)[t] : nullptr;
}

//instantiation for hash demo
template class list<hash_entry<string, string> >;

//instantiation for list demo
template class list<long long>;
