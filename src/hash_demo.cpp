#include "hash_table.h"
#include "hash.h"
#include <iostream>
#include <string>

using namespace std;



//g++ *.cpp -Wall -g -fsanitize=address -std=c++14 -o main

int main(){

	cout << "Enter size of hash table: ";
	int size;
	cin >> size;

	hash_table<string, string> storage(size);

	cout<<"Created hash table of size "<<size<<" - "<< &storage<<endl;

	cout<<"Hit [q] to quit"<<endl;
	string key;
	string val;
	while(true){
		cout<<"Enter key to get/set: ";
		cin>>key;
		if(key=="q"){
			break;
		}
		val = storage[key];
		if(val!=""){
			cout<<key<<" hashes to "<<hex<<i_hash(key)<<" and resloves to "<<val<<endl;
		}
		else{
			cout<<"Enter value to associate "+key+" with: ";
			cin>>val;
			storage[key] = val;
			cout<<key<<" hashed to "<<hex<<i_hash(key)<<" and stored at index "<<i_hash(key)%size<<endl;
		}
		cout<<endl;
	}
	return 0;
}
