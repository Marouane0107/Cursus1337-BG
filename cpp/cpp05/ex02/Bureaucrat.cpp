#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("defeult"), _grade(50)
{}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &o)
{
    if(this != &o)
    {
        _grade = o._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &o) : _name(o._name)
{
    *this = o;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void    Bureaucrat::increment()
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void    Bureaucrat::decrement()
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}

void    Bureaucrat::signForm(AForm &form)
{
    try{
        form.beSigned(*this);
        std::cout << getName() << " signed " << getName() << std::endl;
    }
    catch (const std::exception &e){
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form)
{
    
}

std::ostream   &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return out;
}