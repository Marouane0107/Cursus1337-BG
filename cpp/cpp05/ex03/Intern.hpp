#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const &Intern);
		~Intern();
		Intern &operator=(Intern const &Intern);
		AForm	*makeForm(std::string name, std::string target);
		void	ft_free(AForm *forms[3], int i);
};

#endif
