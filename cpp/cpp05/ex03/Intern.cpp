#include "Intern.hpp"

Intern::Intern(){}
Intern::~Intern(){}

Intern::Intern(Intern const &o)
{
	*this = o;
}

Intern &Intern::operator=(Intern const &o)
{
	(void)o;
	return (*this);
}

void	Intern::ft_free(AForm *forms[3], int j)
{
	for(int i = 0; i < 3; i++)
	{
		if (forms[i] != NULL && i != j)
		{
			delete forms[i];
			forms[i] = NULL;
		}
	}
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string FormNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *FormType[3] = {new ShrubberyCreationForm(target),  new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm *tmp = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (FormNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			tmp =  FormType[i];
			ft_free(FormType, i);
			return (tmp);
		}
	}
	ft_free(FormType, -1);
	std::cerr << "Error: Form " << name << " does not exist." << std::endl;
	return NULL;
}
