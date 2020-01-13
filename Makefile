# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#              #
#    Updated: 2020/01/13 12:33:35 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash
CC = gcc

NAME                =   doom-nukem
CFLAG       		=   -Wall -Wextra -Werror -g
MESSAGE     		=   "\033[38;5;79m[$(NAME)] compiled on normal rules ! Have fun\033[0m                          "

INCDIR              =   ./inc/
OBJDIR              =   ./obj/
LIBFTDIR            =   ./libft/
SRCDIR              =   ./src/

INCFIL              =   doom.h
OBJFIL              =   $(SRCFIL:.c=.o)
LIBFTFIL            =   libft.a
SRCFIL				=	main.c 

SRC                 =   $(addprefix $(SRCDIR),$(SRCFIL))
OBJ                 =   $(addprefix $(OBJDIR),$(OBJFIL))
LIBFT               =   $(addprefix $(LIBFTDIR),$(LIBFTFIL))
INC                 =   $(addprefix $(INCDIR),$(INCFIL))
INCLIBFT            =   $(LIBFTDIR)inc
LIBFT_FLAG          =   -L$(LIBFTDIR) -lft

SDL_PATH            =   ./SDL2-2.0.9/
LIBSDL_ROOT         =   ./libSDL2/
LIBSDL_PATH         =   ./libSDL2/lib/
LIBSDL              =   libSDL2.a
INCSDL              =   $(LIBSDL_ROOT)include/
LIBSDL_FLAG         =   -L$(LIBSDL_PATH) -lSDL2 -lSDL2_mixer
SDLBIN              =   $(addprefix $(LIBSDL_PATH),$(LIBSDL))
SDL_CURL            =   `curl https://www.libsdl.org/release/SDL2-2.0.9.zip -o sdl2.zip`

SDLMIX_PATH         =   ./SDL2_mixer-2.0.4/
LIBSDLMIX_ROOT      =   ./libSDL2/
LIBSDLMIX_PATH      =   ./libSDL2/lib/
LIBSDLMIX           =   libSDL2_mixer.a
INCSDLMIX           =   $(LIBSDLMIX_ROOT)include/
SDLMIXBIN           =   $(addprefix $(LIBSDLMIX_PATH),$(LIBSDLMIX))
CURL_MIX            =   `curl https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.4.zip -o sdl_mix.zip`

T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
PROGRESS = "[`expr $C '*' 100 / $T`%]"

all                 :   libft sdl sdlmix $(NAME)

$(NAME)             :   $(OBJ) $(LIBFT)
						@$(CC) $(CFLAG) -lm $(LIBFT_FLAG) $(LIBSDL_FLAG) -o $@ $^ -lpthread
						@echo -e $(MESSAGE)
						@cd makefile_sources && gcc drawing.c && ./a.out

$(OBJDIR)%.o        :   $(SRCDIR)%.c Makefile inc/defines.h inc/doom.h inc/structs.h
						@mkdir -p $(OBJDIR)
						@mkdir -p ./obj/editor
						@$(CC) $(CFLAG) -I $(INCDIR) -I $(INCLIBFT) -I $(INCSDL) -o $@ -c $<
						@echo -ne "[$(NAME)] progress : $(PROGRESS) | $@               \r"

libft               :   $(LIBFT)

$(LIBFT)            :   $(LIBFTDIR)
						@make -C $(LIBFTDIR)

sdl                 :   $(SDLBIN)

$(SDLBIN)           :
						$(SDL_CURL)
						unzip sdl2.zip
						rm sdl2.zip
						mkdir -p $(LIBSDL_ROOT)
						cd $(SDL_PATH) && ./configure --prefix=$(PWD)/$(LIBSDL_ROOT)
						make -C $(SDL_PATH)
						make install -C $(SDL_PATH)

sdlmix              :   $(SDLMIXBIN)

$(SDLMIXBIN)        :
						$(CURL_MIX)
						unzip sdl_mix.zip
						rm sdl_mix.zip
						cd $(SDLMIX_PATH) && ./configure --prefix=$(PWD)/$(LIBSDLMIX_ROOT)
						make -C $(SDLMIX_PATH)
						make install -C $(SDLMIX_PATH)

clean               :
						@make -C $(LIBFTDIR) clean
						@rm -Rf  $(OBJDIR)

fclean              :
						@make -C $(LIBFTDIR) fclean
						@echo -ne "Cleaning [$(NAME)]... In progress...\r"
						@rm -Rf  $(OBJDIR)
						@rm -f $(NAME)
						@echo -e "Cleaning [$(NAME)] done !                           "

sdlclean            :
						rm -rf $(LIBSDL_ROOT)
						rm -rf $(SDL_PATH)
						rm -rf $(LIBSDLMIX_ROOT)
						rm -rf $(SDLMIX_PATH)

re                  :   fclean all
