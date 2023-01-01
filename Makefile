# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:07:14 by steh              #+#    #+#              #
#    Updated: 2023/01/01 22:41:17 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	$(wildcard $(SRCS_DIR)/*.cpp)
SRCS_DIR		=	tester
OBJ_DIR			=	obj
HEAD_DIR		=	header
DEPENDS 		=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.d, $(SRCS))
NAME			=	program
# OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
OBJS			=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -g #-fsanitize=address
CXX				=	c++

all				: 	$(NAME)
					./$(NAME)

$(NAME)			:	$(OBJS)
					$(CXX) $(CXXFLAGS) $^ -o $@

 -include $(DEPENDS)

$(OBJ_DIR)/%.o	:	$(SRCS_DIR)/%.cpp Makefile
					mkdir -p $(dir $@)
					$(CXX) $(CXXFLAGS) -I$(HEAD_DIR) -MMD -MP -c $< -o $@

clean			:
					@rm -rf $(OBJ_DIR)

fclean			:	clean
					@rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
