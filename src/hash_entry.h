#pragma once

#include "list.h"

//Templated class to repersent a hash table entry
template<class K, class V> class hash_entry{
public:

	//Base data
	K key;
	V val;

	//Constructor to build a valueless key. This is used for searching
	hash_entry(K k) : key(k) {}

	//Default constructor
	hash_entry(K k, V v) : key(k), val(v) {}

	//Copy constructor
	hash_entry(hash_entry<K, V> const &);

	//Assignment operator
	hash_entry<K, V> &operator=(hash_entry<K, V>&);

	//Less than operator for searching and sorting
	bool operator<(hash_entry<K, V> const &) const;

	//Equals operator for searching and sorting
	bool operator==(hash_entry<K, V> const &) const;

	//Because everyone needs a friend :)
	friend std::ostream &operator<<(std::ostream &, hash_entry<K, V> const &);

};
