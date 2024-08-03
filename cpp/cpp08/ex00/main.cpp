#include "easyfind.hpp"

int main()
{
	std::vector<int> values;
	for(int i = 0; i < 10; i++) {
		values.push_back(i + 1);
	}
	try
	{
		std::vector<int>::iterator it = easyfind(values, 6);
		std::cout << *it << std::endl;
	}
	catch(std::runtime_error &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}