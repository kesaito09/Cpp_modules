NAME		= materia
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADERS		= AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp
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
