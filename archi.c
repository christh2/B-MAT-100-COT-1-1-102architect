/*
** EPITECH PROJECT, 2022
** 102
** File description:
** 102architect
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && strlen(av[1]) == 2) {
            printf("USAGE\n");
            printf("   ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...\n");
            printf("\n"); printf("DESCRIPTION\n");printf("   x   abscissa of the original point\n");
            printf("   y   ordinate of the original point");printf("\n");
            printf("   transfo arg1 [arg2]\n"); printf("   -t i j translation along vector (i, j)\n");
            printf("   -z m n scaling by factors m (x-axis) and n (y-axis)\n");
            printf("   -r d rotation centered in O by a d degree angle\n");
            printf("   -s d reflection over the axis passing through O with an inclination\n");
            printf("        angle of d degrees\n");
            return (0);
        }
    }
    else if (ac == 5) {
        if (av[3][0] == '-' && av[3][1] == 'r') {
            float** r = rotation(ac, av);
            return (0);
        } else if (av[3][0] == '-' && av[3][1] == 's') {
            float **s = reflection_axis(ac, av);
            return (0);
        }
    }
    if (ac == 6) {
        if (av[3][0] == '-' && av[3][1] == 't') {
            float** v = translation_along_vector(ac, av);
            return (0);
        }
        if (av[3][0] == '-' && av[3][1] == 'z') {
            float** h = scaling_factors(ac, av);
            return (0);
        }
    } else return 84;
}
