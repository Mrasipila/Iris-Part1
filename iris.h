#ifndef _IRIS_H_
#define _IRIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct sNode node;
typedef struct sList list;

typedef struct sFlower
{
	float			m_petalWidth;		/**< Largeur p�tale (param�tre 4)								*/
	float			m_petalLength;		/**< Longueur p�tal (param�tre 3)								*/
	float			m_sepalWidth;		/**< Largeur s�pal (param�tre 2)								*/
	float			m_sepalLength;		/**< Longueur s�pal (param�tre 1)								*/
	char		m_specieNamed[30];		/**< Nom de l'�sp�ce (classe)													*/
}flower;

struct sList
{
	flower			m_node;			/**< Caract�ristique de la fleur										*/
	list *			m_next;			/**< Pointeur vers le noeud de liste suivant.							*/
};

struct sNode
{
	int			m_valueCompared;	/**< Valeur de comparaison des param�tre								*/
	int 		m_parameter;		/**< Param�tre compar�													*/
	float		m_entropy;			/**< Entropie du noeud													*/
	int			m_samples;			/**< Nombre de fleur dans le noeud										*/
	int *		m_tabValue;			/**< Tableau du nombre fleur par �sp�ce									*/

	list *		m_iris;				/**< Liste des fleurs													*/

	node *		m_leftSon;			/**< Noeud fils gauche													*/
	node *		m_rightSon;			/**< Noeud fils droit													*/
};


list * CreateDataList(FILE* p_file);

float entropy(float nb_class1, float nb_class2, float nb_class3, float efftot);







#endif //_IRIS_H_