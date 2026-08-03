#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
 private:
  const std::string name_;
  int grade_;
  void checkGrade(int grade) const;

 public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat&);
  ~Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat&);

  class GradeTooHighException : public std::exception {
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char* what() const throw();
  };
  const std::string& getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat* bureaucrat);

#endif
