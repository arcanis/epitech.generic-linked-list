NAME    = demo

SRCS    = $(shell find . -name '*.c')
OBJS    = $(SRCS:.c=.o)

CC      = gcc
RM      = rm -f

CFLAGS  = -I.. -Wall -Wextra -Werror -g
LDFLAGS = 

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS)