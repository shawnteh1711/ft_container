# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:07:14 by steh              #+#    #+#              #
#    Updated: 2023/02/08 18:40:11 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	ft_container
SRCS_DIR		=	src
SRCS			=	$(wildcard $(SRCS_DIR)/*.cpp)
OBJ_DIR			=	obj
HEAD_DIR		=	header
DEPENDS 		=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.d, $(SRCS))
OBJS			=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -g #-fsanitize=address
CXX				=	c++ 

all				:	$(NAME)
					./$(NAME) 123

$(NAME)			:	$(OBJS)
					$(CXX) $(CXXFLAGS) $^ -o $@

 -include $(DEPENDS)

$(OBJ_DIR)/%.o	:	$(SRCS_DIR)/%.cpp Makefile
					mkdir -p $(dir $@)
					$(CXX) $(CXXFLAGS) -I$(HEAD_DIR) -MMD -MP -c $< -o $@

test			:
					$(CXX) $(CXXFLAGS) tester/pair_test.cpp tester/algorithms_test.cpp tester/integral_test.cpp tester/main_test.cpp tester/rbtree_test.cpp -o $(NAME)
					./$(NAME)

vector			:
					$(CXX) $(CXXFLAGS) tester/vector_test.cpp -o $(NAME)
					./$(NAME)

stack			:
					$(CXX) $(CXXFLAGS) tester/stack_test.cpp -o $(NAME)
					./$(NAME)

map				:
					$(CXX) $(CXXFLAGS) tester/map_test.cpp -o $(NAME)
					./$(NAME)

set				:
					$(CXX) $(CXXFLAGS) tester/set_test.cpp -o $(NAME)
					./$(NAME)

clean			:
					@rm -rf $(OBJ_DIR)

fclean			:	clean
					@rm -f $(NAME)

re				:	fclean all
