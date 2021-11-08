SRCS	= 	mandatory/ft_printf_utilities.c \
			mandatory/ft_printf.c \

B_SRCS	=	bonus/ft_printf_flags1_bonus.c \
			bonus/ft_printf_flags2_bonus.c \
			bonus/ft_printf_utilities1_bonus.c \
			bonus/ft_printf_utilities2_bonus.c \
			bonus/ft_printf_utilities3_bonus.c \
			bonus/ft_printf_bonus.c \

OBJS	= $(SRCS:.c=.o)

B_OBJS	= $(B_SRCS:.c=.o)

HEADS	= headers/

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

bonus:	fclean $(B_OBJS) $(HEADS)
		$(AR) $(NAME) $(B_OBJS)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all