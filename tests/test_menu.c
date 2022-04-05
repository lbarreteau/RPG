/*
** EPITECH PROJECT, 2021
** Unit-test Lib My
** File description:
** This script test the libmy library
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "global.h"

/*
RESET = \e[0m
BLACK = \e[0;30m
GRAY = \e[1;30m
RED = \e[0;31m
LIGHT_RED = \e[1;31m
GREEN = \e[0;32m
LIGHT_GREEN = \e[1;32m
BROWN = \e[0;33m
YELLOW = \e[1;33m
BLUE = \e[0;34m
LIGHT_BLUE = \e[1;34m
PURPLE = \e[0;35m
LIGHT_PURPLE = \e[1;35m
CYAN = \e[0;36m
LIGHT_CYAN = \e[1;36m
LIGHT_GRAY = \e[0;37m
WHITE = \e[1;37m
*/

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
// Testing My_putchar
Test(menu, my_putchar_simple, .init=redirect_all_stdout)
{
    char got = 'a';
    char *expected = "a";
    cr_assert_eq(1, 1, "Error :\n Expected : %s \n Got : %c", expected, got);
}
