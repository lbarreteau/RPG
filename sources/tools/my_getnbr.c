/*
** EPITECH PROJECT, 2021
** My_getnbr
** File description:
** This script find number of the character in the string.
*/

static int check_operator(char const *str)
{
    int is_negative = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            is_negative++;
    }
    if (0 != is_negative % 2) {
        return (-1);
    } else if (0 == is_negative % 2) {
        return (1);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int nb = 0;

    for (int i = 0; (str[i] >= '0' && str[i] <= '9')
    || str[i] == '+' || str[i] == '-'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z' && str[i + 1] == '\0') ||
        (str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] == '\0')) {
            nb = nb * (str[i] - 48);
            return (nb);
        }
        if (str[i] >= '0' && str[i] <= '9') {
            nb = ((nb * 10) + str[i] - 48);
        }
        if (nb > 2147483647 || nb < -2147483647) {
            return (0);
        }
    }
    nb = nb * check_operator(str);
    return (nb);
}
