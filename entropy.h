#ifndef _ENTROPY_H_
#define _ENTROPY_H_

#include <math.h> // log2f();
#include "iris.h"

struct best_combinaison
{
    char class[2];
    float pas;
};
typedef struct best_combinaison b_c;

struct compteur
{
    int cpt;
    char espece[4];
};
typedef struct compteur compteur;

float entropy(float *nb_class, float efftot);

int readflowername(char *Array);

int list_traversal(list *liste, float condition, int sign, int parametre, int *setosa, int *versicolor, int *virginica);

#endif // _ENTROPY_H_
