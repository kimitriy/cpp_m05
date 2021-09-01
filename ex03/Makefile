# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburton <rburton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 11:32:38 by rburton           #+#    #+#              #
#    Updated: 2021/06/30 04:11:17 by rburton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	intern

HEADER		=	Bureaucrat.hpp \
				Form.hpp \
				ShrubberyCreationForm.hpp \
				RobotomyRequestForm.hpp \
				PresidentialPardonForm.hpp \
				Intern.hpp \

SRC 		= 	main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				ascii_tree.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp \

OBJS		= ${SRC:.cpp=.o}

CXX			= clang++

CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow -I.

RM			= rm -f

.PHONY: all clean re

all:		${NAME}


${OBJS}: 		${HEADER}
${NAME}:		${OBJS}
				${CXX} ${CPPFLAGS} -o ${NAME} ${OBJS} 

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIB}

re:		fclean all
