# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:07:14 by steh              #+#    #+#              #
#    Updated: 2023/01/02 16:57:38 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SUBDIR			=	$(shell ls -d */)
# ROOTSRC			=	$(wildcard *.cpp)
# SRCS			=	$(wildcard $(SRC_DIR)/*.cpp)
# TESTERS			=	$(wildcard $(TESTERS_DIR)/*.cpp)
# SRCS_DIR		=	src
# TESTERS_DIR		=	tester
# OBJ_DIR			=	obj
# HEAD_DIR		=	header
# DEPENDS 		=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.d, $(SRCS))
# NAME			=	program
# # OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
# OBJS			=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
# CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address
# CXX				=	c++

# all				:	$(NAME)
# 					./$(NAME)

# $(NAME)			:	$(OBJS)
# 					$(CXX) $(CXXFLAGS) $^ -o $@

#  -include $(DEPENDS)

# $(OBJ_DIR)/%.o	:	$(SRCS_DIR)/%.cpp Makefile
# 					mkdir -p $(dir $@)
# 					$(CXX) $(CXXFLAGS) -I$(HEAD_DIR) -MMD -MP -c $< -o $@

# clean			:
# 					@rm -rf $(OBJ_DIR)

# fclean			:	clean
# 					@rm -f $(NAME)

# re				:	fclean all

# .PHONY			:	all clean fclean re

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address

NAME		=	main

SUBDIR		=	$(shell ls -d */) 
ROOTSRC		=	$(wildcard *.cpp) $(wildcard *.tpp)
ROOTOBJ		=	$(ROOTSRC:%.cpp=%.o)
SUBSRC		=	$(shell find $(SUBDIR) -name '*.cpp') $(shell find $(SUBDIR) -name '*.tpp')
SUBOBJ		=	$(SUBSRC:%.cpp=%.o)

all				:	$(NAME)
					./$(NAME)

$(NAME)		:	$(ROOTOBJ) $(SUBOBJ)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(ROOTOBJ) $(SUBOBJ)

.cpp.o		:	
				$(CXX) $(CXXFLAGS) -c $< -o $@

clean		:
				rm -f  $(ROOTOBJ) $(SUBOBJ)

fclean		:	clean
				@rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
