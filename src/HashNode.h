#ifndef __HashNode_H__
#define __HashNode_H__

template <typename K, typename V>
class HashNode {
public:
        HashNode(const K &key, const V &value);

        K getKey() const;

        V getValue() const;

        void setValue(V value);

        HashNode *getNext() const;

        void setNext(HashNode *next);

private:
        // key-value pair
        K key;
        V value;
        // next bucket with the same key
        HashNode *next;
};

#endif
