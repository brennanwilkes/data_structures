/*
	Templated class to repersent a stack, using a linked list.
*/

//Prototype for stack class
template<class T> class list_stack;

//Templated node class
template<class T> class node{

		//Nodes actual data
		T data;

		//Pointer to next node
		node<T> *next;

	public:

		//Regular constructor
		node(T data, node<T> *next) : data(data), next(next) {};

		//Copy constructor
		node(const node<T>&);

		//Destructor
		~node();

		//Assignment operator (gotta have that rule of three!!)
		node<T> &operator=(node<T>&);

	//"Since everyone needs a friend" -Bob Ross
	friend class list_stack<T>;
};

//Templated class to repersent a stack using a linked list
template<class T> class list_stack{

		//Pointer to the head node
		node<T> *head;

	public:

		//Default constructor
		list_stack() : head(nullptr) {};

		//Destructor
		~list_stack();

		//Assignment operator
		list_stack<T> &operator=(list_stack<T>&);

		//Copy constructor
		list_stack(const list_stack<T>&);

		//Boolean function to determine if the stack has a valid head node
		bool has_next();

		//Pushes an item on to the stack
		void push(T);

		//Pops an item from the stack
		T pop();
};
