#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSigned(50), _gradeToExecute(150){
}

AForm::AForm(std::string name, int gradeToSigned, int gradeToExecute): _name(name), _isSigned(false), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute)
{
	if (gradeToSigned > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSigned < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(AForm const &o)
{
	if (this != &o)
	{
		_isSigned = o._isSigned;
	}
	return *this;
}

AForm::AForm(AForm const &o): _name(o._name), _gradeToSigned(o._gradeToSigned), _gradeToExecute(o._gradeToExecute)
{
	*this = o;
}


AForm::~AForm(){
}

std::string AForm::getName() const{
	return (_name);
}

int AForm::getGradeToSigned() const{
	return (_gradeToSigned);
}

int AForm::getGradeToExecute() const{
	return(_gradeToExecute);
}

bool	AForm::isSigned() const{
	return (_isSigned);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToSigned())
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	else if (!isSigned())
		throw FormNotSignedException();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream	&operator<<(std::ostream &out, AForm const &AForm)
{
	out << AForm.getName() << " is " << (AForm.isSigned() ? "signed" : "not signed") << std::endl;
	return out;
}
