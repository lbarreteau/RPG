##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

UNIT_TEST	=	unit_tests

all:		make_project

make_project:
	make -C sources/

tests_run:
	make -C tests/
	./$(UNIT_TEST)
	gcovr

clean:
	make -C sources/ clean
	make -C tests/ clean

fclean: 	clean
	make -C sources/ fclean
	make -C tests/ fclean

re:		fclean all

.PHONY: make_lib tests_run moov_for_test clean fclean clean_lib fclean_lib re
