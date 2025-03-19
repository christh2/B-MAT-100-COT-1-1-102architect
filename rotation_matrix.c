/*
** EPITECH PROJECT, 2022
** rotation
** File description:
** matrix
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct.h"

float **r_display_matrix(var *ptr)
{
    printf("Rotation by a %g degree angle\n", fabs(ptr->angle / (PI / 180)));
    printf("%.2f\t%.2f\t%.2f\n",
    ptr->matrix[0][0], ptr->matrix[0][1], ptr->matrix[0][2]);
    printf("%.2f\t%.2f\t%.2f\n",
    ptr->matrix[1][0], ptr->matrix[1][1], ptr->matrix[1][2]);
    printf("%.2f\t%.2f\t%.2f\n",
    ptr->matrix[2][0], ptr->matrix[2][1], ptr->matrix[2][2]);
}

float **r_matrix(var *ptr, int ac, char **av)
{
    ptr->angle = atof(av[4]) * (PI / 180);
    ptr->matrix = (float **)malloc(sizeof(float *) * 3);
    ptr->matrix[0] = (float*)malloc(sizeof(float) * 3);
    ptr->matrix[1] = (float*)malloc(sizeof(float) * 3);
    ptr->matrix[2] = (float*)malloc(sizeof(float) * 3);
    ptr->matrix[0][0] = cos(ptr->angle);
    ptr->matrix[0][1] = -sin(ptr->angle);
    ptr->matrix[0][2] = 0;
    ptr->matrix[1][0] = sin(ptr->angle);
    ptr->matrix[1][1] = cos(ptr->angle);
    ptr->matrix[1][2] = 0;
    ptr->matrix[2][0] = 0;
    ptr->matrix[2][1] = 0;
    ptr->matrix[2][2] = 1;
}

float **rotation(int ac, char **av)
{
    if (ac == 5 && av[3][0] == '-' && av[3][1] == 'r' && check_numbers(av[1]) == 0 &&
        check_numbers(av[2]) == 0 && check_numbers(av[4]) == 0 && strlen(av[3]) == 2) {
        var *ptr = malloc(sizeof(var));
        r_matrix(ptr, ac, av);
        r_display_matrix(ptr);
        float *vector = malloc(sizeof(float) * 3);
        vector[0] = atof(av[1]);
        vector[1] = atof(av[2]);
        vector[2] = 1;
        float *multiplicate = malloc(sizeof(float) * 3);
        multiplicate[0] = ptr->matrix[0][0] * vector[0] +
            ptr->matrix[0][1] * vector[1] + ptr->matrix[0][2] * vector[2];
        multiplicate[1] = ptr->matrix[1][0] * vector[0] +
            ptr->matrix[1][1] * vector[1] + ptr->matrix[1][2] * vector[2];
        multiplicate[2] = ptr->matrix[2][0] * vector[0] +
            ptr->matrix[2][1] * vector[1] + ptr->matrix[2][2] * vector[2];
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n",
               vector[0], vector[1], multiplicate[0], multiplicate[1]);
        return ptr->matrix;
    } else if (ac != 5 || av[3][0] != '-' || check_numbers(av[1]) == 84 ||
               check_numbers(av[2]) == 84 || check_numbers(av[4]) == 84 || strlen(av[3]) != 2) exit (84);
}
