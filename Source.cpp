#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
int main()
{
	std::fstream fin("Text.txt", std::ios::out);
	if (!fin.is_open()) { std::cout << "ERROR" << std::endl; return -1; }
	for (size_t i = 0; i < 1000000; ++i)
		{
			fin << std::rand()%1000000 << "\n";
		}
		fin.close();
	std::bitset<1000000> bit;
	fin.open("Text.txt",std::ios_base::in);
	std::string str;
	try 
	{
		if (!fin.is_open())
		{
			throw std::invalid_argument("what ??");
		}
	}
	catch (std::invalid_argument& s)
	{
		std::cerr << s.what() << std::endl;
		return -1;
	}
	while (getline(fin, str))
	{
		if (str == "") { continue; }
		bit[std::stoi(str)]=1;
	}
	fin.close();
	fin.open("Text.txt", std::ios::out);
	if (!fin.is_open()) { std::cout << "ERROR" << std::endl; return -1; }

	for (int i = 0; i < bit.size(); i++)
	{
		if (bit[i] == 1)
		{
			 fin <<i << std::endl;
		}
	}
	return 0;
}