#include<stdio.h>
#include<stdlib.h>
#include<math.h> // log2f();

struct best_combinaison
{
    char class[2];
    float pas;
};
typedef struct best_combinaison b_c;

// prend un paramètre un tableau de taille 3 contenant le nombre qu'il y a de chaque espèce ET le nombre totale de fleurs
float entropy(float *nb_class, float efftot) 
{
	float val_entropy;
	float P_succes;
	
    for(int i=0; i<3; i++)
    {
        P_succes = nb_class[i] / efftot;
        
        if(P_succes != 0)
            val_entropy -= P_succes*log2f(P_succes);
    }
	return val_entropy;
}

//Compte le nombre de fleurs qui respectent (cbfg) et ne respectent pas la condition d'entrée (cbfd), et precise le nombre de fleurs de chaques classes dans les deux sous catégories évoquées précedemment 
float list_traversal(liste *list, )
{
    
}

// Retourne la valeur de comparaison la plus optimale (grâce à une comparaison des entropie) à utiliser pour une classe et un pas choisie en entrée (classe = PL & PW & SL & SW)
float compare(b_c value, float val_entropy, int val_max) 
{
    printf("Selectionner un char et un pas :\n");
    scanf("%s",value.class);
    scanf("%f",&value.pas);
    printf("%s , %f :\n");
    int pas = value.pas;
    
    for(int i=0; i<val_max; i++)
    {
        
        pas += value.pas;
    }
    
}

// Compare la combinaison la meilleur pour les 4 classes et retourne celle à utiliser
float compare_class() 
{
    
}

int main()
{
    float tab[3] = { 0, 49 , 5 };
	printf("entropy : %lf\n", entropy(tab,54));

	return 0;
}
