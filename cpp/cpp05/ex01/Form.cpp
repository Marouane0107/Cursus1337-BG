#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form(): _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(150){
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (gradeToExecute < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &form): _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	*this = form;
}

Form &Form::operator=(Form const &o)
{
	if (this != &o)
	{
		_signed = o._signed;
	}
	return (*this);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Form::~Form(){
}

std::string  Form::getName() const
{
	return (_name);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool    Form::isSigne()
{
	return (_signed);
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute();
	return out;
}

