NAME	= pra
CXX		= c++
CXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS	= pra.cpp filestream.cpp
OBJS	=$(SRCS:.cpp=.o)
HEADERS	= pra.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXFLAGS) -c $< -o $@


