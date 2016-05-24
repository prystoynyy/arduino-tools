#ifndef __HashMap_H__
#define __HashMap_H__
// Hash map class template
#include "HashNode.h"
#include "HashNode.cpp"
#include "KeyHash.h"

template <typename K, typename V, typename F = KeyHash<K>>
class HashMap {
private:
        // hash table
        HashNode<K, V> **table;
        F hashFunc;
public:
        HashMap();

        ~HashMap();

        bool get(const K &key, V &value);
        void put(const K &key, const V &value);
        void remove(const K &key);
};

#endif
