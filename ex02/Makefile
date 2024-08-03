# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 14:35:06 by bdelamea          #+#    #+#              #
#    Updated: 2024/08/03 13:00:21 by bdelamea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################### BEG ####

NAME        := ex02

INCS        := include \

SRC_DIR     := src
SRCS        := \
			main.cpp \

SRCS        := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

CXX         := c++
CXXFLAGS    := -std=c++98 -Wall -Wextra -Werror -g
INCXXFLAGS  := $(addprefix -I ,$(INCS))

RMF         := rm -f
RMR         := rm -rf
MAKEFLAGS   += --silent --no-print-directory #-j #remove to see relink + flags silence 
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CXX) $(CXXFLAGS) $(INCXXFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	for f in $(dir ); do $(MAKE) -C $$f clean; done
	$(RMF) $(OBJS) $(DEPS)
	$(RMR) $(BUILD_DIR)

fclean: clean
	for f in $(dir ); do $(MAKE) -C $$f fclean; done
	$(RMF) $(NAME)
	$(RMR) $(BUILD_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

.PHONY: clean fclean re
.SILENT: #remove to see relink + flags silence 

####################################### END ####
