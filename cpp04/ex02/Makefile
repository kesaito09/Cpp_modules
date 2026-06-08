NAME		= abstract
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADERS		= AAnimal.hpp Brain.hpp Cat.hpp Dog.hpp
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
