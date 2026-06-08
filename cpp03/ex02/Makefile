NAME		= fragtrap
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= ClapTrap.cpp FragTrap.cpp ScavTrap.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADERS		= ClapTrap.hpp FragTrap.hpp ScavTrap.hpp
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
