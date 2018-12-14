#include "iris.h"

/*
list * CreateDataList(FILE * p_pfile, list * p_pflowerList, int p_nbData)
{
	if (!p_pfile)
		return	EXIT_FAILURE;

	int c;

	fseek(p_pfile, 0L, SEEK_SET);

	for (int i = 0; i < p_nbData; i++)
	{
		flower tmp;
		fscanf_s(p_pfile, "%f,%f,%f,%f,", &tmp.m_sepalWidth, &tmp.m_sepalLength, &tmp.m_petalWidth, &tmp.m_petalLength);
		fscanf_s(p_pfile, "%s", tmp.m_specieNamed, _countof(tmp.m_specieNamed));
		printf("%f, %f, %f, %f, %s", tmp.m_sepalWidth, tmp.m_sepalLength, tmp.m_petalWidth, tmp.m_petalLength, tmp.m_specieNamed);

		inserrerFin(p_pflowerList, tmp);

		// On passe � la ligne suivante
		c = fgetc(p_pfile);
	}

	return p_pflowerList;
}

void insererrFin(list * p_pflowerList, flower p_dataFlower)
{
	flowerListNode * pNouveau = creerNoeudListe(p_dataFlower);

	if (p_pflowerList->m_head == NULL)
	{
		p_pflowerList->m_head = pNouveau;
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
*/

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

	/* Ici, c2 est �gal au caract�re juste avant le EOF. */
	if (c2 != '\n')
		nbLignes++; /* Derni�re ligne non finie */

	return nbLignes;
}

