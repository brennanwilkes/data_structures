#pragma once

/*
	Templated class to represent a linked list.
*/
#include <iostream>

//Prototype for linked list class
template<class T> class list;

//Templated list_node class
template<class T> class list_node{

		//list_nodes actual data
        T data;

        //Pointer to next list_node
        list_node<T> *next;

    public:

    	//Regular constructor
        list_node(T data, list_node<T> *next) : data(data), next(next) {};

        //Copy constructor
        list_node(const list_node<T>&);

        //Destructor
        ~list_node();

        //Assignment operator (gotta have that rule of three!!)
        list_node<T> &operator=(list_node<T>&);

        //Insert data at this point
        list_node<T> &operator+=(T);

        //Remove data at this point
        list_node<T> *operator-=(T);

        //Return the next node
        list_node<T> *last();

        //Get element
        T *operator[](int);

        //Find element
        T *operator[](T);

        //Print out a list_node
        template <typename TT> friend std::ostream &operator<<(std::ostream&, const list_node<TT>&);

    //"Since everyone needs a friend" -Bob Ross
    friend class list<T>;
};

//Templated class to repersent a linked list
template<class T> class list{

		//Pointer to the head list_node
        list_node<T> *head;

    public:

    	//Default constructor
        list() : head(nullptr) {};

        //Destructor
        ~list();

        //Assignment operator
        list<T> &operator=(list<T>&);

        //Copy constructor
        list(const list<T>&);

        //Boolean function to determine if the stack has a valid head list_node
        bool has_next();

        //Inserts an item into the linked list
        list<T> &operator+=(T);

        //Removes an item from the linked list
        list<T> &operator-=(T);

        //Get element
        T *operator[](int);

        //Find element
        T *operator[](T);

        //Print out a list
    	template <typename TT> friend std::ostream &operator<<(std::ostream&, const list<TT>&);
};
