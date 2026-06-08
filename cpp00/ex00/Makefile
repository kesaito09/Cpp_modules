NAME		= megaphone
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: $(OBJS)
	rm -f $(OBJS)

fclean: $(OBJS) $(NAME)
	rm -f $(OBJS) $(NAME)
re: fclean all
