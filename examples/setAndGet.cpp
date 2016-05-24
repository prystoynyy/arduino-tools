#include "../src/HashMap.h"
#include "../src/HashMap.cpp"

HashMap<int, string, MyKeyHash> hmap;
	hmap.put(1, "1");
	hmap.put(2, "2");
	hmap.put(3, "3");

	string value;
	bool result = hmap.get(2, value);
