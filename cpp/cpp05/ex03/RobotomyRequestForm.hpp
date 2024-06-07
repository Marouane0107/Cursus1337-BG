#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
class RobotomyRequestForm: public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &o);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &o);
        void    execute(Bureaucrat const &executor) const;
        ~RobotomyRequestForm();
};

#endif