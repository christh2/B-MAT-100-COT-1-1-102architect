/*
** EPITECH PROJECT, 2022
** struct
** File description:
** structure
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14159

#ifndef  _MATRIX_
    #define _MATRIX_
typedef struct matrix{
    float i;
    float j;
    float **matrix;
    float angle;
}var;
float **t_display_matrix(var *ptr);
float **z_display_matrix(var *ptr);
float **r_display_matrix(var *ptr);
float **s_display_matrix(var *ptr);
float **t_matrix(var *ptr, int ac, char **av);
float **z_matrix(var *ptr, int ac, char **av);
float **r_matrix(var *ptr, int ac, char **av);
float **s_matrix(var *ptr, int ac, char **av);
float **translation_along_vector(int ac, char **av);
float **scaling_factors(int ac, char **av);
float **rotation(int ac, char **av);
float **reflection_axis(int ac, char**av);
int check_numbers(char *str);
#endif /*_MATRIX_*/