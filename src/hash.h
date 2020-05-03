#include <cstdint>

//A basic 32bit hash function. Not a secure hash, but works for my storage needs. Will hash any iterable object
template<class T> uint32_t i_hash(const T &data){
	uint32_t hash = 0x12345678u;
	for(auto i : data){
		hash ^= (hash << 16) | (hash << 19);
		hash += i;
		hash ^= (hash << 26) | (hash << 13);
	}
	return hash;
}
