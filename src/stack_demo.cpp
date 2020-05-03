/*

	Main tester class to demonstrate stacks data structures.
	runs is_matched with each test data on each stack type to
	determine if opening brackets are matched with closing brackets

*/

#include "vector_stack.cpp"
#include "list_stack.cpp"
#include <iostream>
#include <limits>


using namespace std;

//Open brackets
const char OPEN[] =  {'{','[','('};

//Closing brackets
const char CLOSE[] = {'}',']',')'};

//Number of bracket types
const int NUM_BRACE_TYPES = 3;


/*
	templated function to determine if an input string contains
	and equal number of closing brackets as opening, and in the
	correct order to be matched.
*/
template<class STACK> bool is_matched(const string s) {

	//Create stack instance
	STACK stack;

	//Loop over ever character
	bool open,close;
	for(int i=0; s[i]; i++){

		//Determine if character is an opening bracket
		open=false;
		for(int j=0; j<NUM_BRACE_TYPES; j++){
			if(s[i] == OPEN[j]){
				open++;
				break;
			}
		}

		//If opening found, add it to the stack
		if(open){
			stack.push(s[i]);
		}

		//Determine if character is a closing bracket
		else{
			close = false;
			int j;
			for(j=0; j<NUM_BRACE_TYPES; j++){
				if(s[i] == CLOSE[j]){
					close++;
					break;
				}
			}

			//If an item cannot be popped, or the popped item is not
			//equal to the character, return false
			if(close){
				if(!stack.has_next() || stack.pop() != OPEN[j]){
					return false;
				}
			}
		}
	}

	//Return true if there are no items left in the stack
	return !stack.has_next();
}


int main(){

    //take i/o
    string inpt;
    cout<<"Enter brackets to match (hit [return] to see example test cases): "<<endl;
    getline(cin,inpt);

    //Use user data
    if(inpt!=""){
    	cout<<"vector: "<<(is_matched<vector_stack<char> >(inpt) ? "MATCHED" : "NOT MATCHED")<<endl;
    	cout<<"list: "<<(is_matched<list_stack<char> >(inpt) ? "MATCHED" : "NOT MATCHED")<<endl;
    }

    //use example data
   	else{
			//Test data
			const string valid[] = {"","( )"," (){}[ ]    ","([{} {}[ ]])","((([[[ ]]])) ){}{()}"};
			const string invalid[] = {"{","( (","( ){ }[","([}{}[ ]])","((([[[)]    ]))) [}{()}"};

			//Testing output
			cout<<"These should be matched"<<endl;
			for(int i=0;i<sizeof valid / sizeof valid[i];i++){
				cout<<"test string: "<<valid[i] << endl;
				cout<<"list: "<<(is_matched<list_stack<char> >(valid[i]) ? "MATCHED" : "NOT MATCHED")<<endl;
				cout<<"vector: "<<(is_matched<vector_stack<char> >(valid[i]) ? "MATCHED" : "NOT MATCHED")<<endl<<endl;
			}

			cout<<"These should NOT be matched"<<endl;
			for(int i=0;i<sizeof invalid / sizeof invalid[i];i++){
				cout<<"test string: "<<invalid[i] << endl;
				cout<<"list: "<<(is_matched<list_stack<char> >(invalid[i]) ? "MATCHED" : "NOT MATCHED")<<endl;
				cout<<"vector: "<<(is_matched<vector_stack<char> >(invalid[i]) ? "MATCHED" : "NOT MATCHED")<<endl<<endl;
			}
	}

    return 0;
}
