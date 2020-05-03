/*
	Templated class to repersent a stack, using a vector.
*/

#include <vector>

//Templated class to repersent a stack using a vector
template<class T> class vector_stack{

    //Pointer to a vector of data
    std::vector<T> *stack;
    public:

    	//Default constructor
        vector_stack() : stack(new std::vector<T>()) {};

        //Destructor
        ~vector_stack();

        //Assignment operator
        vector_stack<T> &operator=(vector_stack<T>&);

        //Copy constructor
        vector_stack(const vector_stack<T>&);

        //Boolean function to find if stack has atleast 1 element
        bool has_next();

        //Push to stack
        void push(T);

        //Pop from stack
        T pop();
};
