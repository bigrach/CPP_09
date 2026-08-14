CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = btc

# SOURCES
SOURCES =	main.cpp

# OBJECTS
obj_dir = obj
OBJECTS = $(addprefix $(obj_dir)/, $(SOURCES:.cpp=.o))

# WHERE
VPATH = src
INCLUDES = inc

# RULES
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) -o $(NAME) $(OBJECTS)

$(obj_dir)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -rf $(obj_dir)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
