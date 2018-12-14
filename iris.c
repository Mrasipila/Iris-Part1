#include "iris.h"


list * CreateDataList(FILE * p_pfile, list * p_pflowerList, int p_nbData)
{
	if (!p_pfile)
		return EXIT_FAILURE;

	fseek(p_pfile, 0L, SEEK_SET);

	for (int i = 0; i < p_nbData; i++)
	{
		flower tmp;
		fscanf_s(p_pfile, "%f,%f,%f,%f,", &tmp.m_sepalWidth, &tmp.m_sepalLength, &tmp.m_petalWidth, &tmp.m_petalLength);
		fscanf_s(p_pfile, "%s", tmp.m_specieNamed, _countof(tmp.m_specieNamed));
		printf("%f, %f, %f, %f, %s\n", tmp.m_sepalWidth, tmp.m_sepalLength, tmp.m_petalWidth, tmp.m_petalLength, tmp.m_specieNamed);

		insererFin(p_pflowerList, tmp);
	}


return p_pflowerList;
}

void insererFin(list * p_pflowerList, flower p_dataFlower)
{
	flowerListNode * pNouveau = creerNoeudList(p_dataFlower);

	if (p_pflowerList->m_head == NULL)
	{
		p_pflowerList->m_head = pNouveau;
		return EXIT_FAILURE;
	}
	else
	{
		flowerListNode * pCourant = p_pflowerList->m_head;

		while (pCourant->m_next != NULL)
		pCourant = pCourant->m_next;

		pCourant->m_next = pNouveau;
	}
}

flowerListNode * creerNoeudList(flower p_dataFlower)
{
	flowerListNode * pNouveau = (flowerListNode*)calloc(1, sizeof(flowerListNode));

	if (pNouveau == NULL)
		return EXIT_FAILURE;

	pNouveau->m_dataFlower = p_dataFlower;
	pNouveau->m_next = NULL;

	return pNouveau;
}


int CountNbLignes(FILE * p_pfile)
{
	int c;
	int nbLignes = 0;
	int c2 = '\0';

	while ((c = fgetc(p_pfile)) != EOF)
	{
		if (c == '\n')
			nbLignes++;
		c2 = c;
	}

	/* Ici, c2 est égal au caractère juste avant le EOF. */
	if (c2 != '\n')
		nbLignes++; /* Dernière ligne non finie */

	return nbLignes;
}

void afficherList(list * p_pHead)
{
	if (p_pHead == NULL)
	{
		return EXIT_FAILURE;
	}

	flowerListNode * pCourant = p_pHead->m_head;
	printf("\n\n Ma Liste de Fleur et leurs caractéristiques : \n");
	printf("Longueur Sepal | Largeur Sepal | Longueur Petal | Largeur Petal | Nom Espece \n");
		  
	while (pCourant->m_next != NULL)
	{
		printf("   %f    |    %f   |    %f    |    %f   | %s\n", pCourant->m_dataFlower.m_sepalWidth, pCourant->m_dataFlower.m_sepalLength, pCourant->m_dataFlower.m_petalWidth, pCourant->m_dataFlower.m_petalLength, pCourant->m_dataFlower.m_specieNamed);
		pCourant = pCourant->m_next;
	}
	printf("\n");
}

