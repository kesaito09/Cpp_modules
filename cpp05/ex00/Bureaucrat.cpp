#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : name_("Default"), grade_(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name_(name), grade_(grade) {
  checkGrade(grade);
  std::cout << "object created\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {
  std::cout << "copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other)
	
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::checkGrade(int grade) const {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade Too Low";
}

int Bureaucrat::getGrade() const { return grade_; }

const std::string& Bureaucrat::getName() const { return name_; }

void Bureaucrat::incrementGrade(void) {
  checkGrade(grade_ + 1);
  ++grade_;
}
void Bureaucrat::decrementGrade(void) {
  checkGrade(grade_ - 1);
  --grade_;
}
