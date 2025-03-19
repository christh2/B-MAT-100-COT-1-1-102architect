/*
** EPITECH PROJECT, 2022
** check_arg
** File description:
** 102architect
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct.h"

int check_numbers(char *str)
{
    int i;
    for (i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') &&
            str[i] != '-' && str[i] != '.' && str[i] != '+') {
            return 84;
        } else {
            return (0);
        }
    }
}
