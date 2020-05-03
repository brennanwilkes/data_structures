#include "hash_table.h"
#include "hash.h"
#include <string>

using namespace std;

//Overloaded less than operator for hash entries, comparing keys. Used for sorting and searching
template<class K, class V> bool hash_entry<K, V>::operator<(hash_entry<K, V> const &other) const{
	return key < other.key;
}

//Overloaded equals operator, comparing keys
template<class K, class V> bool hash_entry<K, V>::operator==(hash_entry<K, V> const &other) const{
	return key == other.key;
}

//Overloaded left shift operator for printing
template<class K, class V> std::ostream &operator<<(std::ostream &out, hash_entry<K, V> const &entry){
	return out << entry.key << " : "<<entry.val;
}

//Copy constructor
template<class K, class V> hash_entry<K, V>::hash_entry(hash_entry<K, V> const &other) :
		key(other.key), val(other.val) {}

//Assignment operator
template<class K, class V> hash_entry<K, V> &hash_entry<K, V>::operator=(hash_entry<K, V> &other){
	key = other.key;
	val = other.val;
	return *this;
}

//Instantiation for demo
template class hash_entry<string, string>;
