# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:07:14 by steh              #+#    #+#              #
#    Updated: 2023/01/05 19:25:57 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	ft_container
SRCS_DIR		=	src
SRCS			=	$(wildcard $(SRCS_DIR)/*.cpp)
OBJ_DIR			=	obj
HEAD_DIR		=	header
DEPENDS 		=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.d, $(SRCS))
OBJS			=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address
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
					$(CXX) $(CXXFLAGS) tester/*.cpp -o $(NAME)
					./$(NAME)

clean			:
					@rm -rf $(OBJ_DIR)

fclean			:	clean
					@rm -f $(NAME)

re				:	fclean all
