#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 150);
        Bureaucrat alice("Alice", 1);
        
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Alice");
        PresidentialPardonForm pardon("Bob");

        bob.executeForm(shrubbery);  // Should fail because form is not signed
        alice.executeForm(robotomy); // Should fail because form is not signed
        alice.executeForm(pardon);   // Should fail because form is not signed
        
        std::cout << "Signing forms..." << std::endl;
        
        shrubbery.beSigned(alice); // Should fail because Alice's grade is too low to sign the form
        robotomy.beSigned(alice); // Should succeed
        pardon.beSigned(alice);   // Should succeed
        
        bob.executeForm(shrubbery);  // Should fail because Bob's grade is too low to execute the form
        alice.executeForm(shrubbery); // Should succeed
        
        alice.executeForm(robotomy);  // Should succeed, with a 50% chance of either outcome
        alice.executeForm(pardon);    // Should succeed

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

