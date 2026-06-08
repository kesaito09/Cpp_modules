NAME		= forms
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADERS		= AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)
re: fclean all
.PHONY: all clean fclean re
