# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2018/03/01 13:28:04 by mdeville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = libft.a
CC              = gcc
CFLAGS         += -Wall -Wextra -Werror
SRCDIR          = srcs/
OBJDIR          = .obj/
INCDIR          = includes/
RM              = rm
AR              = ar
ARFLAGS         = -rcs

# set the suffix list explicitly
.SUFFIXES:
.SUFFIXES: .c .o .d

# list all sources
CONVERSION_SRC  =	ft_atoi.c ft_atou.c ft_atoimax.c ft_itoa.c ft_utoa.c \
					ft_utoa_base.c

FT_CTYPE_SRC    =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isatty.c \
					ft_isblank.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c \
					ft_islower.c ft_isnumber.c ft_isprint.c ft_isspace.c \
					ft_isupper.c ft_isxdigit.c ft_tolower.c ft_toupper.c

DLST_SRC        =	ft_dlstappend.c ft_dlstdel.c ft_dlstdelone.c \
					ft_dlstfilter.c ft_dlstlen.c ft_dlstpop.c ft_dlstlink.c \
					ft_dlstremove.c ft_dlstnew.c ft_dlstprepend.c \
					ft_dlstreverse.c ft_dlstat.c ft_dlstiter.c \
					ft_dlstsort.c ft_dlst_to_tab.c ft_dlstcpy.c ft_dlstmap.c

FT_GETOPT_SRC   =	ft_getopt.c

FT_IO_SRC       =	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
					ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c

FT_PRINTF_SRC   =	ft_fprintf.c ft_printbin_fd.c ft_printchar_fd.c \
					ft_printf.c ft_printhexa_fd.c ft_printint_fd.c \
					ft_printitoa.c ft_printn_fd.c ft_printoctal_fd.c \
					ft_printpercent_fd.c ft_printpointer_fd.c ft_printstr_fd.c \
					ft_printuint_fd.c ft_printunichar_fd.c ft_printunistr_fd.c \
					ft_vfprintf.c ft_vprintf.c parse_token.c print_token.c

GNL_SRC         =	get_next_line.c

LST_SRC         =	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstfilter.c \
					ft_lstiter.c ft_lstlink.c ft_lstmap.c ft_lstnew.c \
					ft_lstpop.c ft_lstreverse.c ft_lstlen.c ft_lstremove.c \
					ft_lstappend.c

MEMORY_SRC      =	ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
					ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c

PATH_SRC        =	ft_basename.c ft_dirname.c

RBTREE_SRC      =	ft_rbnodenew.c

FT_STRING_SRC   =	ft_stpncpy.c ft_str_is_alpha.c ft_str_is_lowercase.c \
					ft_str_is_numeric.c ft_str_is_printable.c \
					ft_str_is_uppercase.c ft_strcapitalize.c ft_strcasecmp.c \
					ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
					ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
					ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
					ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncasecmp.c \
					ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c \
					ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnlen.c \
					ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
					ft_strsub.c ft_strtrim.c ft_strtrimc.c to_utf8.c \
					ft_strsplit_str.c

SRCDIRS         =	conversion/ ft_ctype/ dlst/ ft_getopt/ ft_io/ ft_printf/ \
					get_next_line/ lst/ memory/ path/ rbtree/ ft_string/

SRC             =	$(addprefix conversion/,$(CONVERSION_SRC)) \
					$(addprefix ft_ctype/,$(FT_CTYPE_SRC)) \
					$(addprefix dlst/,$(DLST_SRC)) \
					$(addprefix ft_getopt/,$(FT_GETOPT_SRC)) \
					$(addprefix ft_io/,$(FT_IO_SRC)) \
					$(addprefix ft_printf/,$(FT_PRINTF_SRC)) \
					$(addprefix get_next_line/,$(GNL_SRC)) \
					$(addprefix lst/,$(LST_SRC)) \
					$(addprefix memory/,$(MEMORY_SRC)) \
					$(addprefix path/,$(PATH_SRC)) \
					$(addprefix rbtree/,$(RBTREE_SRC)) \
					$(addprefix ft_string/,$(FT_STRING_SRC))


CFLAGS         += -I$(INCDIR)
OBJS            = $(SRC:.c=.o)
DEPS            = $(OBJS:.o=.d)
OUTPUT_OPTION   = -o $(OBJDIR)$@
CPPFLAGS       += -MT $@ -MMD -MP -MF $(OBJDIR)$(@:.o=.d)
OBJDIRS         = $(addprefix $(OBJDIR),$(SRCDIRS))

vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(addprefix $(OBJDIR),$(OBJS))

.SECONDEXPANSION:
$(OBJS): %: | $$(dir $(OBJDIR)%)
-include $(addprefix $(OBJDIR),$(DEPS))

$(OBJDIRS) $(OBJDIR):
	mkdir -p $@

clean:
	$(RM) -Rf $(OBJDIR)

fclean: | clean
	$(RM) -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) -j8

.PHONY: all clean fclean re
