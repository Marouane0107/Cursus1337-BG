#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &o): AForm(o), target(o.target)
{
    *this = o;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &o)
{
    if (this != &o)
    {
        target = o.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    AForm::execute(executor);
    std::cout << "*drilling noises*" << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << " has failed to be robotomized" << std::endl;
}
