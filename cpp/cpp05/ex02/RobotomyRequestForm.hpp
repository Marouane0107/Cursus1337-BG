#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &o);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &o);
        const void execute(Bureaucrat const &executor);
        ~RobotomyRequestForm();
};

#endif