##
## EPITECH PROJECT, 2022
## makefile my_printf
## File description:
## makefile my_printf
##

CF = --coverage -lcriterion

SRC = function_1_print.c \
	function_2_print.c \
	function_3_print.c \
	function_4_print.c \
	function_6_print.c \
	print_under_fonc.c \
	function_print_float_pow_null.c \
	function_print_float_pow_pos.c \
	my_printf.c \
	my_put_nbr.c \
	my_putchar.c \
	my_putstr.c \
	my_strlen.c \
	my_put_nbr_base.c \
	my_showstr.c \
	my_put_nbr_ll.c \
	my_getnbr.c \
	my_compute_power_rec.c

OBJ = $(SRC:.c=.o)

TARGET = libmy.a

$(TARGET) : $(OBJ)
	ar rsc $(TARGET) $(OBJ)

all: $(TARGET)

tests_run: $(TARGET) clean
	gcc -o unit_test $(SRC) tests/*.c -L. -I include/ -lmy $(CF)
	./unit_test

test_cover : tests_run
	gcovr -s . --html-details -o =html --branches --exclude tests/
	rm -rf *.gc*
	rm -rf $(OBJ)
	rm unit_test
	open =html

clean :
	rm -rf $(OBJ)
	rm -rf *.html
	rm -rf *.css
	rm -rf html


fclean : clean
	rm -rf $(TARGET)

re : fclean all
