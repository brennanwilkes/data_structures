#include "hash_table.h"
#include "hash.h"
#include <string>

using namespace std;

//Default constructor to create a hash table of size m
template<class K, class V> hash_table<K, V>::hash_table(size_t m) {
	max_entries = m;

	//Storage will be an array of initially empty lists
	entries = new list<hash_entry<K, V> >*[m];

	//Ensure they are nullptrs
	for(size_t i=0;i<max_entries;i++){
		entries[i] = nullptr;
	}
}

//Copy constructor
template<class K, class V> hash_table<K, V>::hash_table(hash_table<K, V> const &other) :
		max_entries(other.max_entries),
		entries(new list<hash_entry<K, V> >*[other.max_entries]) {
	for(size_t i=0; i<max_entries; i++){
		entries[i] = (other.entries[i] ? new list<hash_entry<K, V> >(*other.entries[i]) : nullptr);
	}
}

//Assignment operator. Basically deletes and copies
template<class K, class V> hash_table<K, V> &hash_table<K, V>::operator=(hash_table<K, V> &other){
	for(size_t i=0;i<max_entries;i++){
		delete entries[i];
	}
	delete[] entries;

	max_entries = other.max_entries;
	entries = new list<hash_entry<K, V> >*[other.max_entries];
	for(size_t i=0; i<max_entries; i++){
		entries[i] = (other.entries[i] ? new list<hash_entry<K, V> >(*other.entries[i]) : nullptr);
	}

	return *this;
}

//Destructor
template<class K, class V> hash_table<K, V>::~hash_table<K, V>(){
	for(size_t i=0;i<max_entries;i++){
		delete entries[i];
	}
	delete[] entries;
}

//index operator. Gets the value, allowing for setting
template<class K, class V> V &hash_table<K, V>::operator[](K k){

	//Generate a 32 bit hash of the object, then contain it within the bounds of the table.
	uint32_t const index = i_hash(k) % max_entries;

	//If the index is empty, create a new list object
	if(!entries[index]){
		entries[index] = new list<hash_entry<K, V> >();
	}

	//Search the list for the key value. Returns a pointer to the hash entry with the same key
	hash_entry<K, V> *data = (*entries[index])[hash_entry<K, V>(k)];

	//If no hash entry exists, create one
	if(!data){
		*entries[index] += hash_entry<K, V>(k);
		data = (*entries[index])[hash_entry<K, V>(k)];
	}

	//Return the value by reference, allowing for setting outside of the lookup.
	return data -> val;
}

//instantiation for demo
template class hash_table<string, string>;
