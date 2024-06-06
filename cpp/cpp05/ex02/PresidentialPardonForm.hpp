#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &o);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &o);
        void    execute(Bureaucrat const &executor) const;
        ~PresidentialPardonForm();
};

#endif