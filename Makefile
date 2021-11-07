SRCS	= 	Libft/ft_itoa.c \
			Libft/ft_striteri.c \
			Libft/ft_strmapi.c \
			Libft/ft_putnbr_fd.c \
			Libft/ft_putendl_fd.c \
			Libft/ft_putstr_fd.c \
			Libft/ft_putchar_fd.c \
			Libft/ft_atoi.c \
			Libft/ft_bzero.c \
			Libft/ft_calloc.c \
			Libft/ft_memchr.c \
			Libft/ft_memcmp.c \
			Libft/ft_memcpy.c \
			Libft/ft_memmove.c \
			Libft/ft_memset.c \
			Libft/ft_strchr.c \
			Libft/ft_strdup.c \
			Libft/ft_strlcat.c \
			Libft/ft_strlcpy.c \
			Libft/ft_strlen.c \
			Libft/ft_strncmp.c \
			Libft/ft_strnstr.c \
			Libft/ft_strrchr.c \
			Libft/ft_tolower.c \
			Libft/ft_toupper.c \
			Libft/ft_split.c \
			Libft/ft_strjoin.c \
			Libft/ft_strtrim.c \
			Libft/ft_substr.c \
			Libft/ft_isalnum.c \
			Libft/ft_isalpha.c \
			Libft/ft_isascii.c \
			Libft/ft_isdigit.c \
			Libft/ft_isprint.c \
			ft_printf.c \
			utils_flags.c \
			utils_flags2.c \
			utils_output.c \

B_SRCS	=	Libft/ft_lstmap_bonus.c \
			Libft/ft_lstclear_bonus.c \
			Libft/ft_lstdelone_bonus.c \
			Libft/ft_lstiter_bonus.c \
			Libft/ft_lstadd_back_bonus.c \
			Libft/ft_lstlast_bonus.c \
			Libft/ft_lstsize_bonus.c \
			Libft/ft_lstadd_front_bonus.c \
			Libft/ft_lstnew_bonus.c \

OBJS	= $(SRCS:.c=.o)

B_OBJS	= $(B_SRCS:.c=.o)

LIBFTHEADS	= libft.h

HEADS		= ft_printf.h

LIBFTNAME	= libft.a

NAME	= libftprintf.a

GCC		= gcc

FLAGS	= -Wall -Werror -Wextra

AR		= ar -rcs

RM		= rm -f

.c.o:
		$(GCC) -c $(FLAGS) $< -o ${<:.c=.o} -I$(LIBFTHEADS) -I${HEADS}

$(NAME): $(OBJS) $(HEADS)
		$(AR) $(NAME) $(OBJS)

all:	$(NAME)

bonus:	$(B_OBJS) $(HEADS)
		$(AR) $(NAME) $(B_OBJS)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all