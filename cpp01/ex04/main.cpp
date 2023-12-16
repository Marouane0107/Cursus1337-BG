#include <iostream>
#include <string>
#include <fstream>


std::string    new_line(std::string line, std::string s1, std::string s2)
{
	std::string	new_line;
	size_t		x = 0;
	size_t		n = 0;

	for (size_t i = 0; i < line.length(); i++)
	{
		n = 0;
		if (line[i] == s1[n])
		{
			x = i;
			while(n < s1.length() && x < line.length() && line[x] == s1[n])
			{
				x++;
				n++;
			}
			if (n == s1.size())
			{
				new_line += s2;
				n = 0;
				i = x;
			}
		}
		new_line += line[i];
	}
	return (new_line);
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
