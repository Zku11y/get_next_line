src = get_next_line.c get_next_line_utils.c
NAME = get_next_line.a
obj = $(src:.c=.o)

all:$(NAME)

$(NAME):$(obj)
	ar rcs $(NAME) $(obj)

m1:
	@cc -Wall -Wextra -Werror main.c
	@./a.out | cat -e

m2:
	@cc -Wall -Wextra -Werror -g main2.c $(src)
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out | cat -e

m2n:
	@cc -Wall -Wextra -Werror main2.c $(src)
	@./a.out | cat -e
clean:
	rm $(obj)

fclean: clean
	rm $(NAME)

re:fclean $(NAME)

.PHONY: clean