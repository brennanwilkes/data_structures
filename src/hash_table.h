#pragma once

#include "list.h"
#include "hash_entry.h"

//A templated class repersenting a hash table
template<class K, class V> class hash_table{

	//Size
	size_t max_entries;

	//Storage array
	list<hash_entry<K, V> > **entries;

public:

	//Default constructor
	hash_table(size_t m=2048);

	//Copy constructor
	hash_table(hash_table<K, V> const &);

	//Destructor
	~hash_table<K, V>();

	//Assignment operator
	hash_table<K, V> &operator=(hash_table<K, V>&);

	//Indexing operator
	V &operator[](K);
};
