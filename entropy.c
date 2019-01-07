#include "iris.h"
#include "entropy.h"

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


// Foncion qui compare 
int readflowername(char *Array)
{
        char Seto[] = "Iris-setosa";
        char Virgi[] = "Iris-virginica";
        char Versi[] = "Iris-versicolor";
        
        if( strcmp(Array,Seto) == 0 )
        {
            return 1;
        }
        else if( strcmp(Array,Virgi) == 0 )
        {
            return 2;
        }
        else if( strcmp(Array,Versi) == 0 )
        {
            return 3;
        }
        else
        {
            printf("espece inconnu\n");
            return 0;
        }
}

//Compte le nombre de fleurs qui respectent (cbfg) et ne respectent pas la condition d'entrée (cbfd), et precise le nombre de fleurs de chaques classes dans les deux sous catégories évoquées précedemment 
int list_traversal(list *liste, float condition, int sign, int parametre, int *setosa, int *versicolor, int *virginica)// sign = 0 => '<' sign = 1 => '>'
{
    (*setosa) = 0;
    (*virginica) = 0;
    (*versicolor) = 0;
    
    if(liste == NULL)
    {
        printf("No defined list\n");
        exit(-1);
    }
    else
    {
        flowerListNode * courant;
        courant = liste->m_head;
        
        while(courant->m_next != NULL)
        {
            if(sign == 0)
            {
                // PW
                if(parametre == 4)
                {
                    if( courant->m_dataFlower.m_petalWidth <= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 106 \n");
                    }
                }
                //PL
                if(parametre == 3)
                {
                    if( courant->m_dataFlower.m_petalLength <= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 125 \n");
                    }
                }
                //SW
                if(parametre == 2)
                {
                    if( courant->m_dataFlower.m_sepalWidth <= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 144 \n");
                    }
                }
                //SL
                if(parametre == 1)
                {
                    if( courant->m_dataFlower.m_sepalLength <= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 163 \n");
                    }
                }
            }
            
            if(sign == 1)
            {
                // PW
                if(parametre == 4)
                {
                    if( courant->m_dataFlower.m_petalWidth >= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 187 \n");
                    }
                }
                //PL
                if(parametre == 3)
                {
                    if( courant->m_dataFlower.m_petalLength >= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 206 \n");
                    }
                }
                //SW
                if(parametre == 2)
                {
                    if( courant->m_dataFlower.m_sepalWidth >= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 225 \n");
                    }
                }
                //SL
                if(parametre == 1)
                {
                    if( courant->m_dataFlower.m_sepalLength >= condition )
                    {
                        if( readflowername(courant->m_dataFlower.m_specieNamed) == 1 )
                        {
                            (*setosa)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 2 )
                        {
                            (*virginica)++;
                        }
                        else if( readflowername(courant->m_dataFlower.m_specieNamed) == 3 )
                        {
                            (*versicolor)++;
                        }
                        else
                            printf("erreur ligne 244 \n");
                    }
                }
            }
            
            courant = courant->m_next;
        }
        
    }
    
    int N_respected_condition;
    N_respected_condition = *setosa + (*virginica) + (*versicolor); 
    return N_respected_condition;
}

// Retourne la valeur de comparaison la plus optimale (grâce à une comparaison des entropie) à utiliser pour une classe et un pas choisie en entrée (classe = PL & PW & SL & SW)
/*
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
*/
/*

int main()
{
    float tab[3] = { 0, 49 , 5 };
	printf("entropy : %lf\n", entropy(tab,54));
    
	return 0;
}
*/
