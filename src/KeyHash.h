#ifndef __KeyHash_H__
#define __KeyHash_H__

static const int TABLE_SIZE = 128;

// Default hash function class
template <typename K>
struct KeyHash {
        unsigned long operator()(const K& key) const
        {
                return key % TABLE_SIZE;
        }
};

#endif
