#ifndef _IRIS_H_
#define _IRIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct sNode node;
typedef struct sFlowerListNode flowerListNode;
typedef struct sList list;

struct sList
{
	flowerListNode *		m_head;					/**< Pointeur sur la tête de liste										*/
};

typedef struct sFlower
{
	float					m_petalWidth;			/**< Largeur pétale (paramètre 4)										*/
	float					m_petalLength;			/**< Longueur pétal (paramètre 3)										*/
	float					m_sepalWidth;			/**< Largeur sépal (paramètre 2)										*/
	float					m_sepalLength;			/**< Longueur sépal (paramètre 1)										*/
	char					m_specieNamed[30];		/**< Nom de l'éspèce (classe)											*/
}flower;

struct sFlowerListNode
{
	flower					m_dataFlower;			/**< Caractéristique de la fleur										*/
	flowerListNode *		m_next;					/**< Pointeur vers le noeud de liste suivant.							*/
};

struct sNode
{
	int						m_valueCompared;		/**< Valeur de comparaison des paramètre								*/
	int 					m_parameter;			/**< Paramètre comparé													*/
	float					m_entropy;				/**< Entropie du noeud													*/
	int						m_samples;				/**< Nombre de fleur dans le noeud										*/
	int *					m_tabValue;				/**< Tableau du nombre fleur par éspèce									*/

	flowerListNode *		m_iris;					/**< Liste des fleurs													*/

	node *					m_leftSon;				/**< Noeud fils gauche													*/
	node *					m_rightSon;				/**< Noeud fils droit													*/
};


list * CreateDataList(FILE * p_pfile, list * p_pflowerlist, int p_nbData);

void insererrFin(list * p_pflowerList, flower p_dataFlower);

flowerListNode * creerNoeudList(flower p_dataFlower);

int CountNbLignes(FILE * p_pfile);


#endif //_IRIS_H_
