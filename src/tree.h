/*
	Templated class to represent a tree.
*/
#include <iostream>
#include <cmath>

//Prototype for binary search tree class
template<class T> class tree;

//Templated tree_node class
template<class T> class tree_node{

		//tree_nodes actual data
        T data;

        //Pointer to left tree_node
        tree_node<T> *left;

        //Pointer to left tree_node
        tree_node<T> *right;

    public:

    	//Regular constructor
        tree_node(T data, tree_node<T> *left=nullptr, tree_node<T> *right=nullptr) : data(data), left(left), right(right) {};

        //Copy constructor
        tree_node(const tree_node<T>&);

        //Destructor
        ~tree_node();

        //Assignment operator (gotta have that rule of three!!)
        tree_node<T> &operator=(tree_node<T>&);

        //Insert data at this point
        tree_node<T> &operator+=(T);

        //Remove data at this point
        tree_node<T> *operator-=(T);

        //finds the immediate predecessor of a node
        tree_node<T> *immediate_predecessor(bool md=true);

        //Print out a tree_node
        template <typename TT> friend std::ostream &operator<<(std::ostream&, const tree_node<TT>&);

    //"Since everyone needs a friend" -Bob Ross
    friend class tree<T>;
};

//Templated class to repersent a linked tree
template<class T> class tree{

		//Pointer to the root tree_node
        tree_node<T> *root;

    public:

    	//Default constructor
        tree() : root(nullptr) {};

        //Destructor
        ~tree();

        //Assignment operator
        tree<T> &operator=(tree<T>&);

        //Copy constructor
        tree(const tree<T>&);

        //Inserts an item into the linked tree
        tree<T> &operator+=(T);

        //Removes an item from the linked tree
        tree<T> &operator-=(T);

        //Gets the biggest value
        T biggest();

        //Print out a tree
    	template <typename TT> friend std::ostream &operator<<(std::ostream&, const tree<TT>&);
};
