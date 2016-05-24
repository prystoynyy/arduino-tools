#include "HashMap.h"

template <typename K, typename V, typename F>
HashMap<K,V,F>::HashMap(){
        table = new HashNode<K, V> *[TABLE_SIZE]();
}

template <typename K, typename V, typename F>
HashMap<K,V,F>::~HashMap(){
        // destroy all buckets one by one
        for (int i = 0; i < TABLE_SIZE; ++i) {
                HashNode<K, V> *entry = table[i];
                while (entry) {
                        HashNode<K, V> *prev = entry;
                        entry = entry->getNext();
                        delete prev;
                }
                table[i] = 0;
        }
        // destroy the hash table
        delete [] table;
}

template <typename K, typename V, typename F>
bool HashMap<K,V,F>::get(const K &key, V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];

        while (entry) {
                if (entry->getKey() == key) {
                        value = entry->getValue();
                        return true;
                }
                entry = entry->getNext();
        }
        return false;
}


template <typename K, typename V, typename F>
void HashMap<K,V,F>::put(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = 0;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != 0 && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
        }

        if (entry == 0) {
                entry = new HashNode<K, V>(key, value);
                if (prev == 0) {
                        // insert as first bucket
                        table[hashValue] = entry;
                } else {
                        prev->setNext(entry);
                }
        } else {
                // just update the value
                entry->setValue(value);
        }
}

template <typename K, typename V, typename F>
void HashMap<K,V,F>::remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = 0;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != 0 && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
        }

        if (entry == 0) {
                // key not found
                return;
        }
        else {
                if (prev == 0) {
                        // remove first bucket of the list
                        table[hashValue] = entry->getNext();
                } else {
                        prev->setNext(entry->getNext());
                }
                delete entry;
        }
}
