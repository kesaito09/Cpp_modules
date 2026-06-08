NAME		= animal
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADERS		= Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
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
