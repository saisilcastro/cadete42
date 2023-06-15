#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("empty") {
  std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm copy constructor called\n";
  *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &rhs) {
  std::cout << "RobotomyRequestForm assignation operator called\n";
  if (this != &rhs) {
    const_cast<std::string &>(this->_target) = rhs.getTarget();
  }
  return *this;
}

std::string const RobotomyRequestForm::getTarget() const {
  return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getSigned() || executor.getGrade() > this->getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::cout << "Brrr brrr brrr... ";
  std::srand(time(NULL));
  if (std::rand() % 2) {
    std::cout << this->_target << "\33[32m has been robotomized successfully\n";
  } else {
    std::cout << this->_target << "\33[31m robotomization failed\n";
  }
}
