
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat A("Mar1", 5);
        Intern someRandomIntern;
        AForm* form;

        try {
            form = someRandomIntern.makeForm("robotomy request", "Bender");
            form->beSigned(A);
            form->execute(A);
            delete form;
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
            delete form;
        }

        try {
            form = someRandomIntern.makeForm("shrubbery creation", "home");
            form->beSigned(A);
            form->execute(A);
            delete form;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            delete form;
        }

        try {
            form = someRandomIntern.makeForm("presidential pardon", "Bob");
            form->beSigned(A);
            form->execute(A);
            delete form;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            delete form;
        }

        form = someRandomIntern.makeForm("unknown form", "Unknown");
        if (form) {
            delete form;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
