SRCS	=	srcs/ft_printf_flags1.c \
			srcs/ft_printf_flags2.c \
			srcs/ft_printf_utilities1.c \
			srcs/ft_printf_utilities2.c \
			srcs/ft_printf_utilities3.c \
			srcs/ft_printf.c \

OBJS	= $(SRCS:.c=.o)

HEADS	= headers/ft_printf.h

NAME	= libftprintf.a

GCC		= gcc

FLAGS	= -Wall -Werror -Wextra

AR		= ar -crs

RM		= rm -f



.c.o:
		$(GCC) -c $(FLAGS) $< -o ${<:.c=.o} -I$(HEADS)

$(NAME): $(OBJS) $(HEADS)
		$(AR) $(NAME) $(OBJS)

all:	$(NAME)

bonus:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all