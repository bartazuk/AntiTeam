#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


//Struct
typedef struct latency_cache{
	unsigned int id_cache;
	unsigned int latency_ms;
}latency_cache;

typedef struct request{
	unsigned int id_video;
	unsigned int nb_ask;
}latency_cache;

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



int main(int argc, char** argv)
{
	if(argc != 3)
	{
		std::cout<<"Pass more arguments: <File_input> <File_output>"<<std::endl;
		exit(1);
	}
	//Open File
	std::ifstream in_f;
	std::string in_f_name = "../../../inputs/"+std::string(argv[1]);
	in_f.open(in_f_name.c_str(), std::ifstream::in);
	if(!in_f.is_open())
	{
		exit(2);
	}
	exit(0);
}
