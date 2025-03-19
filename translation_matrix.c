/*
** EPITECH PROJECT, 2022
** translation
** File description:
** translation
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct.h"

float **t_display_matrix(var *ptr)
{
    printf("Translation along vector (%g, %g)\n", ptr->i, ptr->j);
    printf("%.2f\t%.2f\t%.2f\n",
    ptr->matrix[0][0], ptr->matrix[0][1], ptr->matrix[0][2]);
    printf("%.2f\t%.2f\t%.2f\n",
    ptr->matrix[1][0], ptr->matrix[1][1], ptr->matrix[1][2]);
    printf("%.2f\t%.2f\t%.2f\n",
    ptr->matrix[2][0], ptr->matrix[2][1], ptr->matrix[2][2]);
}

float **t_matrix(var *ptr, int ac, char **av)
{
    ptr->i = atof(av[4]);
    ptr->j = atof(av[5]);
    ptr->matrix = (float **)malloc(sizeof(float *) * 3);
    ptr->matrix[0] = (float*)malloc(sizeof(float) * 3);
    ptr->matrix[1] = (float*)malloc(sizeof(float) * 3);
    ptr->matrix[2] = (float*)malloc(sizeof(float) * 3);
    ptr->matrix[0][0] = 1;
    ptr->matrix[0][1] = 0;
    ptr->matrix[0][2] = ptr->i;
    ptr->matrix[1][0] = 0;
    ptr->matrix[1][1] = 1;
    ptr->matrix[1][2] = ptr->j;
    ptr->matrix[2][0] = 0;
    ptr->matrix[2][1] = 0;
    ptr->matrix[2][2] = 1;
}

float **translation_along_vector(int ac, char **av)
{
    if (ac == 6 && av[3][0] == '-' && av[3][1] == 't' && (check_numbers(av[1]) == 0) &&
        (check_numbers(av[2]) == 0) && (check_numbers(av[4]) == 0) &&
        (check_numbers(av[5]) == 0) && strlen(av[3]) == 2) {
        var *ptr = malloc(sizeof(var));
        t_matrix(ptr, ac, av); t_display_matrix(ptr);
        float *vector = malloc(sizeof(float) * 3);
        vector[0] = atof(av[1]); vector[1] = atof(av[2]); vector[2] = 1;
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
    } else if (ac != 6 || av[3][1] != 't' || check_numbers(av[1]) == 84
     || check_numbers(av[2]) == 84 || check_numbers(av[4]) == 84 ||
    check_numbers(av[5]) == 84 || strlen(av[3]) != 2) exit (84); 
}
