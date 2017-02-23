#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include <string>
#include <sstream>

//remove namespace. Readability is subjective alterated by usage, clarity is objective.

typedef struct pizza_layout{
	unsigned int R;
	unsigned int C;
	unsigned int L;
	unsigned int H;
}pizza_layout;


static pizza_layout s_pizza;

int main(int argc, char** argv) {
	if(argc != 3)
	{
		std::cout<<"Pass more arguments: <File_input> <File_output>"<<std::endl;
		exit(1);
	}
	std::ifstream in_f;
	std::string in_f_name = "../../../inputs/"+std::string(argv[1]);
	in_f.open(in_f_name.c_str(), std::ifstream::in);
	if(!in_f.is_open())
	{
		exit(2);
	}

	//ToBe use with std::FILE
	//fscanf(in_f, "%u%u%u%u", &(s_pizza.R), &(s_pizza.C), &(s_pizza.L), &(s_pizza.H));
	std::string line;
	std::getline(in_f, line);
	std::stringstream m_ss(line);

	//if whitespace between numbers
	int *p_pizza = reinterpret_cast<int*>(&s_pizza);
	while(m_ss >> *p_pizza++)
	{
	}
	m_ss << "";//erase stream
	m_ss.clear();//clear eof flag
	m_ss.seekg(0);//then set read ptr
	printf("%u %u %u %u\n", s_pizza.R, s_pizza.C, s_pizza.L, s_pizza.H);

	//if need to read a simple char
	std::getline(in_f,line);
	m_ss << line;
	char a;
	m_ss >> a;

	//[DEBUG]
	//int aa = m_ss.tellg();//get read ptr
	//std::cout<<m_ss.str()<<std::endl;//verify streamstring integrity

	//Read to eof
	while(std::getline(in_f, line))
	{
		//std::cout<<line;
	}
	in_f.close();

	//output: fstream (R+W) and fprintf
	exit(0);
}
