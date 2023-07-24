CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = rush-02
SRCS = ./main.c ./str_aux_ft.c ./auxiliar_functions.c ./auxiliar_functions2.c auxiliar_functions3.c ./read_file.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 


clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) 
