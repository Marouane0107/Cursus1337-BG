#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &o): AForm(o), target(o.target)
{
    *this = o;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &o)
{
    if (this != &o)
    {
        target = o.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
