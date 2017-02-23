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

typedef struct request_desc{
	unsigned int id_video;
	unsigned int nb_ask;
}request_desc;

enum node_type {ENDPOINT, CACHE, DATA_CENTER};

typedef struct node {
	enum node_type type;
	unsigned int id;
	std::vector<node *> link;
	void * priv_data; // endpoint, cache etc...
}node;

typedef struct endpoint{
	unsigned int latency_datacenter;
	std::vector<latency_cache> m_latency_cache;
	std::vector<request_desc> access;
}endpoint;

typedef struct cache{
	unsigned int cache_size;
}cache;

typedef struct layout{
	unsigned int video_nb;
	unsigned int end_nb;
	unsigned int request_desc;
	unsigned int cache_nb;
	unsigned int cache_capacity;
}layout;


// ******************Variable static**********************

static layout s_layout;



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
		printf("ERROR\n");
		exit(2);
	}

	std::string line;
	std::getline(in_f, line);
	std::stringstream m_ss(line);

	//if whitespace between numbers
	unsigned int *p_layout = reinterpret_cast<unsigned int*>(&s_layout);
	while(m_ss >> *p_layout++)
	{
	}
	m_ss << "";//erase stream
	m_ss.clear();//clear eof flag
	m_ss.seekg(0);//then set read ptr
	printf("%u %u %u %u %u\n", s_layout.video_nb, s_layout.end_nb, s_layout.request_desc, s_layout.cache_nb, s_layout.cache_capacity);


	exit(0);
}
