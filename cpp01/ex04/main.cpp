#include <iostream>
#include <string>
#include <fstream>

std::string    new_line(std::string line, std::string s1, std::string s2)
{
	size_t		pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos += s2.length();
	}
	return (line);
}

int main(int ac, char* av[])
{
	if (ac == 4)
	{
		std::string infile = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::string line;
		std::ifstream inputfile(infile.c_str());
		if (!inputfile.is_open())
		{
			std::cout << " Error in opening infile !!" << std::endl;
			return (1);
		}
		std::string out = infile + ".replace";
		std::ofstream outfile(out.c_str());
		if (!outfile.is_open())
		{ 
			std::cout << " Error in opening outfile !!" << std::endl;
			return (1);
		}
		while (getline(inputfile, line))
		{
			outfile << new_line(line, s1, s2) << "\n";
		}
		return (0);
	}
	std::cout << " Wrong number of argument !!" << std::endl;
	return (1);
}
