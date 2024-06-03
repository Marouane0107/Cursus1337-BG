#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool    _isSigned;
		int const   _gradeToSigned;
		int const   _gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int gradeToSigned, int gradeToExecute);
		AForm(AForm const &o);
		~AForm();
		AForm &operator=(AForm const &o);
		std::string getName() const;
		int		getGradeToSigned() const;
		int		getGradeToExecute() const;
		bool	isSigned() const;
		void	beSigned(Bureaucrat &bureaucrat);
		virtual const void	execute(Bureaucrat const &executor) = 0;
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, AForm const &Form);

#endif
