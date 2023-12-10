#include "Harl.hpp"

int main(int ac,char*av[])
{
	Harl		Harl;
	
	if (ac == 2)
	{
		switch (Harl.get_lvl(av[1]))
		{
			case 0:
				Harl.complain("DEBUG");
			case 1:
				Harl.complain("INFO");
			case 2:
				Harl.complain("WARNING");
			case 3:
				Harl.complain("ERROR");
				break;
			case 4:
				Harl.complain("");
		}
		return (0);
	}
	std::cout << "Invalid number of argument! " << std::endl;
	return (1);
}