//g++ *.cpp -Wall -g -fsanitize=address -std=c++14 -o main

#include "list.h"
#include "tree.h"
#include <iostream>
#include <chrono>

using namespace std;


#include "data_set.h"

static unsigned long long current_millis()
{
	// code stolen from https://stackoverflow.com/a/56107709
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

template <class T> static void time_data_structure()
{
	unsigned long long const start = current_millis();
	T d;
	for (size_t i = 0; i < sizeof to_add / sizeof to_add[0]; i++) {
		d += to_add[i];
	}
	for (size_t i = 0; i < sizeof to_subtract / sizeof to_subtract[0]; i++) {
		d -= to_subtract[i];
	}
	unsigned long long const end = current_millis();
	cout << " (finished in " << (end - start) << "ms)" << endl;
}

int main() {
	cout<<"processing 15000 tree operations"<<endl;
	time_data_structure<tree<long long> >();
	cout<<"processing 15000 list operations"<<endl;
	time_data_structure<list<long long> >();
	return 0;
}
