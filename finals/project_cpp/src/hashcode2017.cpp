#include <iostream>
#include <vector>

enum node_type {ENDPOINT, CACHE, DATA_CENTER};

typedef struct node {
	enum node_type type;
	unsigned int id;
	std::vector<node *> link;
	void * priv_data; // endpoint, cache etc...
}node;

typedef struct endpoint{
	unsigned int latency_datacenter;
	std::vector<unsigned int, unsigned int> latency_cache;
	std::vector<unsigned int, unsigned int> access;
}endpoint;

typedef struct cache{
	unsigned int cache_size;
}cache;




int main() {

	return 0;
}
