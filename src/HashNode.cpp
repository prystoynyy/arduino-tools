#include "HashNode.h"

template <typename K, typename V>
HashNode<K,V>::HashNode(const K &key, const V &value) :
        key(key), value(value), next(0) {
}

template <typename K, typename V>
K HashNode<K,V>::getKey() const{
  return this->key;
}

template <typename K, typename V>
V HashNode<K,V>::getValue() const{
  return this->value;
}

template <typename K, typename V>
void HashNode<K,V>::setValue(V value){
  this->value = value;
}

template <typename K, typename V>
HashNode<K,V>* HashNode<K,V>::getNext() const{
return this->next;
}

template <typename K, typename V>
void HashNode<K,V>::setNext(HashNode<K, V> *next){
  this->next = next;
}
