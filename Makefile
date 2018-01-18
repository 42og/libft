NAME=libft.a
CC=clang
CFLAGS=-Wall -Wextra -Werror
INCLUDES=-Iincludes/
AR=ar
ARFLAGS=-rcs

SRC = srcs/conversion/ft_atoi.c \
	srcs/conversion/ft_atou.c \
	srcs/conversion/ft_atoimax.c \
	srcs/conversion/ft_itoa.c \
	srcs/conversion/ft_utoa.c \
	srcs/conversion/ft_utoa_base.c \
	srcs/ctype/ft_isalnum.c \
	srcs/ctype/ft_isalpha.c \
	srcs/ctype/ft_isascii.c \
	srcs/ctype/ft_isatty.c \
	srcs/ctype/ft_isblank.c \
	srcs/ctype/ft_iscntrl.c \
	srcs/ctype/ft_isdigit.c \
	srcs/ctype/ft_isgraph.c \
	srcs/ctype/ft_islower.c \
	srcs/ctype/ft_isnumber.c \
	srcs/ctype/ft_isprint.c \
	srcs/ctype/ft_isspace.c \
	srcs/ctype/ft_isupper.c \
	srcs/ctype/ft_isxdigit.c \
	srcs/ctype/ft_tolower.c \
	srcs/ctype/ft_toupper.c \
	srcs/dlst/ft_dlstappend.c \
	srcs/dlst/ft_dlstdel.c \
	srcs/dlst/ft_dlstdel_back.c \
	srcs/dlst/ft_dlstdel_front.c \
	srcs/dlst/ft_dlstdelone.c \
	srcs/dlst/ft_dlstfilter.c \
	srcs/dlst/ft_dlstnew.c \
	srcs/dlst/ft_dlstprepend.c \
	srcs/dlst/ft_dlstreverse.c \
	srcs/ft_getopt/ft_getopt.c \
	srcs/ft_io/ft_putchar.c \
	srcs/ft_io/ft_putchar_fd.c \
	srcs/ft_io/ft_putendl.c \
	srcs/ft_io/ft_putendl_fd.c \
	srcs/ft_io/ft_putnbr.c \
	srcs/ft_io/ft_putnbr_fd.c \
	srcs/ft_io/ft_putstr.c \
	srcs/ft_io/ft_putstr_fd.c \
	srcs/ft_printf/ft_fprintf.c \
	srcs/ft_printf/ft_printbin_fd.c \
	srcs/ft_printf/ft_printchar_fd.c \
	srcs/ft_printf/ft_printf.c \
	srcs/ft_printf/ft_printhexa_fd.c \
	srcs/ft_printf/ft_printint_fd.c \
	srcs/ft_printf/ft_printitoa.c \
	srcs/ft_printf/ft_printn_fd.c \
	srcs/ft_printf/ft_printoctal_fd.c \
	srcs/ft_printf/ft_printpercent_fd.c \
	srcs/ft_printf/ft_printpointer_fd.c \
	srcs/ft_printf/ft_printstr_fd.c \
	srcs/ft_printf/ft_printuint_fd.c \
	srcs/ft_printf/ft_printunichar_fd.c \
	srcs/ft_printf/ft_printunistr_fd.c \
	srcs/ft_printf/ft_vfprintf.c \
	srcs/ft_printf/ft_vprintf.c \
	srcs/ft_printf/parse_token.c \
	srcs/ft_printf/print_token.c \
	srcs/get_next_line/get_next_line.c \
	srcs/lst/ft_lstadd.c \
	srcs/lst/ft_lstdel.c \
	srcs/lst/ft_lstdelone.c \
	srcs/lst/ft_lstfilter.c \
	srcs/lst/ft_lstiter.c \
	srcs/lst/ft_lstlink.c \
	srcs/lst/ft_lstmap.c \
	srcs/lst/ft_lstnew.c \
	srcs/lst/ft_lstpop.c \
	srcs/lst/ft_lstreverse.c \
	srcs/memory/ft_bzero.c \
	srcs/memory/ft_memalloc.c \
	srcs/memory/ft_memccpy.c \
	srcs/memory/ft_memchr.c \
	srcs/memory/ft_memcmp.c \
	srcs/memory/ft_memcpy.c \
	srcs/memory/ft_memdel.c \
	srcs/memory/ft_memmove.c \
	srcs/memory/ft_memset.c \
	srcs/path/ft_basename.c \
	srcs/rbtree/ft_rbnodenew.c \
	srcs/string/ft_stpncpy.c \
	srcs/string/ft_str_is_alpha.c \
	srcs/string/ft_str_is_lowercase.c \
	srcs/string/ft_str_is_numeric.c \
	srcs/string/ft_str_is_printable.c \
	srcs/string/ft_str_is_uppercase.c \
	srcs/string/ft_strcapitalize.c \
	srcs/string/ft_strcasecmp.c \
	srcs/string/ft_strcat.c \
	srcs/string/ft_strchr.c \
	srcs/string/ft_strclr.c \
	srcs/string/ft_strcmp.c \
	srcs/string/ft_strcpy.c \
	srcs/string/ft_strdel.c \
	srcs/string/ft_strdup.c \
	srcs/string/ft_strequ.c \
	srcs/string/ft_striter.c \
	srcs/string/ft_striteri.c \
	srcs/string/ft_strjoin.c \
	srcs/string/ft_strlcat.c \
	srcs/string/ft_strlen.c \
	srcs/string/ft_strmap.c \
	srcs/string/ft_strmapi.c \
	srcs/string/ft_strncasecmp.c \
	srcs/string/ft_strncat.c \
	srcs/string/ft_strncmp.c \
	srcs/string/ft_strncpy.c \
	srcs/string/ft_strndup.c \
	srcs/string/ft_strnequ.c \
	srcs/string/ft_strnew.c \
	srcs/string/ft_strnjoin.c \
	srcs/string/ft_strnlen.c \
	srcs/string/ft_strnstr.c \
	srcs/string/ft_strrchr.c \
	srcs/string/ft_strsplit.c \
	srcs/string/ft_strstr.c \
	srcs/string/ft_strsub.c \
	srcs/string/ft_strtrim.c \
	srcs/string/ft_strtrimc.c \
	srcs/string/to_utf8.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@zsh -c "echo -n '\tCompiling $<'"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@zsh -c 'echo -e "\r\t\033[32mCompiled $@\033[0m "'

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	$(MAKE)
