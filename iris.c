#include "iris.h"
#include "entropy.h"


list * CreateDataList(FILE * p_pfile, list * p_pflowerList, int p_nbData)
{
	if (!p_pfile)
		exit(-1);

	fseek(p_pfile, 0L, SEEK_SET);

	for (int i = 0; i < p_nbData; i++)
	{
		flower tmp;
		fscanf(p_pfile, "%f,%f,%f,%f,", &tmp.m_sepalLength, &tmp.m_sepalWidth, &tmp.m_petalLength, &tmp.m_petalWidth);
		fscanf(p_pfile, "%s", tmp.m_specieNamed);
		printf("%f, %f, %f, %f, %s\n", tmp.m_sepalLength, tmp.m_sepalWidth, tmp.m_petalLength, tmp.m_petalWidth, tmp.m_specieNamed);
        
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
		exit(-1);

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


void afficherList(list * p_pflowerList)
{
	if (p_pflowerList == NULL)
		exit(-1);

	flowerListNode * pCourant = p_pflowerList->m_head;
	printf("\n\n Ma Liste de Fleur et leurs caractéristiques : \n");
	printf("Longueur Sepal | Largeur Sepal | Longueur Petal | Largeur Petal | Nom Espece \n");
		  
	while (pCourant != NULL)
	{
		printf("   %f    |    %f   |    %f    |    %f   | %s\n", pCourant->m_dataFlower.m_sepalLength, pCourant->m_dataFlower.m_sepalWidth, pCourant->m_dataFlower.m_petalLength, pCourant->m_dataFlower.m_petalWidth, pCourant->m_dataFlower.m_specieNamed);
		pCourant = pCourant->m_next;
	}
	printf("\n");
}


void NbFlowerBySpecies(treeNode * p_pflowerNode)
{

    if (p_pflowerNode == NULL || p_pflowerNode->m_irisList->m_head == NULL)
		exit(-1);
    
    flowerListNode * pCourant = p_pflowerNode->m_irisList->m_head;
    
    while (pCourant != NULL)
    {
        if (strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-setosa") == 0)
            p_pflowerNode->m_tabValue[0] += 1;
        else if (strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-virginica") == 0)
            p_pflowerNode->m_tabValue[1] += 1;
        else if (strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-versicolor") == 0)
            p_pflowerNode->m_tabValue[2] += 1;
        else
        {
            printf("Espece de fleur inconnu\n");
            exit(-1);
        }
        pCourant = pCourant->m_next;
    }
}

void InitialisationMinEtMax(treeNode * p_pflowerNode)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        p_pflowerNode->m_parameterTab[i].m_min = 100;
        p_pflowerNode->m_parameterTab[i].m_max = 0;
    }
    
    
    if (p_pflowerNode == NULL || p_pflowerNode->m_irisList->m_head == NULL)
		exit(-1);
    
    
    flowerListNode * pCourant = p_pflowerNode->m_irisList->m_head;
    
    
    while (pCourant != NULL)
    {
        if (pCourant->m_dataFlower.m_sepalLength < p_pflowerNode->m_parameterTab[0].m_min)
            p_pflowerNode->m_parameterTab[0].m_min = pCourant->m_dataFlower.m_sepalLength;
        if (pCourant->m_dataFlower.m_sepalWidth < p_pflowerNode->m_parameterTab[1].m_min)
            p_pflowerNode->m_parameterTab[1].m_min = pCourant->m_dataFlower.m_sepalWidth;
        if (pCourant->m_dataFlower.m_petalLength < p_pflowerNode->m_parameterTab[2].m_min)
            p_pflowerNode->m_parameterTab[2].m_min = pCourant->m_dataFlower.m_petalLength;
        if (pCourant->m_dataFlower.m_petalWidth < p_pflowerNode->m_parameterTab[3].m_min)
            p_pflowerNode->m_parameterTab[3].m_min = pCourant->m_dataFlower.m_petalWidth;
        
        if (pCourant->m_dataFlower.m_sepalLength > p_pflowerNode->m_parameterTab[0].m_max)
            p_pflowerNode->m_parameterTab[0].m_max = pCourant->m_dataFlower.m_sepalLength;
        if (pCourant->m_dataFlower.m_sepalWidth > p_pflowerNode->m_parameterTab[1].m_max)
            p_pflowerNode->m_parameterTab[1].m_max = pCourant->m_dataFlower.m_sepalWidth;
        if (pCourant->m_dataFlower.m_petalLength > p_pflowerNode->m_parameterTab[2].m_max)
            p_pflowerNode->m_parameterTab[2].m_max = pCourant->m_dataFlower.m_petalLength;
        if (pCourant->m_dataFlower.m_petalWidth > p_pflowerNode->m_parameterTab[3].m_max)
            p_pflowerNode->m_parameterTab[3].m_max = pCourant->m_dataFlower.m_petalWidth;
        
        pCourant = pCourant->m_next;
    }
}


float * ComparedSepalWidth(treeNode * p_pflowerNode)
{
    
    flowerListNode * pCourant = p_pflowerNode->m_irisList->m_head;
    float tab[3] = {0, 0, 0};
    
    
    int min = p_pflowerNode->m_parameterTab[1].m_min;
    int max = p_pflowerNode->m_parameterTab[1].m_max;
    for (int j = min ; j <= max ; j += 0.05)
    {
        while(pCourant != NULL)
        {
            if (pCourant->m_dataFlower.m_sepalWidth <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-setosa") == 0)
                tab[0] += tab[0];
            else if (pCourant->m_dataFlower.m_sepalWidth <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-versicolor") == 0)
                tab[1] += tab[1];
            else if (pCourant->m_dataFlower.m_sepalWidth <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-virginica") == 0)
                tab[2] += tab[2];
            else
                exit(-1);
            
            pCourant = pCourant->m_next;   
        }
    }
    return tab;
}

float ComparedPetalLength(treeNode * p_pflowerNode)
{
    if (p_pflowerNode == NULL || p_pflowerNode->m_irisList->m_head == NULL)
        exit(-1);
    
    flowerListNode * pCourant;
    float tab[3] = {0, 0, 0};
    float entropValue = 0;
    float entropValueInverse = 0;
    
    
    float min = p_pflowerNode->m_parameterTab[2].m_min;
    float max = p_pflowerNode->m_parameterTab[2].m_max;
    for (float j = min ; j < max+0.05 ; j += 0.05)
    {
        pCourant = p_pflowerNode->m_irisList->m_head;
        tab[0] = 0;
        tab[1] = 0;
        tab[2] = 0;
        while(pCourant != NULL)
        {
            if (pCourant->m_dataFlower.m_petalLength <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-setosa") == 0)
                tab[0] += 1;
            if (pCourant->m_dataFlower.m_petalLength <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-versicolor") == 0)
                tab[1] += 1;
            if (pCourant->m_dataFlower.m_petalLength <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-virginica") == 0)
                tab[2] += 1;
            
            pCourant = pCourant->m_next;
        }
    float nbFlowerInTab = tab[0] + tab[1] + tab[2];
    float tabInverse[3] = {p_pflowerNode->m_tabValue[0] - tab[0], p_pflowerNode->m_tabValue[1] - tab[1], p_pflowerNode->m_tabValue[2] - tab[2]};
    float nbFlowerInTabInverse = tabInverse[0] + tabInverse[1] + tabInverse[2];
    entropValue = entropy(tab, nbFlowerInTab);
    entropValueInverse = entropy(tabInverse, nbFlowerInTabInverse);
    printf("%f   %f   %f\n", tab[0], tab[1], tab[2]);
    printf("nb fleur dans tab1 : %f\n", nbFlowerInTab);
    printf("nb fleur dans tabInverse1 : %f\n", nbFlowerInTabInverse);
    printf("val entropi1 : %f\n", entropValue);
    printf("val entropinverse1 :%f\n\n", entropValueInverse);
    }
    return entropValue;
}

float * ComparedPetalWidth(treeNode * p_pflowerNode)
{
    
    flowerListNode * pCourant = p_pflowerNode->m_irisList->m_head;
    float tab[3] = {0, 0, 0};    
    
    int min = p_pflowerNode->m_parameterTab[3].m_min;
    int max = p_pflowerNode->m_parameterTab[3].m_max;
    for (int j = min ; j <= max ; j += 0.05)
    {
        while(pCourant != NULL)
        {
            if (pCourant->m_dataFlower.m_petalWidth <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-setosa") == 0)
                tab[0] += tab[0];
            else if (pCourant->m_dataFlower.m_petalWidth <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-versicolor") == 0)
                tab[1] += tab[1];
            else if (pCourant->m_dataFlower.m_petalWidth <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-virginica") == 0)
                tab[2] += tab[2];
            else
                exit(-1);
            
            pCourant = pCourant->m_next;
        }
    }
    return tab;
}

float ComparedSepalLength(treeNode * p_pflowerNode)
{
    if (p_pflowerNode == NULL || p_pflowerNode->m_irisList->m_head == NULL)
        exit(-1);
    
    p_pflowerNode->m_valueCompared = 0;
    
    flowerListNode * pCourant;
    float tab[3] = {0, 0, 0};
    float entropValue = 0;
    float entropValueInverse = 0;
    float entropTot = 0;
    
    float min = p_pflowerNode->m_parameterTab[0].m_min;
    float max = p_pflowerNode->m_parameterTab[0].m_max;
    for (float j = min ; j < max+0.05 ; j += 0.05)
    {
        pCourant = p_pflowerNode->m_irisList->m_head;
        tab[0] = 0;
        tab[1] = 0;
        tab[2] = 0;
        while(pCourant != NULL)
        {
            if (pCourant->m_dataFlower.m_sepalLength <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-setosa") == 0)
                tab[0] += 1;
            if (pCourant->m_dataFlower.m_sepalLength <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-versicolor") == 0)
                tab[1] += 1;
            if (pCourant->m_dataFlower.m_sepalLength <= j && strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-virginica") == 0)
                tab[2] += 1;
            
            pCourant = pCourant->m_next;
        }
        
    float nbFlowerInTab = tab[0] + tab[1] + tab[2];
    float tabInverse[3] = {p_pflowerNode->m_tabValue[0] - tab[0], p_pflowerNode->m_tabValue[1] - tab[1], p_pflowerNode->m_tabValue[2] - tab[2]};
    float nbFlowerInTabInverse = tabInverse[0] + tabInverse[1] + tabInverse[2];
    
    entropValue = entropy(tab, nbFlowerInTab);
    entropValueInverse = entropy(tabInverse, nbFlowerInTabInverse);
    entropTot = entropValue + entropValueInverse;
    
    bestEntropy(p_pflowerNode, 0, entropTot, j);
                
                
    printf("%f   %f   %f\n", tab[0], tab[1], tab[2]);
    printf("nb fleur dans tab : %f\n", nbFlowerInTab);
    printf("nb fleur dans tabInverse : %f\n", nbFlowerInTabInverse);
    printf("val entropi : %f\n", entropValue);
    printf("val entropinverse :%f\n\n", entropValueInverse);
    }
    
    printf("
    return entropValue;
}


void bestEntropy(treeNode * p_pflowerNode, int pParameterCompared, float pEntropValue, float pValueCompared)
{
    if(p_pflowerNode->m_entropy > pEntropValue)
    {
        p_pflowerNode->m_entropy = pEntropValue;
        p_pflowerNode->m_valueCompared = pValueCompared;
        p_pflowerNode->m_paramCompared = pParameterCompared;
    }    
}


/*treeNode * CreateNode(treeNode * p_pflowerNode)
{
    p_pflowerNode * pSon = 
    
    
}*/

